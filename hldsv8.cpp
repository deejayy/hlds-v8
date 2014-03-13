#include <extdll.h>
#include <meta_api.h>
#include <cbase.h>
#include <player.h>
#include <usercmd.h>

#include <v8.h>

#include "common.h"
#include "hldsv8_common.h"
#include "hldsv8_shared.h"

// #define v8debug

using namespace v8;

Isolate* isolate = Isolate::GetCurrent();
HandleScope handle_scope(isolate);
Handle<Context> context;

/**
 * Client list, maxplayers + 1
 */
edict_t *entities[33];

int maxPlayers;
int maxEntities;

/**
 * Callback define status
 * int d<callback function basename>: CB_*
 */
typedef struct {
	int dClientConnect;
	int dClientCommand;
	int dCmdStart;
	int dGameInit;
	int dServerActivate;
	int dServerDeactivate;
	int dPlayerPreThink;
	int dThink;
	int dPlayerPostThink;
	int dTouch;
	int dStartFrame;
	int dCmdEnd;
	int dClientDisconnect;
	int dClientKill;
	int dClientPutInServer;
	int dSpectatorConnect;
	int dSpectatorDisconnect;
	int dSpectatorThink;
	int dClientUserInfoChanged;
} cbDefines_t;

static cbDefines_t cbDefines = { };

/**
 * First callback before the world has spawned, and the game rules initialized
 * Should return the game description (default: Half-Life)
 *
 * @return const char *
 */
const char *v8_GetGameDescription () {
	SET_META_RESULT(MRES_OVERRIDE);
	return "Counter Strike";
}

/**
 * Game init, suitable for v8 initialization, and used for it
 *
 * @return void
 */
