// ENGFUNC Callbacks

extern int               v8_PrecacheModel                    ( char* s );
extern int               v8_PrecacheSound                    ( char* s );
extern void              v8_SetModel                         ( edict_t *e, const char *m );
extern int               v8_ModelIndex                       ( const char *m );
extern int               v8_ModelFrames                      ( int modelIndex );
extern void              v8_SetSize                          ( edict_t *e, const float *rgflMin, const float *rgflMax );
extern void              v8_ChangeLevel                      ( char* s1, char* s2 );
extern void              v8_GetSpawnParms                    ( edict_t *ent );
extern void              v8_SaveSpawnParms                   ( edict_t *ent );
extern float             v8_VecToYaw                         ( const float *rgflVector );
extern void              v8_VecToAngles                      ( const float *rgflVectorIn, float *rgflVectorOut );
extern void              v8_MoveToOrigin                     ( edict_t *ent, const float *pflGoal, float dist, int iMoveType );
extern void              v8_ChangeYaw                        ( edict_t* ent );
extern void              v8_ChangePitch                      ( edict_t* ent );
extern edict_t*          v8_FindEntityByString               ( edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue );
extern int               v8_GetEntityIllum                   ( edict_t* pEnt );
extern edict_t*          v8_FindEntityInSphere               ( edict_t *pEdictStartSearchAfter, const float *org, float rad );
extern edict_t*          v8_FindClientInPVS                  ( edict_t *pEdict );
extern edict_t*          v8_EntitiesInPVS                    ( edict_t *pplayer );
extern void              v8_MakeVectors                      ( const float *rgflVector );
extern void              v8_AngleVectors                     ( const float *rgflVector, float *forward, float *right, float *up );
extern edict_t*          v8_CreateEntity                     ( void );
extern void              v8_RemoveEntity                     ( edict_t* e );
extern edict_t*          v8_CreateNamedEntity                ( int className );
extern void              v8_MakeStatic                       ( edict_t *ent );
extern int               v8_EntIsOnFloor                     ( edict_t *e );
extern int               v8_DropToFloor                      ( edict_t* e );
extern int               v8_WalkMove                         ( edict_t *ent, float yaw, float dist, int iMode );
extern void              v8_SetOrigin                        ( edict_t *e, const float *rgflOrigin );
extern void              v8_EmitSound                        ( edict_t *entity, int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch );
extern void              v8_EmitAmbientSound                 ( edict_t *entity, float *pos, const char *samp, float vol, float attenuation, int fFlags, int pitch );
extern void              v8_TraceLine                        ( const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr );
extern void              v8_TraceToss                        ( edict_t* pent, edict_t* pentToIgnore, TraceResult *ptr );
extern int               v8_TraceMonsterHull                 ( edict_t *pEdict, const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr );
extern void              v8_TraceHull                        ( const float *v1, const float *v2, int fNoMonsters, int hullNumber, edict_t *pentToSkip, TraceResult *ptr );
extern void              v8_TraceModel                       ( const float *v1, const float *v2, int hullNumber, edict_t *pent, TraceResult *ptr );
extern const char *      v8_TraceTexture                     ( edict_t *pTextureEntity, const float *v1, const float *v2  );
extern void              v8_TraceSphere                      ( const float *v1, const float *v2, int fNoMonsters, float radius, edict_t *pentToSkip, TraceResult *ptr );
extern void              v8_GetAimVector                     ( edict_t* ent, float speed, float *rgflReturn );
extern void              v8_ServerCommand                    ( char* str );
extern void              v8_ServerExecute                    ( void );
extern void              v8_ClientCommand                    ( edict_t* pEdict, char* szFmt, ... );
extern void              v8_ParticleEffect                   ( const float *org, const float *dir, float color, float count );
extern void              v8_LightStyle                       ( int style, char* val );
extern int               v8_DecalIndex                       ( const char *name );
extern int               v8_PointContents                    ( const float *rgflVector );
extern void              v8_MessageBegin                     ( int msg_dest, int msg_type, const float *pOrigin, edict_t *ed );
extern void              v8_MessageEnd                       ( void );
extern void              v8_WriteByte                        ( int iValue );
extern void              v8_WriteChar                        ( int iValue );
extern void              v8_WriteShort                       ( int iValue );
extern void              v8_WriteLong                        ( int iValue );
extern void              v8_WriteAngle                       ( float flValue );
extern void              v8_WriteCoord                       ( float flValue );
extern void              v8_WriteString                      ( const char *sz );
extern void              v8_WriteEntity                      ( int iValue );
extern void              v8_CVarRegister                     ( cvar_t *pCvar );
extern float             v8_CVarGetFloat                     ( const char *szVarName );
extern const char*       v8_CVarGetString                    ( const char *szVarName );
extern void              v8_CVarSetFloat                     ( const char *szVarName, float flValue );
extern void              v8_CVarSetString                    ( const char *szVarName, const char *szValue );
extern void              v8_AlertMessage                     ( ALERT_TYPE atype, char *szFmt, ... );
extern void              v8_EngineFprintf                    ( void *pfile, char *szFmt, ... );
extern void*             v8_PvAllocEntPrivateData            ( edict_t *pEdict, int32 cb );
extern void*             v8_PvEntPrivateData                 ( edict_t *pEdict );
extern void              v8_FreeEntPrivateData               ( edict_t *pEdict );
extern const char*       v8_SzFromIndex                      ( int iString );
extern int               v8_AllocString                      ( const char *szValue );
extern struct entvars_s* v8_GetVarsOfEnt                     ( edict_t *pEdict );
extern edict_t*          v8_PEntityOfEntOffset               ( int iEntOffset );
extern int               v8_EntOffsetOfPEntity               ( const edict_t *pEdict );
extern int               v8_IndexOfEdict                     ( const edict_t *pEdict );
extern edict_t*          v8_PEntityOfEntIndex                ( int iEntIndex );
extern edict_t*          v8_FindEntityByVars                 ( struct entvars_s* pvars );
extern void*             v8_GetModelPtr                      ( edict_t* pEdict );
extern int               v8_RegUserMsg                       ( const char *pszName, int iSize );
extern void              v8_AnimationAutomove                ( const edict_t* pEdict, float flTime );
extern void              v8_GetBonePosition                  ( const edict_t* pEdict, int iBone, float *rgflOrigin, float *rgflAngles  );
extern uint32            v8_FunctionFromName                 ( const char *pName  );
extern const char *      v8_NameForFunction                  ( uint32 function  );
extern void              v8_ClientPrintf                     ( edict_t* pEdict, PRINT_TYPE ptype, const char *szMsg  );
extern void              v8_ServerPrint                      ( const char *szMsg  );
extern const char *      v8_Cmd_Args                         ( void  );
extern const char *      v8_Cmd_Argv                         ( int argc  );
extern int               v8_Cmd_Argc                         ( void  );
extern void              v8_GetAttachment                    ( const edict_t *pEdict, int iAttachment, float *rgflOrigin, float *rgflAngles  );
extern void              v8_CRC32_Init                       ( CRC32_t *pulCRC );
extern void              v8_CRC32_ProcessBuffer              ( CRC32_t *pulCRC, void *p, int len );
extern void              v8_CRC32_ProcessByte                ( CRC32_t *pulCRC, unsigned char ch );
extern CRC32_t           v8_CRC32_Final                      ( CRC32_t pulCRC );
extern int32             v8_RandomLong                       ( int32  lLow,  int32  lHigh );
extern float             v8_RandomFloat                      ( float flLow, float flHigh );
extern void              v8_SetView                          ( const edict_t *pClient, const edict_t *pViewent  );
extern float             v8_Time                             ( void  );
extern void              v8_CrosshairAngle                   ( const edict_t *pClient, float pitch, float yaw );
extern byte *            v8_LoadFileForMe                    ( char *filename, int *pLength );
extern void              v8_FreeFile                         ( void *buffer );
extern void              v8_EndSection                       ( const char *pszSectionName );
extern int               v8_CompareFileTime                  ( char *filename1, char *filename2, int *iCompare );
extern void              v8_GetGameDir                       ( char *szGetGameDir );
extern void              v8_Cvar_RegisterVariable            ( cvar_t *variable );
extern void              v8_FadeClientVolume                 ( const edict_t *pEdict, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds );
extern void              v8_SetClientMaxspeed                ( const edict_t *pEdict, float fNewMaxspeed );
extern edict_t *         v8_CreateFakeClient                 ( const char *netname );
extern void              v8_RunPlayerMove                    ( edict_t *fakeclient, const float *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, byte impulse, byte msec  );
extern int               v8_NumberOfEntities                 ( void );
extern char*             v8_GetInfoKeyBuffer                 ( edict_t *e );
extern char*             v8_InfoKeyValue                     ( char *infobuffer, char *key );
extern void              v8_SetKeyValue                      ( char *infobuffer, char *key, char *value );
extern void              v8_SetClientKeyValue                ( int clientIndex, char *infobuffer, char *key, char *value );
extern int               v8_IsMapValid                       ( char *filename );
extern void              v8_StaticDecal                      ( const float *origin, int decalIndex, int entityIndex, int modelIndex  );
extern int               v8_PrecacheGeneric                  ( char* s );
extern int               v8_GetPlayerUserId                  ( edict_t *e  );
extern void              v8_BuildSoundMsg                    ( edict_t *entity, int channel, const char *sample, /*int*/float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, edict_t *ed );
extern int               v8_IsDedicatedServer                ( void );
extern cvar_t  *         v8_CVarGetPointer                   ( const char *szVarName );
extern unsigned int      v8_GetPlayerWONId                   ( edict_t *e );
extern void              v8_Info_RemoveKey                   ( char *s, const char *key  );
extern const char *      v8_GetPhysicsKeyValue               ( const edict_t *pClient, const char *key  );
extern void              v8_SetPhysicsKeyValue               ( const edict_t *pClient, const char *key, const char *value  );
extern const char *      v8_GetPhysicsInfoString             ( const edict_t *pClient  );
extern unsigned short    v8_PrecacheEvent                    ( int type, const char*psz  );
extern void              v8_PlaybackEvent                    ( int flags, const edict_t *pInvoker, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2  );
extern unsigned char *   v8_SetFatPVS                        ( float *org  );
extern unsigned char *   v8_SetFatPAS                        ( float *org  );
extern int               v8_CheckVisibility                  ( const edict_t *entity, unsigned char *pset  );
extern void              v8_DeltaSetField                    ( struct delta_s *pFields, const char *fieldname  );
extern void              v8_DeltaUnsetField                  ( struct delta_s *pFields, const char *fieldname  );
extern void              v8_DeltaAddEncoder                  ( char *name, void (*conditionalencode)( struct delta_s *pFields, const unsigned char *from, const unsigned char *to )  );
extern int               v8_GetCurrentPlayer                 ( void  );
extern int               v8_CanSkipPlayer                    ( const edict_t *player  );
extern int               v8_DeltaFindField                   ( struct delta_s *pFields, const char *fieldname  );
extern void              v8_DeltaSetFieldByIndex             ( struct delta_s *pFields, int fieldNumber  );
extern void              v8_DeltaUnsetFieldByIndex           ( struct delta_s *pFields, int fieldNumber  );
extern void              v8_SetGroupMask                     ( int mask, int op  );
extern int               v8_CreateInstancedBaseline          ( int classname, struct entity_state_s *baseline  );
extern void              v8_Cvar_DirectSet                   ( struct cvar_s *var, char *value  );
extern void              v8_ForceUnmodified                  ( FORCE_TYPE type, float *mins, float *maxs, const char *filename  );
extern void              v8_GetPlayerStats                   ( const edict_t *pClient, int *ping, int *packet_loss  );
extern void              v8_AddServerCommand                 ( char *cmd_name, void (*function) (void)  );
extern qboolean          v8_Voice_GetClientListening         ( int iReceiver, int iSender );
extern qboolean          v8_Voice_SetClientListening         ( int iReceiver, int iSender, qboolean bListen );
extern const char *      v8_GetPlayerAuthId                  ( edict_t *e  );
extern sequenceEntry_s*  v8_SequenceGet                      ( const char* fileName, const char* entryName  );
extern sentenceEntry_s*  v8_SequencePickSentence             ( const char* groupName, int pickMethod, int *picked  );
extern int               v8_GetFileSize                      ( char *filename  );
extern unsigned int      v8_GetApproxWavePlayLen             ( const char *filepath );
extern int               v8_IsCareerMatch                    ( void  );
extern int               v8_GetLocalizedStringLength         ( const char *label );
extern void              v8_RegisterTutorMessageShown        ( int mid );
extern int               v8_GetTimesTutorMessageShown        ( int mid );
extern void              v8_ProcessTutorMessageDecayBuffer   ( int *buffer, int bufferLength );
extern void              v8_ConstructTutorMessageDecayBuffer ( int *buffer, int bufferLength );
extern void              v8_ResetTutorMessageDecayData       ( void  );
extern void              v8_QueryClientCvarValue             ( const edict_t *player, const char *cvarName  );
extern void              v8_QueryClientCvarValue2            ( const edict_t *player, const char *cvarName, int requestID  );
extern int               v8_EngCheckParm                     ( const char *pchCmdLineToken, char **pchNextVal  );

