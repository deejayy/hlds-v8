#include <extdll.h>
#include <meta_api.h>
#include <cbase.h>
#include <player.h>
#include <usercmd.h>

#include <v8.h>

#include "common.h"

using namespace v8;

Isolate* isolate = Isolate::GetCurrent();
HandleScope handle_scope(isolate);
Handle<Context> context;

static void jsWindowObjectAccessor(Local<String> property, const PropertyCallbackInfo<Value>& info) {
	info.GetReturnValue().Set(info.Holder());
}

static void jsConsolePrint(const v8::FunctionCallbackInfo<Value> &args) {
	for (int i=0; i < args.Length(); i++) {
		String::Utf8Value str(args[i]->ToString());
		ALERT(at_logged, "%s", *str);
	}

	SERVER_PRINT("\n");
	args.GetReturnValue().Set(Null(isolate));
}


// very first callback, runs twice: before and after logswitch
const char *v8_GetGameDescription () {
	SET_META_RESULT(MRES_IGNORED);
	return "v8 gamedesc";
}

// second callback
void v8_GameInit () {
	Handle<ObjectTemplate> globalObject = ObjectTemplate::New();
	Handle<ObjectTemplate> console      = ObjectTemplate::New();

	globalObject->SetAccessor(String::NewFromUtf8(isolate, "window" ), jsWindowObjectAccessor);
	globalObject->Set        (String::NewFromUtf8(isolate, "console"), console);
	console     ->Set        (String::NewFromUtf8(isolate, "log"    ), FunctionTemplate::New(isolate, jsConsolePrint));

	context = Context::New(isolate, NULL, globalObject);
	Context::Scope context_scope(context);

	char* scriptSource = fileReader("/home/cstrike/inst/debug/cstrike/plugins/hldsv8/scripts/test.js");

	if (scriptSource != NULL) {
		Handle<String> source = String::NewFromUtf8(isolate, scriptSource);
		Handle<Script> script = Script::Compile(source);
		Handle<Value>  result = script->Run();
		String::Utf8Value utf8(result);

		ALERT(at_logged, "[HLDSV8] Engine Started. (%s)\n", *utf8);
	} else {
		ALERT(at_logged, "[HLDSV8] Engine failed to start, no script\n");
	}

	SET_META_RESULT(MRES_IGNORED);
}

// third callback
void v8_PM_Init (struct playermove_s *ppmove) {
	SET_META_RESULT(MRES_IGNORED);
}

// 4th callback
void v8_RegisterEncoders () {
	SET_META_RESULT(MRES_IGNORED);
}

// 5th callback, run 4 times in batch
int v8_GetHullBounds (int hullnumber, float *mins, float *maxs) {
	SET_META_RESULT(MRES_IGNORED);
}

// 6th callback
void v8_ResetGlobalState () {
	SET_META_RESULT(MRES_IGNORED);
}

// very frequent at startup (400), first callback after logswitch, nothing is initialized
void v8_KeyValue (edict_t *pentKeyvalue, KeyValueData *pkvd) {
	SET_META_RESULT(MRES_IGNORED);
}

// very frequent at startup (400), second callback after logswitch, nothing is initialized
int v8_Spawn (edict_t *pent) {
	SET_META_RESULT(MRES_IGNORED);
	return 1;
}

// frequent at startup (50), very frequent in-game (v8_StartFrame * 4!) third callback after logswitch, nothing is initialized
void v8_SetAbsBox (edict_t *pent) {
	SET_META_RESULT(MRES_IGNORED);
}

// fourth callback after logswitch
void v8_ServerActivate (edict_t *pEdictList, int edictCount, int clientMax) {
	SET_META_RESULT(MRES_HANDLED);
}

// batch run at startup, about 80 times, end with: v8_CreateInstancedBaselines
void v8_CreateBaseline (int player, int eindex, struct entity_state_s *baseline, struct edict_s *entity, int playermodelindex, vec3_t player_mins, vec3_t player_maxs) {
	SET_META_RESULT(MRES_IGNORED);
}