void v8_GameInit () {
	jsInitialize();

	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	cbDefines.dGameInit              = v8c_CheckCallbackIsDefined("GameInit");
	cbDefines.dServerActivate        = v8c_CheckCallbackIsDefined("ServerActivate");
	cbDefines.dClientConnect         = v8c_CheckCallbackIsDefined("ClientConnect");
	cbDefines.dCmdStart              = v8c_CheckCallbackIsDefined("CmdStart");
	cbDefines.dClientCommand         = v8c_CheckCallbackIsDefined("ClientCommand");
	cbDefines.dServerDeactivate      = v8c_CheckCallbackIsDefined("ServerDeactivate");
	cbDefines.dPlayerPreThink        = v8c_CheckCallbackIsDefined("PlayerPreThink");
	cbDefines.dThink                 = v8c_CheckCallbackIsDefined("Think");
	cbDefines.dPlayerPostThink       = v8c_CheckCallbackIsDefined("PlayerPostThink");
	cbDefines.dTouch                 = v8c_CheckCallbackIsDefined("Touch");
	cbDefines.dStartFrame            = v8c_CheckCallbackIsDefined("StartFrame");
	cbDefines.dCmdEnd                = v8c_CheckCallbackIsDefined("CmdEnd");
	cbDefines.dClientDisconnect      = v8c_CheckCallbackIsDefined("ClientDisconnect");
	cbDefines.dClientKill            = v8c_CheckCallbackIsDefined("ClientKill");
	cbDefines.dClientPutInServer     = v8c_CheckCallbackIsDefined("ClientPutInServer");
	cbDefines.dSpectatorConnect      = v8c_CheckCallbackIsDefined("SpectatorConnect");
	cbDefines.dSpectatorDisconnect   = v8c_CheckCallbackIsDefined("SpectatorDisconnect");
	cbDefines.dSpectatorThink        = v8c_CheckCallbackIsDefined("SpectatorThink");
	cbDefines.dClientUserInfoChanged = v8c_CheckCallbackIsDefined("ClientUserInfoChanged");

	if (cbDefines.dGameInit == CB_DEFINED) {
		Handle<Object> params = Object::New(isolate);
		MRES = v8c_UCallback("GameInit", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * Server activate
 *
 * @param edict_t pEdictList entity list
 * @param int     edictCount max entities
 * @param int     clientMax  max clients
 *
 * @return void
 */
void v8_ServerActivate (edict_t *pEdictList, int edictCount, int clientMax) {
	maxEntities = edictCount;
	maxPlayers = clientMax;

	SET_META_RESULT(cbDefines.dServerActivate == CB_DEFINED ? v8c_UCallback("ServerActivate") : MRES_IGNORED);
}

/**
 * A client connects to the server
 *
 * @param edict_t   pEntity        client
 * @param char*     pszName        player network name
 * @param char*     pszAddress     player network address (ip:port)
 * @param char[128] szRejectReason reject reason
 *
 * @return qboolean
 */
qboolean v8_ClientConnect (edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[ 128 ]) {
	entities[ENTINDEX(pEntity)] = pEntity;
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dClientConnect == CB_DEFINED) {
		Handle<Object> params = Object::New(isolate);
		params->Set(String::NewFromUtf8(isolate, "id"     ), Number::New(isolate, ENTINDEX(pEntity)));
		params->Set(String::NewFromUtf8(isolate, "name"   ), String::NewFromUtf8(isolate, pszName));
		params->Set(String::NewFromUtf8(isolate, "address"), String::NewFromUtf8(isolate, pszAddress));

		MRES = v8c_UCallback("ClientConnect", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * Command start
 *
 * @param edict_t   player      player
 * @param usercmd_s cmd         command structure
 * @param int       random_seed ?
 *
 * @return void
 */
void v8_CmdStart (const edict_t *player, const struct usercmd_s *cmd, unsigned int random_seed) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dCmdStart == CB_DEFINED) {
		Handle<Object> params = Object::New(isolate);

		usercmd_t *command = (usercmd_t *)cmd;

		params->Set(String::NewFromUtf8(isolate, "id"              ), Number::New(isolate, ENTINDEX(player)));
		params->Set(String::NewFromUtf8(isolate, "lerp_msec"       ), Number::New(isolate, command->lerp_msec));      // Interpolation time on client
		params->Set(String::NewFromUtf8(isolate, "msec"            ), Number::New(isolate, command->msec));           // Duration in ms of command
		params->Set(String::NewFromUtf8(isolate, "viewangles"      ), v8c_Vec3tToObject(command->viewangles));        // Command view angles.
		params->Set(String::NewFromUtf8(isolate, "forwardmove"     ), Number::New(isolate, command->forwardmove));    // Forward velocity.
		params->Set(String::NewFromUtf8(isolate, "sidemove"        ), Number::New(isolate, command->sidemove));       // Sideways velocity.
		params->Set(String::NewFromUtf8(isolate, "upmove"          ), Number::New(isolate, command->upmove));         // Upward velocity.
		params->Set(String::NewFromUtf8(isolate, "lightlevel"      ), Number::New(isolate, command->lightlevel));     // Light level at spot where we are standing.
		params->Set(String::NewFromUtf8(isolate, "buttons"         ), Number::New(isolate, command->buttons));        // Attack buttons
		params->Set(String::NewFromUtf8(isolate, "impulse"         ), Number::New(isolate, command->impulse));        // Impulse command issued.
		params->Set(String::NewFromUtf8(isolate, "weaponselect"    ), Number::New(isolate, command->weaponselect));   // Current weapon id
		params->Set(String::NewFromUtf8(isolate, "impact_index"    ), Number::New(isolate, command->impact_index));   // experimental
		params->Set(String::NewFromUtf8(isolate, "impact_position" ), v8c_Vec3tToObject(command->impact_position));   // experimental

		MRES = v8c_UCallback("CmdStart", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * A client issues a command
 *
 * @param edict_t pEntity
 *
 * @return void
 */
void v8_ClientCommand (edict_t *pEntity) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dClientCommand == CB_DEFINED) {
		Handle<Object> params = Object::New(isolate);
		params->Set(String::NewFromUtf8(isolate, "id"), Number::New(isolate, ENTINDEX(pEntity)));

		int argc = g_engfuncs.pfnCmd_Argc();
		Handle<Array> argv = Array::New(isolate, argc);
		if (argc > 1) {
			params->Set(String::NewFromUtf8(isolate, "args"), String::NewFromUtf8(isolate, g_engfuncs.pfnCmd_Args()));
		}
		for (int i = 0; i < argc; i++) {
			argv->Set(i, String::NewFromUtf8(isolate, g_engfuncs.pfnCmd_Argv(i)));
		}
		params->Set(String::NewFromUtf8(isolate, "argv"), argv);

		MRES = v8c_UCallback("ClientCommand", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * Server deactivate
 */
void v8_ServerDeactivate () {
	SET_META_RESULT(cbDefines.dServerDeactivate == CB_DEFINED ? v8c_UCallback("ServerDeactivate") : MRES_IGNORED);
}

/**
 * Player pre-think
 *
 * @param edict_t pEntity player
 *
 * @return void
 */
void v8_PlayerPreThink (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dPlayerPreThink == CB_DEFINED ? v8c_UCallback("PlayerPreThink", ENTINDEX(pEntity)) : MRES_IGNORED);
}

/**
 * Entity think event (4-5 times / sec)
 *
 * @param edict_t pEntity
 *
 * @return void
 */
void v8_Think (edict_t *pEntity) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dThink == CB_DEFINED) {
		Handle<Object> params = Object::New(isolate);

		CBaseEntity *entity = (CBaseEntity *)GET_PRIVATE(pEntity);
		params->Set(String::NewFromUtf8(isolate, "id"), Number::New(isolate, ENTINDEX(pEntity)));
		if (entity) {
			params->Set(String::NewFromUtf8(isolate, "classname"), String::NewFromUtf8(isolate, STRING(entity->pev->classname)));
		}

		MRES = v8c_UCallback("Think", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * Player post-think
 *
 * @param edict_t pEntity
 *
 * @return void
 */
void v8_PlayerPostThink (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dPlayerPostThink == CB_DEFINED ? v8c_UCallback("PlayerPostThink", ENTINDEX(pEntity)) : MRES_IGNORED);
}

/**
 * Entity touch another entity (entity in game)
 *
 * @param edict_t pentTouched touched entity
 * @param edict_t pentOther   other entity
 *
 * @return void
 */
void v8_Touch (edict_t *pentTouched, edict_t *pentOther) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dTouch == CB_DEFINED) {
		Handle<Object> params = Object::New(isolate);

		params->Set(String::NewFromUtf8(isolate, "id"), Number::New(isolate, ENTINDEX(pentTouched)));
		params->Set(String::NewFromUtf8(isolate, "id2"), Number::New(isolate, ENTINDEX(pentOther)));

		MRES = v8c_UCallback("Touch", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * Startframe
 *
 * @return void
 */
void v8_StartFrame () {
	SET_META_RESULT(cbDefines.dStartFrame == CB_DEFINED ? v8c_UCallback("StartFrame") : MRES_IGNORED);
}

void v8_CmdEnd (const edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dCmdEnd == CB_DEFINED ? v8c_UCallback("CmdEnd", ENTINDEX(pEntity)) : MRES_IGNORED);
}

void v8_ClientDisconnect (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dClientDisconnect == CB_DEFINED ? v8c_UCallback("ClientDisconnect", ENTINDEX(pEntity)) : MRES_IGNORED);
}

void v8_ClientKill (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dClientKill == CB_DEFINED ? v8c_UCallback("ClientKill", ENTINDEX(pEntity)) : MRES_IGNORED);
}

void v8_ClientPutInServer (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dClientPutInServer == CB_DEFINED ? v8c_UCallback("ClientPutInServer", ENTINDEX(pEntity)) : MRES_IGNORED);
}

void v8_SpectatorConnect (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dSpectatorConnect == CB_DEFINED ? v8c_UCallback("SpectatorConnect", ENTINDEX(pEntity)) : MRES_IGNORED);
}

void v8_SpectatorDisconnect (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dSpectatorDisconnect == CB_DEFINED ? v8c_UCallback("SpectatorDisconnect", ENTINDEX(pEntity)) : MRES_IGNORED);
}

void v8_SpectatorThink (edict_t *pEntity) {
	SET_META_RESULT(cbDefines.dSpectatorThink == CB_DEFINED ? v8c_UCallback("SpectatorThink", ENTINDEX(pEntity)) : MRES_IGNORED);
}

/**
 * Called after the player changes userinfo - gives dll a chance to modify it before it gets sent into the rest of the engine.
 *
 * @param edict_t pEntity    entity
 * @param char*   infobuffer info key buffer string (\key\value...)
 *
 * @return void
 */
void v8_ClientUserInfoChanged (edict_t *pEntity, char *infobuffer) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dClientUserInfoChanged == CB_DEFINED) {
		Handle<Object> params = Object::New(isolate);

		params->Set(String::NewFromUtf8(isolate, "id"), Number::New(isolate, ENTINDEX(pEntity)));
		params->Set(String::NewFromUtf8(isolate, "infobuffer"), String::NewFromUtf8(isolate, infobuffer));

		MRES = v8c_UCallback("ClientUserInfoChanged", params);
	}

	SET_META_RESULT(MRES);
}