// DLLFUNC Callbacks

extern void         v8_GameInit                  ( void );
extern int          v8_Spawn                     ( edict_t *pent );
extern void         v8_Think                     ( edict_t *pent );
extern void         v8_Use                       ( edict_t *pentUsed, edict_t *pentOther );
extern void         v8_Touch                     ( edict_t *pentTouched, edict_t *pentOther );
extern void         v8_Blocked                   ( edict_t *pentBlocked, edict_t *pentOther );
extern void         v8_KeyValue                  ( edict_t *pentKeyvalue, KeyValueData *pkvd );
extern void         v8_Save                      ( edict_t *pent, SAVERESTOREDATA *pSaveData );
extern int          v8_Restore                   ( edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity );
extern void         v8_SetAbsBox                 ( edict_t *pent );
extern void         v8_SaveWriteFields           ( SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int );
extern void         v8_SaveReadFields            ( SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int );
extern void         v8_SaveGlobalState           ( SAVERESTOREDATA * );
extern void         v8_RestoreGlobalState        ( SAVERESTOREDATA * );
extern void         v8_ResetGlobalState          ( void );
extern qboolean     v8_ClientConnect             ( edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[ 128 ] );
extern void         v8_ClientDisconnect          ( edict_t *pEntity );
extern void         v8_ClientKill                ( edict_t *pEntity );
extern void         v8_ClientPutInServer         ( edict_t *pEntity );
extern void         v8_ClientCommand             ( edict_t *pEntity );
extern void         v8_ClientUserInfoChanged     ( edict_t *pEntity, char *infobuffer );
extern void         v8_ServerActivate            ( edict_t *pEdictList, int edictCount, int clientMax );
extern void         v8_ServerDeactivate          ( void );
extern void         v8_PlayerPreThink            ( edict_t *pEntity );
extern void         v8_PlayerPostThink           ( edict_t *pEntity );
extern void         v8_StartFrame                ( void );
extern void         v8_ParmsNewLevel             ( void );
extern void         v8_ParmsChangeLevel          ( void );
extern const char  *v8_GetGameDescription        ( void );
extern void         v8_PlayerCustomization       ( edict_t *pEntity, customization_t *pCustom );
extern void         v8_SpectatorConnect          ( edict_t *pEntity );
extern void         v8_SpectatorDisconnect       ( edict_t *pEntity );
extern void         v8_SpectatorThink            ( edict_t *pEntity );
extern void         v8_Sys_Error                 ( const char *error_string );
extern void         v8_PM_Move                   ( struct playermove_s *ppmove, qboolean server );
extern void         v8_PM_Init                   ( struct playermove_s *ppmove );
extern char         v8_PM_FindTextureType        ( char *name );
extern void         v8_SetupVisibility           ( struct edict_s *pViewEntity, struct edict_s *pClient, unsigned char **pvs, unsigned char **pas );
extern void         v8_UpdateClientData          ( const struct edict_s *ent, int sendweapons, struct clientdata_s *cd );
extern int          v8_AddToFullPack             ( struct entity_state_s *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, unsigned char *pSet );
extern void         v8_CreateBaseline            ( int player, int eindex, struct entity_state_s *baseline, struct edict_s *entity, int playermodelindex, vec3_t player_mins, vec3_t player_maxs );
extern void         v8_RegisterEncoders          ( void );
extern int          v8_GetWeaponData             ( struct edict_s *player, struct weapon_data_s *info );
extern void         v8_CmdStart                  ( const edict_t *player, const struct usercmd_s *cmd, unsigned int random_seed );
extern void         v8_CmdEnd                    ( const edict_t *player );
extern int          v8_ConnectionlessPacket      ( const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size );
extern int          v8_GetHullBounds             ( int hullnumber, float *mins, float *maxs );
extern void         v8_CreateInstancedBaselines  ( void );
extern int          v8_InconsistentFile          ( const struct edict_s *player, const char *filename, char *disconnect_message );
extern int          v8_AllowLagCompensation      ( void );

#include <v8.h>

extern v8::Isolate* isolate;
extern v8::Handle<v8::Context> context;
extern edict_t *entities[33];
