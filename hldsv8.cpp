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

int v8_ModelFrames (int modelIndex) {
	ALERT(at_logged, "[V8E] %s\n", "ModelFrames");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_GetSpawnParms (edict_t *ent) {
	ALERT(at_logged, "[V8E] %s\n", "GetSpawnParms");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_SaveSpawnParms (edict_t *ent) {
	ALERT(at_logged, "[V8E] %s\n", "SaveSpawnParms");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_MoveToOrigin (edict_t *ent, const float *pflGoal, float dist, int iMoveType) {
	ALERT(at_logged, "[V8E] %s\n", "MoveToOrigin");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ChangeYaw (edict_t* ent) {
	ALERT(at_logged, "[V8E] %s\n", "ChangeYaw");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ChangePitch (edict_t* ent) {
	ALERT(at_logged, "[V8E] %s\n", "ChangePitch");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_GetEntityIllum (edict_t* pEnt) {
	ALERT(at_logged, "[V8E] %s\n", "GetEntityIllum");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_AngleVectors (const float *rgflVector, float *forward, float *right, float *up) {
	ALERT(at_logged, "[V8E] %s\n", "AngleVectors");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_MakeStatic (edict_t *ent) {
	ALERT(at_logged, "[V8E] %s\n", "MakeStatic");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_EntIsOnFloor (edict_t *e) {
	ALERT(at_logged, "[V8E] %s\n", "EntIsOnFloor");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

int v8_WalkMove (edict_t *ent, float yaw, float dist, int iMode) {
	ALERT(at_logged, "[V8E] %s\n", "WalkMove");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_EmitAmbientSound (edict_t *entity, float *pos, const char *samp, float vol, float attenuation, int fFlags, int pitch) {
	ALERT(at_logged, "[V8E] %s\n", "EmitAmbientSound");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_TraceToss (edict_t* pent, edict_t* pentToIgnore, TraceResult *ptr) {
	ALERT(at_logged, "[V8E] %s\n", "TraceToss");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_TraceMonsterHull (edict_t *pEdict, const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr) {
	ALERT(at_logged, "[V8E] %s\n", "TraceMonsterHull");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_TraceModel (const float *v1, const float *v2, int hullNumber, edict_t *pent, TraceResult *ptr) {
	ALERT(at_logged, "[V8E] %s\n", "TraceModel");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_TraceSphere (const float *v1, const float *v2, int fNoMonsters, float radius, edict_t *pentToSkip, TraceResult *ptr) {
	ALERT(at_logged, "[V8E] %s\n", "TraceSphere");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_GetAimVector (edict_t* ent, float speed, float *rgflReturn) {
	ALERT(at_logged, "[V8E] %s\n", "GetAimVector");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ClientCommand (edict_t* pEdict, char* szFmt, ...) {
	ALERT(at_logged, "[V8E] %s\n", "ClientCommand");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ParticleEffect (const float *org, const float *dir, float color, float count) {
	ALERT(at_logged, "[V8E] %s\n", "ParticleEffect");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_PointContents (const float *rgflVector) {
	ALERT(at_logged, "[V8E] %s\n", "PointContents");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_EngineFprintf (void *pfile, char *szFmt, ...) {
	ALERT(at_logged, "[V8E] %s\n", "EngineFprintf");
	SET_META_RESULT(MRES_IGNORED);
}

const char* v8_SzFromIndex (int iString) {
	ALERT(at_logged, "[V8E] %s\n", "SzFromIndex");
	SET_META_RESULT(MRES_IGNORED);
}

struct entvars_s* v8_GetVarsOfEnt (edict_t *pEdict) {
	ALERT(at_logged, "[V8E] %s\n", "GetVarsOfEnt");
	SET_META_RESULT(MRES_IGNORED);
}

edict_t* v8_FindEntityByVars (struct entvars_s* pvars) {
	ALERT(at_logged, "[V8E] %s\n", "FindEntityByVars");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_AnimationAutomove (const edict_t* pEdict, float flTime) {
	ALERT(at_logged, "[V8E] %s\n", "AnimationAutomove");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_GetBonePosition (const edict_t* pEdict, int iBone, float *rgflOrigin, float *rgflAngles) {
	ALERT(at_logged, "[V8E] %s\n", "GetBonePosition");
	SET_META_RESULT(MRES_IGNORED);
}

uint32 v8_FunctionFromName (const char *pName) {
	ALERT(at_logged, "[V8E] %s\n", "FunctionFromName");
	SET_META_RESULT(MRES_IGNORED);
}

const char * v8_NameForFunction (uint32 function) {
	ALERT(at_logged, "[V8E] %s\n", "NameForFunction");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ClientPrintf (edict_t* pEdict, PRINT_TYPE ptype, const char *szMsg) {
	ALERT(at_logged, "[V8E] %s\n", "ClientPrintf");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ServerPrint (const char *szMsg) {
	ALERT(at_logged, "[V8E] %s\n", "ServerPrint");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_GetAttachment (const edict_t *pEdict, int iAttachment, float *rgflOrigin, float *rgflAngles) {
	ALERT(at_logged, "[V8E] %s\n", "GetAttachment");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_CRC32_Init (CRC32_t *pulCRC) {
	ALERT(at_logged, "[V8E] %s\n", "CRC32_Init");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_CRC32_ProcessBuffer (CRC32_t *pulCRC, void *p, int len) {
	ALERT(at_logged, "[V8E] %s\n", "CRC32_ProcessBuffer");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_CRC32_ProcessByte (CRC32_t *pulCRC, unsigned char ch) {
	ALERT(at_logged, "[V8E] %s\n", "CRC32_ProcessByte");
	SET_META_RESULT(MRES_IGNORED);
}

CRC32_t v8_CRC32_Final (CRC32_t pulCRC) {
	ALERT(at_logged, "[V8E] %s\n", "CRC32_Final");
	SET_META_RESULT(MRES_IGNORED);
}

float v8_Time (void) {
	ALERT(at_logged, "[V8E] %s\n", "Time");
	SET_META_RESULT(MRES_IGNORED);
	return 0.0;
}

void v8_CrosshairAngle (const edict_t *pClient, float pitch, float yaw) {
	ALERT(at_logged, "[V8E] %s\n", "CrosshairAngle");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_EndSection (const char *pszSectionName) {
	ALERT(at_logged, "[V8E] %s\n", "EndSection");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_CompareFileTime (char *filename1, char *filename2, int *iCompare) {
	ALERT(at_logged, "[V8E] %s\n", "CompareFileTime");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_Cvar_RegisterVariable (cvar_t *variable) {
	ALERT(at_logged, "[V8E] %s\n", "Cvar_RegisterVariable");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_FadeClientVolume (const edict_t *pEdict, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds) {
	ALERT(at_logged, "[V8E] %s\n", "FadeClientVolume");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_SetClientMaxspeed (const edict_t *pEdict, float fNewMaxspeed) {
	ALERT(at_logged, "[V8E] %s\n", "SetClientMaxspeed");
	SET_META_RESULT(MRES_IGNORED);
}

edict_t * v8_CreateFakeClient (const char *netname) {
	ALERT(at_logged, "[V8E] %s\n", "CreateFakeClient");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_RunPlayerMove (edict_t *fakeclient, const float *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, byte impulse, byte msec) {
	ALERT(at_logged, "[V8E] %s\n", "RunPlayerMove");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_NumberOfEntities (void) {
	ALERT(at_logged, "[V8E] %s\n", "NumberOfEntities");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

int v8_IsMapValid (char *filename) {
	ALERT(at_logged, "[V8E] %s\n", "IsMapValid");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_BuildSoundMsg (edict_t *entity, int channel, const char *sample, /*int*/float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, edict_t *ed) {
	ALERT(at_logged, "[V8E] %s\n", "BuildSoundMsg");
	SET_META_RESULT(MRES_IGNORED);
}

unsigned int v8_GetPlayerWONId (edict_t *e) {
	ALERT(at_logged, "[V8E] %s\n", "GetPlayerWONId");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_SetGroupMask (int mask, int op) {
	ALERT(at_logged, "[V8E] %s\n", "SetGroupMask");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_CreateInstancedBaseline (int classname, struct entity_state_s *baseline) {
	ALERT(at_logged, "[V8E] %s\n", "CreateInstancedBaseline");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_Cvar_DirectSet (struct cvar_s *var, char *value) {
	ALERT(at_logged, "[V8E] %s\n", "Cvar_DirectSet");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_GetPlayerStats (const edict_t *pClient, int *ping, int *packet_loss) {
	ALERT(at_logged, "[V8E] %s\n", "GetPlayerStats");
	SET_META_RESULT(MRES_IGNORED);
}

qboolean v8_Voice_GetClientListening (int iReceiver, int iSender) {
	ALERT(at_logged, "[V8E] %s\n", "Voice_GetClientListening");
	SET_META_RESULT(MRES_IGNORED);
}

sequenceEntry_s* v8_SequenceGet (const char* fileName, const char* entryName) {
	ALERT(at_logged, "[V8E] %s\n", "SequenceGet");
	SET_META_RESULT(MRES_IGNORED);
}

sentenceEntry_s* v8_SequencePickSentence (const char* groupName, int pickMethod, int *picked) {
	ALERT(at_logged, "[V8E] %s\n", "SequencePickSentence");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_GetFileSize (char *filename) {
	ALERT(at_logged, "[V8E] %s\n", "GetFileSize");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

unsigned int v8_GetApproxWavePlayLen (const char *filepath) {
	ALERT(at_logged, "[V8E] %s\n", "GetApproxWavePlayLen");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

int v8_GetLocalizedStringLength (const char *label) {
	ALERT(at_logged, "[V8E] %s\n", "GetLocalizedStringLength");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_RegisterTutorMessageShown (int mid) {
	ALERT(at_logged, "[V8E] %s\n", "RegisterTutorMessageShown");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_GetTimesTutorMessageShown (int mid) {
	ALERT(at_logged, "[V8E] %s\n", "GetTimesTutorMessageShown");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

void v8_ProcessTutorMessageDecayBuffer (int *buffer, int bufferLength) {
	ALERT(at_logged, "[V8E] %s\n", "ProcessTutorMessageDecayBuffer");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ConstructTutorMessageDecayBuffer (int *buffer, int bufferLength) {
	ALERT(at_logged, "[V8E] %s\n", "ConstructTutorMessageDecayBuffer");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_ResetTutorMessageDecayData (void) {
	ALERT(at_logged, "[V8E] %s\n", "ResetTutorMessageDecayData");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_QueryClientCvarValue (const edict_t *player, const char *cvarName) {
	ALERT(at_logged, "[V8E] %s\n", "QueryClientCvarValue");
	SET_META_RESULT(MRES_IGNORED);
}

void v8_QueryClientCvarValue2 (const edict_t *player, const char *cvarName, int requestID) {
	ALERT(at_logged, "[V8E] %s\n", "QueryClientCvarValue2");
	SET_META_RESULT(MRES_IGNORED);
}

int v8_EngCheckParm (const char *pchCmdLineToken, char **pchNextVal) {
	ALERT(at_logged, "[V8E] %s\n", "EngCheckParm");
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

/**
 * Fired @ knifing
 */
void v8_TraceHull (const float *v1, const float *v2, int fNoMonsters, int hullNumber, edict_t *pentToSkip, TraceResult *ptr) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_SetView (const edict_t *pClient, const edict_t *pViewent) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
int v8_DropToFloor (edict_t* e) {
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

/**
 *
 */
const char * v8_TraceTexture (edict_t *pTextureEntity, const float *v1, const float *v2) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_SetOrigin (edict_t *e, const float *rgflOrigin) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 * Fired @ crouching
 */
void v8_SetSize (edict_t *e, const float *rgflMin, const float *rgflMax) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
float v8_VecToYaw (const float *rgflVector) {
	SET_META_RESULT(MRES_IGNORED);
	return 0.0;
}

/**
 *
 */
void v8_VecToAngles (const float *rgflVectorIn, float *rgflVectorOut) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
char* v8_GetInfoKeyBuffer (edict_t *e) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_ChangeLevel (char* s1, char* s2) {
	ALERT(at_logged, "[V8E] %s\n", "ChangeLevel");
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_StaticDecal (const float *origin, int decalIndex, int entityIndex, int modelIndex) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_SetModel (edict_t *e, const char *m) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_LightStyle (int style, char* val) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
int v8_DecalIndex (const char *name) {
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

/**
 *
 */
edict_t* v8_CreateEntity (void) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_RemoveEntity (edict_t* e) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
edict_t* v8_CreateNamedEntity (int className) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_TraceLine (const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
int v8_CanSkipPlayer (const edict_t *player) {
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

/**
 *
 */
void v8_FreeFile (void *buffer) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
void v8_ServerExecute (void) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
edict_t* v8_FindEntityInSphere (edict_t *pEdictStartSearchAfter, const float *org, float rad) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
edict_t* v8_FindClientInPVS (edict_t *pEdict) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
edict_t* v8_EntitiesInPVS (edict_t *pplayer) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
int v8_IsDedicatedServer (void) {
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}

/**
 *
 */
void v8_GetGameDir (char *szGetGameDir) {
	SET_META_RESULT(MRES_IGNORED);
}

/**
 *
 */
int v8_ModelIndex (const char *m) {
	SET_META_RESULT(MRES_IGNORED);
	return 0;
}


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
	int dCVarRegister;
	int dCVarGetFloat;
	int dCVarGetString;
	int dCVarSetFloat;
	int dCVarSetString;
	int dCVarGetPointer;
	int dAlertMessage;
	int dAllocString;
	int dServerCommand;
	int dRegUserMsg;
	int dLoadFileForMe;
	int dAddServerCommand;
	int dInfoKeyValue;
	int dSetKeyValue;
	int dSetClientKeyValue;
	int dInfo_RemoveKey;
	int dGetPhysicsKeyValue;
	int dSetPhysicsKeyValue;
	int dGetPlayerAuthId;
	int dGetPlayerUserId;
	int dFindEntityByString;
	int dPlaybackEvent;
	int dEmitSound;
	int dMessageBegin;
	int dMessageEnd;
	int dWriteByte;
	int dWriteChar;
	int dWriteShort;
	int dWriteLong;
	int dWriteAngle;
	int dWriteCoord;
	int dWriteString;
	int dWriteEntity;
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

	/*
	  ==========================


	void *handle = dlopen("/home/cstrike/inst/debug/cstrike/dlls/cs.so", RTLD_NOW|RTLD_GLOBAL);
	void *addr = dlsym(handle, "_ZN11CBasePlayer10TakeDamageEP9entvars_sS1_fi");

	if (addr != NULL) {
		ALERT(at_logged, "dlsym: %p\n", addr);
	} else {
		ALERT(at_logged, "dlsym returned null\n");
	}


	  ==========================
	*/

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
	cbDefines.dCVarRegister          = v8c_CheckCallbackIsDefined("CVarRegister");
	cbDefines.dCVarGetFloat          = v8c_CheckCallbackIsDefined("CVarGetFloat");
	cbDefines.dCVarGetString         = v8c_CheckCallbackIsDefined("CVarGetString");
	cbDefines.dCVarSetFloat          = v8c_CheckCallbackIsDefined("CVarSetFloat");
	cbDefines.dCVarSetString         = v8c_CheckCallbackIsDefined("CVarSetString");
	cbDefines.dCVarGetPointer        = v8c_CheckCallbackIsDefined("CVarGetPointer");
	cbDefines.dAlertMessage          = v8c_CheckCallbackIsDefined("AlertMessage");
	cbDefines.dAllocString           = v8c_CheckCallbackIsDefined("AllocString");
	cbDefines.dServerCommand         = v8c_CheckCallbackIsDefined("ServerCommand");
	cbDefines.dRegUserMsg            = v8c_CheckCallbackIsDefined("RegUserMsg");
	cbDefines.dLoadFileForMe         = v8c_CheckCallbackIsDefined("LoadFileForMe");
	cbDefines.dAddServerCommand      = v8c_CheckCallbackIsDefined("AddServerCommand");
	cbDefines.dInfoKeyValue          = v8c_CheckCallbackIsDefined("InfoKeyValue");
	cbDefines.dSetKeyValue           = v8c_CheckCallbackIsDefined("SetKeyValue");
	cbDefines.dSetClientKeyValue     = v8c_CheckCallbackIsDefined("SetClientKeyValue");
	cbDefines.dInfo_RemoveKey        = v8c_CheckCallbackIsDefined("Info_RemoveKey");
	cbDefines.dGetPhysicsKeyValue    = v8c_CheckCallbackIsDefined("GetPhysicsKeyValue");
	cbDefines.dSetPhysicsKeyValue    = v8c_CheckCallbackIsDefined("SetPhysicsKeyValue");
	cbDefines.dGetPlayerAuthId       = v8c_CheckCallbackIsDefined("GetPlayerAuthId");
	cbDefines.dGetPlayerUserId       = v8c_CheckCallbackIsDefined("GetPlayerUserId");
	cbDefines.dFindEntityByString    = v8c_CheckCallbackIsDefined("FindEntityByString");
	cbDefines.dPlaybackEvent         = v8c_CheckCallbackIsDefined("PlaybackEvent");
	cbDefines.dEmitSound             = v8c_CheckCallbackIsDefined("EmitSound");
	cbDefines.dMessageBegin          = v8c_CheckCallbackIsDefined("MessageBegin");
	cbDefines.dMessageEnd            = v8c_CheckCallbackIsDefined("MessageEnd");
	cbDefines.dWriteByte             = v8c_CheckCallbackIsDefined("WriteByte");
	cbDefines.dWriteChar             = v8c_CheckCallbackIsDefined("WriteChar");
	cbDefines.dWriteShort            = v8c_CheckCallbackIsDefined("WriteShort");
	cbDefines.dWriteLong             = v8c_CheckCallbackIsDefined("WriteLong");
	cbDefines.dWriteAngle            = v8c_CheckCallbackIsDefined("WriteAngle");
	cbDefines.dWriteCoord            = v8c_CheckCallbackIsDefined("WriteCoord");
	cbDefines.dWriteString           = v8c_CheckCallbackIsDefined("WriteString");
	cbDefines.dWriteEntity           = v8c_CheckCallbackIsDefined("WriteEntity");

	if (cbDefines.dGameInit == CB_DEFINED) {
		Handle<Object> params = V8OBJ();
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
		Handle<Object> params = V8OBJ();
		params->Set(V8STR("id"     ), V8NUM(ENTINDEX(pEntity)));
		params->Set(V8STR("name"   ), V8STR(pszName));
		params->Set(V8STR("address"), V8STR(pszAddress));

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
		Handle<Object> params = V8OBJ();

		usercmd_t *command = (usercmd_t *)cmd;

		params->Set(V8STR("id"              ), V8NUM(ENTINDEX(player)));
		params->Set(V8STR("lerp_msec"       ), V8NUM(command->lerp_msec));      // Interpolation time on client
		params->Set(V8STR("msec"            ), V8NUM(command->msec));           // Duration in ms of command
		params->Set(V8STR("viewangles"      ), v8c_Vec3tToObject(command->viewangles));        // Command view angles.
		params->Set(V8STR("forwardmove"     ), V8NUM(command->forwardmove));    // Forward velocity.
		params->Set(V8STR("sidemove"        ), V8NUM(command->sidemove));       // Sideways velocity.
		params->Set(V8STR("upmove"          ), V8NUM(command->upmove));         // Upward velocity.
		params->Set(V8STR("lightlevel"      ), V8NUM(command->lightlevel));     // Light level at spot where we are standing.
		params->Set(V8STR("buttons"         ), V8NUM(command->buttons));        // Attack buttons
		params->Set(V8STR("impulse"         ), V8NUM(command->impulse));        // Impulse command issued.
		params->Set(V8STR("weaponselect"    ), V8NUM(command->weaponselect));   // Current weapon id
		params->Set(V8STR("impact_index"    ), V8NUM(command->impact_index));   // experimental
		params->Set(V8STR("impact_position" ), v8c_Vec3tToObject(command->impact_position));   // experimental

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
		Handle<Object> params = V8OBJ();
		params->Set(V8STR("id"), V8NUM(ENTINDEX(pEntity)));

		int argc = g_engfuncs.pfnCmd_Argc();
		Handle<Array> argv = Array::New(isolate, argc);
		if (argc > 1) {
			params->Set(V8STR("args"), V8STR(g_engfuncs.pfnCmd_Args()));
		}
		for (int i = 0; i < argc; i++) {
			argv->Set(i, V8STR(g_engfuncs.pfnCmd_Argv(i)));
		}
		params->Set(V8STR("argv"), argv);

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
		Handle<Object> params = V8OBJ();

		CBaseEntity *entity = (CBaseEntity *)GET_PRIVATE(pEntity);
		params->Set(V8STR("id"), V8NUM(ENTINDEX(pEntity)));
		if (entity) {
			params->Set(V8STR("classname"), V8STR(STRING(entity->pev->classname)));
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
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"), V8NUM(ENTINDEX(pentTouched)));
		params->Set(V8STR("id2"), V8NUM(ENTINDEX(pentOther)));

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
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"), V8NUM(ENTINDEX(pEntity)));
		params->Set(V8STR("infobuffer"), V8STR(infobuffer));

		MRES = v8c_UCallback("ClientUserInfoChanged", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * hlsdk-2.3-p4/multiplayer/common/cvardef.h
 */
void v8_CVarRegister (cvar_t *pCvar) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dCVarRegister == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("name"  ), V8STR(pCvar->name));
		params->Set(V8STR("string"), V8STR(pCvar->string));
		params->Set(V8STR("flags" ), V8NUM(pCvar->flags));
		params->Set(V8STR("value" ), V8NUM(pCvar->value));

		MRES = v8c_UCallback("CVarRegister", params);
	}

	SET_META_RESULT(MRES);
}

float v8_CVarGetFloat (const char *szVarName) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dCVarGetFloat == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("varName"), V8STR(szVarName));

		MRES = v8c_UCallback("CVarGetFloat", params);
	}

	SET_META_RESULT(MRES);
	return 0.0;
}

const char* v8_CVarGetString (const char *szVarName) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dCVarGetString == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("varName"), V8STR(szVarName));

		MRES = v8c_UCallback("CVarGetString", params);
	}

	SET_META_RESULT(MRES);
}

void v8_CVarSetFloat (const char *szVarName, float flValue) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dCVarSetFloat == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("varName"), V8STR(szVarName));
		params->Set(V8STR("value"), V8NUM(flValue));

		MRES = v8c_UCallback("CVarSetFloat", params);
	}

	SET_META_RESULT(MRES);
}

void v8_CVarSetString (const char *szVarName, const char *szValue) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dCVarSetString == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("varName"), V8STR(szVarName));
		params->Set(V8STR("value"), V8STR(szValue));

		MRES = v8c_UCallback("CVarSetString", params);
	}

	SET_META_RESULT(MRES);
}

cvar_t  * v8_CVarGetPointer (const char *szVarName) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dCVarGetPointer == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("varName"), V8STR(szVarName));

		MRES = v8c_UCallback("CVarGetPointer", params);
	}

	SET_META_RESULT(MRES);
}

void v8_AlertMessage (ALERT_TYPE atype, char *szFmt, ...) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dAlertMessage == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		va_list			argptr;
		static char		string[1024];

		va_start (argptr, szFmt);
		vsnprintf(string, sizeof(string), szFmt, argptr);
		va_end   (argptr);

		params->Set(V8STR("string"), V8STR(string));
		params->Set(V8STR("atype"), V8NUM(int(atype)));

		MRES = v8c_UCallback("AlertMessage", params);
	}

	SET_META_RESULT(MRES);
}

/**
 *
 */
int v8_AllocString (const char *szValue) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dAllocString == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("value"), V8STR(szValue));

		MRES = v8c_UCallback("AllocString", params);
	}

	SET_META_RESULT(MRES);
	return 0;
}

/**
 *
 */
void v8_ServerCommand (char* str) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dServerCommand == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("str"), V8STR(str));

		MRES = v8c_UCallback("ServerCommand", params);
	}

	SET_META_RESULT(MRES);
}

/**
 *
 */
int v8_RegUserMsg (const char *pszName, int iSize) {
	SET_META_RESULT(MRES_IGNORED);
	int ret = 0;

	Context::Scope context_scope(context);

	if (cbDefines.dRegUserMsg == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("name"), V8STR(pszName));
		params->Set(V8STR("size"), V8NUM(iSize));

		ret = v8c_UCallbackReturn("RegUserMsg", params)->ToInt32()->Value();
	}

	return ret;
}

/**
 *
 */
byte * v8_LoadFileForMe (char *filename, int *pLength) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dLoadFileForMe == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("filename"), V8STR(filename));

		MRES = v8c_UCallback("LoadFileForMe", params);
	}

	SET_META_RESULT(MRES);
	return 0;
}

void v8_AddServerCommand (char *cmd_name, void (*function) (void)) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dAddServerCommand == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("cmd_name"), V8STR(cmd_name));

		MRES = v8c_UCallback("AddServerCommand", params);
	}

	SET_META_RESULT(MRES);
}

char* v8_InfoKeyValue (char *infobuffer, char *key) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dInfoKeyValue == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("infobuffer"), V8STR(infobuffer));
		params->Set(V8STR("key"), V8STR(key));

		MRES = v8c_UCallback("InfoKeyValue", params);
	}

	SET_META_RESULT(MRES);
}

void v8_SetKeyValue (char *infobuffer, char *key, char *value) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dSetKeyValue == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("infobuffer"), V8STR(infobuffer));
		params->Set(V8STR("key"), V8STR(key));
		params->Set(V8STR("value"), V8STR(value));

		MRES = v8c_UCallback("SetKeyValue", params);
	}

	SET_META_RESULT(MRES);
}

void v8_SetClientKeyValue (int clientIndex, char *infobuffer, char *key, char *value) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dSetClientKeyValue == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("index"), V8NUM(clientIndex));
		params->Set(V8STR("infobuffer"), V8STR(infobuffer));
		params->Set(V8STR("key"), V8STR(key));
		params->Set(V8STR("value"), V8STR(value));

		MRES = v8c_UCallback("SetClientKeyValue", params);
	}

	SET_META_RESULT(MRES);
}

void v8_Info_RemoveKey (char *s, const char *key) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dInfo_RemoveKey == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("s"), V8STR(s));
		params->Set(V8STR("key"), V8STR(key));

		MRES = v8c_UCallback("Info_RemoveKey", params);
	}

	SET_META_RESULT(MRES);
}

const char * v8_GetPhysicsKeyValue (const edict_t *pClient, const char *key) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dGetPhysicsKeyValue == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"), V8NUM(ENTINDEX(pClient)));
		params->Set(V8STR("key"), V8STR(key));

		MRES = v8c_UCallback("GetPhysicsKeyValue", params);
	}

	SET_META_RESULT(MRES);
}

void v8_SetPhysicsKeyValue (const edict_t *pClient, const char *key, const char *value) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dSetPhysicsKeyValue == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"), V8NUM(ENTINDEX(pClient)));
		params->Set(V8STR("key"), V8STR(key));
		params->Set(V8STR("value"), V8STR(value));

		MRES = v8c_UCallback("SetPhysicsKeyValue", params);
	}

	SET_META_RESULT(MRES);
}

const char * v8_GetPlayerAuthId (edict_t *e) {
	SET_META_RESULT(cbDefines.dGetPlayerAuthId == CB_DEFINED ? v8c_UCallback("GetPlayerAuthId", ENTINDEX(e)) : MRES_IGNORED);
}

int v8_GetPlayerUserId (edict_t *e) {
	SET_META_RESULT(cbDefines.dGetPlayerUserId == CB_DEFINED ? v8c_UCallback("GetPlayerUserId", ENTINDEX(e)) : MRES_IGNORED);
}

edict_t* v8_FindEntityByString (edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dFindEntityByString == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"), V8NUM(ENTINDEX(pEdictStartSearchAfter)));
		params->Set(V8STR("field"), V8STR(pszField));
		params->Set(V8STR("value"), V8STR(pszValue));

		MRES = v8c_UCallback("FindEntityByString", params);
	}

	SET_META_RESULT(MRES);
}

void v8_EmitSound (edict_t *entity, int channel, const char *sample, /*int*/float volume, float attenuation, int fFlags, int pitch) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dEmitSound == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"         ), V8NUM(ENTINDEX(entity)));
		params->Set(V8STR("channel"    ), V8NUM(channel));
		params->Set(V8STR("sample"     ), V8STR(sample));
		params->Set(V8STR("volume"     ), V8NUM(volume));
		params->Set(V8STR("attenuation"), V8NUM(attenuation));
		params->Set(V8STR("fFlags"     ), V8NUM(fFlags));
		params->Set(V8STR("pitch"      ), V8NUM(pitch));

		MRES = v8c_UCallback("EmitSound", params);
	}

	SET_META_RESULT(MRES);
}

void v8_PlaybackEvent (int flags, const edict_t *pInvoker, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dPlaybackEvent == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"         ), V8NUM(ENTINDEX(pInvoker)));
		params->Set(V8STR("flags"      ), V8NUM(flags));
		params->Set(V8STR("eventindex" ), V8NUM(eventindex));
		params->Set(V8STR("delay"      ), V8NUM(delay));
		params->Set(V8STR("fparam1"    ), V8NUM(fparam1));
		params->Set(V8STR("fparam2"    ), V8NUM(fparam2));
		params->Set(V8STR("iparam1"    ), V8NUM(iparam1));
		params->Set(V8STR("iparam2"    ), V8NUM(iparam2));
		params->Set(V8STR("bparam1"    ), V8NUM(bparam1));
		params->Set(V8STR("bparam2"    ), V8NUM(bparam2));

		MRES = v8c_UCallback("PlaybackEvent", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * Start a message buffer
 */
void v8_MessageBegin (int msg_dest, int msg_type, const float *pOrigin, edict_t *ed) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dMessageBegin == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("id"      ), V8NUM(ENTINDEX(ed)));
		params->Set(V8STR("msg_dest"), V8NUM(msg_dest));
		params->Set(V8STR("msg_type"), V8NUM(msg_type));

		MRES = v8c_UCallback("MessageBegin", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * End a message buffer
 */
void v8_MessageEnd (void) {
	SET_META_RESULT(cbDefines.dMessageEnd == CB_DEFINED ? v8c_UCallback("MessageEnd") : MRES_IGNORED);
}

/**
 * Write data to client buffer
 */
void v8_WriteByte (int iValue) {
	SET_META_RESULT(cbDefines.dWriteByte == CB_DEFINED ? v8c_UCallback("WriteByte", iValue) : MRES_IGNORED);
}

/**
 * Write data to client buffer
 */
void v8_WriteChar (int iValue) {
	SET_META_RESULT(cbDefines.dWriteChar == CB_DEFINED ? v8c_UCallback("WriteChar", iValue) : MRES_IGNORED);
}

/**
 * Write data to client buffer
 */
void v8_WriteShort (int iValue) {
	SET_META_RESULT(cbDefines.dWriteShort == CB_DEFINED ? v8c_UCallback("WriteShort", iValue) : MRES_IGNORED);
}

/**
 * Write data to client buffer
 */
void v8_WriteLong (int iValue) {
	SET_META_RESULT(cbDefines.dWriteLong == CB_DEFINED ? v8c_UCallback("WriteLong", iValue) : MRES_IGNORED);
}

/**
 * Write data to client buffer
 */
void v8_WriteAngle (float flValue) {
	SET_META_RESULT(cbDefines.dWriteAngle == CB_DEFINED ? v8c_UCallback("WriteAngle", flValue) : MRES_IGNORED);
}

/**
 * Write data to client buffer
 */
void v8_WriteCoord (float flValue) {
	SET_META_RESULT(cbDefines.dWriteCoord == CB_DEFINED ? v8c_UCallback("WriteCoord", flValue) : MRES_IGNORED);
}

/**
 * Write data to client buffer
 */
void v8_WriteString (const char *sz) {
	META_RES MRES = MRES_IGNORED;

	Context::Scope context_scope(context);

	if (cbDefines.dWriteString == CB_DEFINED) {
		Handle<Object> params = V8OBJ();

		params->Set(V8STR("sz"     ), V8STR(sz));

		MRES = v8c_UCallback("WriteString", params);
	}

	SET_META_RESULT(MRES);
}

/**
 * Write data to client buffer
 */
void v8_WriteEntity (int iValue) {
	SET_META_RESULT(cbDefines.dWriteEntity == CB_DEFINED ? v8c_UCallback("WriteEntity", iValue) : MRES_IGNORED);
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

	/**
	 * UNIMPLEMENTED: Please no.
	 */
	int v8_EntOffsetOfPEntity (const edict_t *pEdict) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	/**
	 * UNIMPLEMENTED: Please no.
	 */
	int v8_IndexOfEdict (const edict_t *pEdict) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	/**
	 * UNIMPLEMENTED: Please no.
	 */
	edict_t* v8_PEntityOfEntIndex (int iEntIndex) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED: Please no.
	 */
	int32 v8_RandomLong (int32  lLow,  int32  lHigh) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED: Please no.
	 */
	int v8_CheckVisibility (const edict_t *entity, unsigned char *pset) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	/**
	 * UNIMPLEMENTED: Please no
	 */
	int v8_IsCareerMatch (void) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	/**
	 * UNIMPLEMENTED
	 */
	void v8_DeltaUnsetFieldByIndex (struct delta_s *pFields, int fieldNumber) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED
	 */
	void* v8_GetModelPtr (edict_t* pEdict) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED
	 */
	int v8_GetCurrentPlayer (void) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	/**
	 * UNIMPLEMENTED
	 */
	qboolean v8_Voice_SetClientListening (int iReceiver, int iSender, qboolean bListen) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED
	 */
	const char * v8_GetPhysicsInfoString (const edict_t *pClient) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED
	 */
	void v8_MakeVectors (const float *rgflVector) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED
	 */
	unsigned char * v8_SetFatPVS (float *org) {
		SET_META_RESULT(MRES_IGNORED);
	}

	/**
	 * UNIMPLEMENTED
	 */
	unsigned char * v8_SetFatPAS (float *org) {
		SET_META_RESULT(MRES_IGNORED);
	}

	int v8_PrecacheModel (char* s) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	int v8_PrecacheSound (char* s) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	void v8_ForceUnmodified (FORCE_TYPE type, float *mins, float *maxs, const char *filename) {
		SET_META_RESULT(MRES_IGNORED);
	}

	void* v8_PvAllocEntPrivateData (edict_t *pEdict, int32 cb) {
		SET_META_RESULT(MRES_IGNORED);
	}

	void* v8_PvEntPrivateData (edict_t *pEdict) {
		SET_META_RESULT(MRES_IGNORED);
	}

	void v8_FreeEntPrivateData (edict_t *pEdict) {
		SET_META_RESULT(MRES_IGNORED);
	}

	void v8_DeltaSetField (struct delta_s *pFields, const char *fieldname) {
		SET_META_RESULT(MRES_IGNORED);
	}

	void v8_DeltaUnsetField (struct delta_s *pFields, const char *fieldname) {
		SET_META_RESULT(MRES_IGNORED);
	}

	void v8_DeltaAddEncoder (char *name, void (*conditionalencode)( struct delta_s *pFields, const unsigned char *from, const unsigned char *to )) {
		SET_META_RESULT(MRES_IGNORED);
	}

	int v8_DeltaFindField (struct delta_s *pFields, const char *fieldname) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	void v8_DeltaSetFieldByIndex (struct delta_s *pFields, int fieldNumber) {
		SET_META_RESULT(MRES_IGNORED);
	}

	int v8_PrecacheGeneric (char* s) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	unsigned short v8_PrecacheEvent (int type, const char*psz) {
		SET_META_RESULT(MRES_IGNORED);
	}

	float v8_RandomFloat (float flLow, float flHigh) {
		SET_META_RESULT(MRES_IGNORED);
		return 0.0;
	}

	const char * v8_Cmd_Args (void) {
		SET_META_RESULT(MRES_IGNORED);
	}

	const char * v8_Cmd_Argv (int argc) {
		SET_META_RESULT(MRES_IGNORED);
	}

	int v8_Cmd_Argc (void) {
		SET_META_RESULT(MRES_IGNORED);
		return 0;
	}

	edict_t* v8_PEntityOfEntOffset (int iEntOffset) {
		SET_META_RESULT(MRES_IGNORED);
	}