/* ================================================================== */
/* =================== U N I M P L E M E N T E D ==================== */
/* ================================================================== */

/**
 * UNIMPLEMENTED: PlayerMove Init
 *
 * @params playermove_s ppmove
 *
 * @return void
 */
void v8_PM_Init (struct playermove_s *ppmove) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Register network encoders
 *
 * @return void
 */
void v8_RegisterEncoders () {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Engine calls this to enumerate player collision hulls, for prediction.  Return 0 if the hullnumber doesn't exist.
 *
 * @return int
 */
int v8_GetHullBounds (int hullnumber, float *mins, float *maxs) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Resets the global gamestate
 *
 * @return void
 */
void v8_ResetGlobalState () {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: First batch of callbacks after the world has spawned, provides a tree-structure with key-value items
 * Eg. worldspawn env_*, func_*, info_*, light*, infodecal, trigger_*
 * Hint: pkvd->(szClassName|szKeyName|szValue)
 */
void v8_KeyValue (edict_t *pentKeyvalue, KeyValueData *pkvd) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Don't know, probably spawning worldspawn items
 *
 * @return int
 */
int v8_Spawn (edict_t *pent) {
	SET_META_RESULT(MRES_IGNORED);
	return 1;
}

/**
 * UNIMPLEMENTED: Adjust collision boxes for hits, etc
 *
 * @param edict_t pent pointer to an entity
 *
 * @return void
 */
void v8_SetAbsBox (edict_t *pent) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Create baseline (80 times at startup)
 * Creates baselines used for network encoding, especially for player data since players are not spawned until connect time.
 *
 * @param int            player           player
 * @param int            eindex           entity index
 * @param entity_state_s baseline         entity state
 * @param edict_s        entity           entity
 * @param int            playermodelindex player model index
 * @param vec3_t         player_mins
 * @param vec3_t         player_maxs
 *
 * @return void
 */
void v8_CreateBaseline (int player, int eindex, struct entity_state_s *baseline, struct edict_s *entity, int playermodelindex, vec3_t player_mins, vec3_t player_maxs) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Baseline creation last step
 *
 * @return void
 */
void v8_CreateInstancedBaselines () {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Too frequent to use for anything
 * Determine whether we should send this entity to all clients (eg. spectators, model-less entities (etc...): no)
 */
int v8_AddToFullPack (struct entity_state_s *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, unsigned char *pSet) {
	SET_META_RESULT(MRES_IGNORED);
	return 1;
}

/**
 * UNIMPLEMENTED: Set up visible entities by the client (per frame)
 */
void v8_SetupVisibility (struct edict_s *pViewEntity, struct edict_s *pClient, unsigned char **pvs, unsigned char **pas) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Data sent to current client only engine sets cd to 0 before calling
 */
void v8_UpdateClientData (const struct edict_s *ent, int sendweapons, struct clientdata_s *cd) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Probably not used
 */
int v8_GetWeaponData (struct edict_s *player, struct weapon_data_s *info) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED: Return 1 if lag compensation should be allowed
 */
int v8_AllowLagCompensation () {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_PM_Move (struct playermove_s *ppmove, qboolean server) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_Use (edict_t *pentUsed, edict_t *pentOther) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_Blocked (edict_t *pentBlocked, edict_t *pentOther) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_Save (edict_t *pent, SAVERESTOREDATA *pSaveData) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
int v8_Restore (edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity) {
	SET_META_RESULT(MRES_IGNORED);
	return 1;
}

/**
 * UNIMPLEMENTED
 */
void v8_SaveWriteFields (SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_SaveReadFields (SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_SaveGlobalState (SAVERESTOREDATA *) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_RestoreGlobalState (SAVERESTOREDATA *) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_ParmsNewLevel () {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_ParmsChangeLevel () {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_PlayerCustomization (edict_t *pEntity, customization_t *pCustom) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
void v8_Sys_Error (const char *error_string) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
char v8_PM_FindTextureType (char *name) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
int v8_ConnectionlessPacket (const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * UNIMPLEMENTED
 */
int v8_InconsistentFile (const struct edict_s *player, const char *filename, char *disconnect_message) {
	SET_META_RESULT(MRES_IGNORED);
}