// baseline creation last step
void v8_CreateInstancedBaselines () {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (4-5 / sec)
void v8_Think (edict_t *pent) {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent if player is not spectator
void v8_Touch (edict_t *pentTouched, edict_t *pentOther) {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (100)
void v8_PlayerPreThink (edict_t *pEntity) {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (100)
void v8_PlayerPostThink (edict_t *pEntity) {
	SET_META_RESULT(MRES_IGNORED);
}

// very frequent in-game (~ fps ?)
void v8_StartFrame () {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (100)
void v8_PM_Move (struct playermove_s *ppmove, qboolean server) {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (100)
void v8_SetupVisibility (struct edict_s *pViewEntity, struct edict_s *pClient, unsigned char **pvs, unsigned char **pas) {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (250)
void v8_UpdateClientData (const struct edict_s *ent, int sendweapons, struct clientdata_s *cd) {
	SET_META_RESULT(MRES_IGNORED);
}

// very frequent in-game (12000)
int v8_AddToFullPack (struct entity_state_s *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, unsigned char *pSet) {
	SET_META_RESULT(MRES_IGNORED);
	return 1;
}

// frequent in-game (250)
int v8_GetWeaponData (struct edict_s *player, struct weapon_data_s *info) {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (100)
void v8_CmdStart (const edict_t *player, const struct usercmd_s *cmd, unsigned int random_seed) {
	Context::Scope context_scope(context);

	Handle<String>   myName = String::NewFromUtf8(isolate, "CmdStart");
	Handle<Function> fn     = Handle<Function>::Cast(context->Global()->Get(myName));

	if (fn->GetName()->ToString()->Equals(myName)) {
		Handle<Object> params = Object::New(isolate);

		entvars_t *pev = (entvars_t *)&player->v;
		CBasePlayer *pl = (CBasePlayer*)CBasePlayer::Instance(pev);
		usercmd_t *command = (usercmd_t *)cmd;

		Handle<Object> viewangles = Object::New(isolate);
		viewangles->Set(String::NewFromUtf8(isolate, "x"), Number::New(isolate, command->viewangles[0]));
		viewangles->Set(String::NewFromUtf8(isolate, "y"), Number::New(isolate, command->viewangles[1]));
		viewangles->Set(String::NewFromUtf8(isolate, "z"), Number::New(isolate, command->viewangles[2]));

		Handle<Object> impact_position = Object::New(isolate);
		impact_position->Set(String::NewFromUtf8(isolate, "x"), Number::New(isolate, command->impact_position[0]));
		impact_position->Set(String::NewFromUtf8(isolate, "y"), Number::New(isolate, command->impact_position[1]));
		impact_position->Set(String::NewFromUtf8(isolate, "z"), Number::New(isolate, command->impact_position[2]));

		Handle<Object> buttons = Object::New(isolate);
		buttons->Set(String::NewFromUtf8(isolate, "attack"    ), Number::New(isolate, command->buttons & IN_ATTACK));
		buttons->Set(String::NewFromUtf8(isolate, "jump"      ), Number::New(isolate, command->buttons & IN_JUMP));
		buttons->Set(String::NewFromUtf8(isolate, "duck"      ), Number::New(isolate, command->buttons & IN_DUCK));
		buttons->Set(String::NewFromUtf8(isolate, "forward"   ), Number::New(isolate, command->buttons & IN_FORWARD));
		buttons->Set(String::NewFromUtf8(isolate, "back"      ), Number::New(isolate, command->buttons & IN_BACK));
		buttons->Set(String::NewFromUtf8(isolate, "use"       ), Number::New(isolate, command->buttons & IN_USE));
		buttons->Set(String::NewFromUtf8(isolate, "cancel"    ), Number::New(isolate, command->buttons & IN_CANCEL));
		buttons->Set(String::NewFromUtf8(isolate, "left"      ), Number::New(isolate, command->buttons & IN_LEFT));
		buttons->Set(String::NewFromUtf8(isolate, "right"     ), Number::New(isolate, command->buttons & IN_RIGHT));
		buttons->Set(String::NewFromUtf8(isolate, "moveleft"  ), Number::New(isolate, command->buttons & IN_MOVELEFT));
		buttons->Set(String::NewFromUtf8(isolate, "moveright" ), Number::New(isolate, command->buttons & IN_MOVERIGHT));
		buttons->Set(String::NewFromUtf8(isolate, "attack2"   ), Number::New(isolate, command->buttons & IN_ATTACK2));
		buttons->Set(String::NewFromUtf8(isolate, "run"       ), Number::New(isolate, command->buttons & IN_RUN));
		buttons->Set(String::NewFromUtf8(isolate, "reload"    ), Number::New(isolate, command->buttons & IN_RELOAD));
		buttons->Set(String::NewFromUtf8(isolate, "alt1"      ), Number::New(isolate, command->buttons & IN_ALT1));
		buttons->Set(String::NewFromUtf8(isolate, "score"     ), Number::New(isolate, command->buttons & IN_SCORE));

		params->Set(String::NewFromUtf8(isolate, "lerp_msec"       ), Number::New(isolate, command->lerp_msec));      // Interpolation time on client
		params->Set(String::NewFromUtf8(isolate, "msec"            ), Number::New(isolate, command->msec));           // Duration in ms of command
		params->Set(String::NewFromUtf8(isolate, "viewangles"      ), viewangles);                                    // Command view angles.
		params->Set(String::NewFromUtf8(isolate, "forwardmove"     ), Number::New(isolate, command->forwardmove));    // Forward velocity.
		params->Set(String::NewFromUtf8(isolate, "sidemove"        ), Number::New(isolate, command->sidemove));       // Sideways velocity.
		params->Set(String::NewFromUtf8(isolate, "upmove"          ), Number::New(isolate, command->upmove));         // Upward velocity.
		params->Set(String::NewFromUtf8(isolate, "lightlevel"      ), Number::New(isolate, command->lightlevel));     // Light level at spot where we are standing.
		params->Set(String::NewFromUtf8(isolate, "buttons"         ), buttons);                                       // Attack buttons
		params->Set(String::NewFromUtf8(isolate, "impulse"         ), Number::New(isolate, command->impulse));        // Impulse command issued.
		params->Set(String::NewFromUtf8(isolate, "weaponselect"    ), Number::New(isolate, command->weaponselect));   // Current weapon id
		params->Set(String::NewFromUtf8(isolate, "impact_index"    ), Number::New(isolate, command->impact_index));   // experimental
		params->Set(String::NewFromUtf8(isolate, "impact_position" ), impact_position);                               // experimental

		const int      fnArgc = 1;
		Handle<Value>  fnArgs[fnArgc]  = { params };

		Handle<Value>  result  = fn->Call(context->Global(), fnArgc, fnArgs);
	} else {
		ALERT(at_logged, "[HLDSV8] No CmdStart defined in script!\n");
	}

	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (100)
void v8_CmdEnd (const edict_t *player) {
	SET_META_RESULT(MRES_IGNORED);
}

// frequent in-game (200)
int v8_AllowLagCompensation () {
	SET_META_RESULT(MRES_IGNORED);
}

void v8_Use (edict_t *pentUsed, edict_t *pentOther) {
	ALERT(at_logged, "v8_Use\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_Blocked (edict_t *pentBlocked, edict_t *pentOther) {
	ALERT(at_logged, "v8_Blocked\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_Save (edict_t *pent, SAVERESTOREDATA *pSaveData) {
	ALERT(at_logged, "v8_Save\n");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_Restore (edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity) {
	ALERT(at_logged, "v8_Restore\n");
	SET_META_RESULT(MRES_IGNORED);
	return 1;
}

void v8_SaveWriteFields (SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int) {
	ALERT(at_logged, "v8_SaveWriteFields\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_SaveReadFields (SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int) {
	ALERT(at_logged, "v8_SaveReadFields\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_SaveGlobalState (SAVERESTOREDATA *) {
	ALERT(at_logged, "v8_SaveGlobalState\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_RestoreGlobalState (SAVERESTOREDATA *) {
	ALERT(at_logged, "v8_RestoreGlobalState\n");
	SET_META_RESULT(MRES_IGNORED);
}

qboolean v8_ClientConnect (edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[ 128 ]) {
	Context::Scope context_scope(context);

	Handle<String>   myName = String::NewFromUtf8(isolate, "ClientConnect");
	Handle<Function> fn     = Handle<Function>::Cast(context->Global()->Get(myName));

	if (fn->GetName()->ToString()->Equals(myName)) {
		Handle<Object> params = Object::New(isolate);
		params->Set(String::NewFromUtf8(isolate, "name"   ), String::NewFromUtf8(isolate, pszName));
		params->Set(String::NewFromUtf8(isolate, "address"), String::NewFromUtf8(isolate, pszAddress));
		params->Set(String::NewFromUtf8(isolate, "authid" ), String::NewFromUtf8(isolate, g_engfuncs.pfnGetPlayerAuthId(pEntity)));
		params->Set(String::NewFromUtf8(isolate, "keys"   ), String::NewFromUtf8(isolate, g_engfuncs.pfnGetInfoKeyBuffer(pEntity)));
		params->Set(String::NewFromUtf8(isolate, "uid"    ), Number::New(isolate, g_engfuncs.pfnGetPlayerUserId(pEntity)));
		params->Set(String::NewFromUtf8(isolate, "wonid"  ), Number::New(isolate, g_engfuncs.pfnGetPlayerWONId(pEntity)));

		const int      fnArgc = 1;
		Handle<Value>  fnArgs[fnArgc]  = { params };

		Handle<Value>  result  = fn->Call(context->Global(), fnArgc, fnArgs);
	} else {
		ALERT(at_logged, "[HLDSV8] No ClientConnect defined in script!\n");
	}

	SET_META_RESULT(MRES_IGNORED);
}

void v8_ClientDisconnect (edict_t *pEntity) {
	ALERT(at_logged, "v8_ClientDisconnect\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ClientKill (edict_t *pEntity) {
	ALERT(at_logged, "v8_ClientKill\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ClientPutInServer (edict_t *pEntity) {
	ALERT(at_logged, "v8_ClientPutInServer\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ClientCommand (edict_t *pEntity) {
	ALERT(at_logged, "v8_ClientCommand\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ClientUserInfoChanged (edict_t *pEntity, char *infobuffer) {
	ALERT(at_logged, "v8_ClientUserInfoChanged\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ParmsNewLevel () {
	ALERT(at_logged, "v8_ParmsNewLevel\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ParmsChangeLevel () {
	ALERT(at_logged, "v8_ParmsChangeLevel\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_PlayerCustomization (edict_t *pEntity, customization_t *pCustom) {
	ALERT(at_logged, "v8_PlayerCustomization\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_SpectatorConnect (edict_t *pEntity) {
	ALERT(at_logged, "v8_SpectatorConnect\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_SpectatorDisconnect (edict_t *pEntity) {
	ALERT(at_logged, "v8_SpectatorDisconnect\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_SpectatorThink (edict_t *pEntity) {
	ALERT(at_logged, "v8_SpectatorThink\n");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_Sys_Error (const char *error_string) {
	ALERT(at_logged, "v8_Sys_Error\n");
	SET_META_RESULT(MRES_IGNORED);
}

char v8_PM_FindTextureType (char *name) {
	ALERT(at_logged, "v8_PM_FindTextureType\n");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_ConnectionlessPacket (const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size) {
	ALERT(at_logged, "v8_ConnectionlessPacket\n");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_InconsistentFile (const struct edict_s *player, const char *filename, char *disconnect_message) {
	ALERT(at_logged, "v8_InconsistentFile\n");
	SET_META_RESULT(MRES_IGNORED);
}

// last callback, suitable for finalization
void v8_ServerDeactivate () {
	SET_META_RESULT(MRES_IGNORED);
}

