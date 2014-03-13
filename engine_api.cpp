#include <extdll.h>

#include <meta_api.h>

#include "hldsv8.h"

enginefuncs_t meta_engfuncs =
{
	v8_PrecacheModel,                          // pfnPrecacheModel()
	v8_PrecacheSound,                          // pfnPrecacheSound()
	v8_SetModel,                               // pfnSetModel()
	v8_ModelIndex,                             // pfnModelIndex()
	v8_ModelFrames,                            // pfnModelFrames()

	v8_SetSize,                                // pfnSetSize()
	v8_ChangeLevel,                            // pfnChangeLevel()
	v8_GetSpawnParms,                          // pfnGetSpawnParms()
	v8_SaveSpawnParms,                         // pfnSaveSpawnParms()

	v8_VecToYaw,                               // pfnVecToYaw()
	v8_VecToAngles,                            // pfnVecToAngles()
	v8_MoveToOrigin,                           // pfnMoveToOrigin()
	v8_ChangeYaw,                              // pfnChangeYaw()
	v8_ChangePitch,                            // pfnChangePitch()

	v8_FindEntityByString,                     // pfnFindEntityByString()
	v8_GetEntityIllum,                         // pfnGetEntityIllum()
	v8_FindEntityInSphere,                     // pfnFindEntityInSphere()
	v8_FindClientInPVS,                        // pfnFindClientInPVS()
	v8_EntitiesInPVS,                          // pfnEntitiesInPVS()

	v8_MakeVectors,                            // pfnMakeVectors()
	v8_AngleVectors,                           // pfnAngleVectors()

	v8_CreateEntity,                           // pfnCreateEntity()
	v8_RemoveEntity,                           // pfnRemoveEntity()
	v8_CreateNamedEntity,                      // pfnCreateNamedEntity()

	v8_MakeStatic,                             // pfnMakeStatic()
	v8_EntIsOnFloor,                           // pfnEntIsOnFloor()
	v8_DropToFloor,                            // pfnDropToFloor()

	v8_WalkMove,                               // pfnWalkMove()
	v8_SetOrigin,                              // pfnSetOrigin()

	v8_EmitSound,                              // pfnEmitSound()
	v8_EmitAmbientSound,                       // pfnEmitAmbientSound()

	v8_TraceLine,                              // pfnTraceLine()
	v8_TraceToss,                              // pfnTraceToss()
	v8_TraceMonsterHull,                       // pfnTraceMonsterHull()
	v8_TraceHull,                              // pfnTraceHull()
	v8_TraceModel,                             // pfnTraceModel()
	v8_TraceTexture,                           // pfnTraceTexture()
	v8_TraceSphere,                            // pfnTraceSphere()
	v8_GetAimVector,                           // pfnGetAimVector()

	v8_ServerCommand,                          // pfnServerCommand()
	v8_ServerExecute,                          // pfnServerExecute()
	v8_ClientCommand,                          // pfnClientCommand()

	v8_ParticleEffect,                         // pfnParticleEffect()
	v8_LightStyle,                             // pfnLightStyle()
	v8_DecalIndex,                             // pfnDecalIndex()
	v8_PointContents,                          // pfnPointContents()

	v8_MessageBegin,                           // pfnMessageBegin()
	v8_MessageEnd,                             // pfnMessageEnd()

	v8_WriteByte,                              // pfnWriteByte()
	v8_WriteChar,                              // pfnWriteChar()
	v8_WriteShort,                             // pfnWriteShort()
	v8_WriteLong,                              // pfnWriteLong()
	v8_WriteAngle,                             // pfnWriteAngle()
	v8_WriteCoord,                             // pfnWriteCoord()
	v8_WriteString,                            // pfnWriteString()
	v8_WriteEntity,                            // pfnWriteEntity()

	v8_CVarRegister,                           // pfnCVarRegister()
	v8_CVarGetFloat,                           // pfnCVarGetFloat()
	v8_CVarGetString,                          // pfnCVarGetString()
	v8_CVarSetFloat,                           // pfnCVarSetFloat()
	v8_CVarSetString,                          // pfnCVarSetString()

	v8_AlertMessage,                           // pfnAlertMessage()
	v8_EngineFprintf,                          // pfnEngineFprintf()

	v8_PvAllocEntPrivateData,                  // pfnPvAllocEntPrivateData()
	v8_PvEntPrivateData,                       // pfnPvEntPrivateData()
	v8_FreeEntPrivateData,                     // pfnFreeEntPrivateData()

	v8_SzFromIndex,                            // pfnSzFromIndex()
	v8_AllocString,                            // pfnAllocString()

	v8_GetVarsOfEnt,                           // pfnGetVarsOfEnt()
	v8_PEntityOfEntOffset,                     // pfnPEntityOfEntOffset()
	v8_EntOffsetOfPEntity,                     // pfnEntOffsetOfPEntity()
	v8_IndexOfEdict,                           // pfnIndexOfEdict()
	v8_PEntityOfEntIndex,                      // pfnPEntityOfEntIndex()
	v8_FindEntityByVars,                       // pfnFindEntityByVars()
	v8_GetModelPtr,                            // pfnGetModelPtr()

	v8_RegUserMsg,                             // pfnRegUserMsg()

	v8_AnimationAutomove,                      // pfnAnimationAutomove()
	v8_GetBonePosition,                        // pfnGetBonePosition()

	v8_FunctionFromName,                       // pfnFunctionFromName()
	v8_NameForFunction,                        // pfnNameForFunction()

	v8_ClientPrintf,                           // pfnClientPrintf()
	v8_ServerPrint,                            // pfnServerPrint()

	v8_Cmd_Args,                               // pfnCmd_Args()
	v8_Cmd_Argv,                               // pfnCmd_Argv()
	v8_Cmd_Argc,                               // pfnCmd_Argc()

	v8_GetAttachment,                          // pfnGetAttachment()

	v8_CRC32_Init,                             // pfnCRC32_Init()
	v8_CRC32_ProcessBuffer,                    // pfnCRC32_ProcessBuffer()
	v8_CRC32_ProcessByte,                      // pfnCRC32_ProcessByte()
	v8_CRC32_Final,                            // pfnCRC32_Final()

	v8_RandomLong,                             // pfnRandomLong()
	v8_RandomFloat,                            // pfnRandomFloat()

	v8_SetView,                                // pfnSetView()
	v8_Time,                                   // pfnTime()
	v8_CrosshairAngle,                         // pfnCrosshairAngle()

	v8_LoadFileForMe,                          // pfnLoadFileForMe()
	v8_FreeFile,                               // pfnFreeFile()

	v8_EndSection,                             // pfnEndSection()
	v8_CompareFileTime,                        // pfnCompareFileTime()
	v8_GetGameDir,                             // pfnGetGameDir()
	v8_Cvar_RegisterVariable,                  // pfnCvar_RegisterVariable()
	v8_FadeClientVolume,                       // pfnFadeClientVolume()
	v8_SetClientMaxspeed,                      // pfnSetClientMaxspeed()
	v8_CreateFakeClient,                       // pfnCreateFakeClient()
	v8_RunPlayerMove,                          // pfnRunPlayerMove()
	v8_NumberOfEntities,                       // pfnNumberOfEntities()

	v8_GetInfoKeyBuffer,                       // pfnGetInfoKeyBuffer()
	v8_InfoKeyValue,                           // pfnInfoKeyValue()
	v8_SetKeyValue,                            // pfnSetKeyValue()
	v8_SetClientKeyValue,                      // pfnSetClientKeyValue()

	v8_IsMapValid,                             // pfnIsMapValid()
	v8_StaticDecal,                            // pfnStaticDecal()
	v8_PrecacheGeneric,                        // pfnPrecacheGeneric()
	v8_GetPlayerUserId,                        // pfnGetPlayerUserId()
	v8_BuildSoundMsg,                          // pfnBuildSoundMsg()
	v8_IsDedicatedServer,                      // pfnIsDedicatedServer()
	v8_CVarGetPointer,                         // pfnCVarGetPointer()
	v8_GetPlayerWONId,                         // pfnGetPlayerWONId()

	v8_Info_RemoveKey,                         // pfnInfo_RemoveKey()
	v8_GetPhysicsKeyValue,                     // pfnGetPhysicsKeyValue()
	v8_SetPhysicsKeyValue,                     // pfnSetPhysicsKeyValue()
	v8_GetPhysicsInfoString,                   // pfnGetPhysicsInfoString()
	v8_PrecacheEvent,                          // pfnPrecacheEvent()
	v8_PlaybackEvent,                          // pfnPlaybackEvent()

	v8_SetFatPVS,                              // pfnSetFatPVS()
	v8_SetFatPAS,                              // pfnSetFatPAS()

	v8_CheckVisibility,                        // pfnCheckVisibility()

	v8_DeltaSetField,                          // pfnDeltaSetField()
	v8_DeltaUnsetField,                        // pfnDeltaUnsetField()
	v8_DeltaAddEncoder,                        // pfnDeltaAddEncoder()
	v8_GetCurrentPlayer,                       // pfnGetCurrentPlayer()
	v8_CanSkipPlayer,                          // pfnCanSkipPlayer()
	v8_DeltaFindField,                         // pfnDeltaFindField()
	v8_DeltaSetFieldByIndex,                   // pfnDeltaSetFieldByIndex()
	v8_DeltaUnsetFieldByIndex,                 // pfnDeltaUnsetFieldByIndex()

	v8_SetGroupMask,                           // pfnSetGroupMask()

	v8_CreateInstancedBaseline,                // pfnCreateInstancedBaseline()
	v8_Cvar_DirectSet,                         // pfnCvar_DirectSet()

	v8_ForceUnmodified,                        // pfnForceUnmodified()

	v8_GetPlayerStats,                         // pfnGetPlayerStats()

	v8_AddServerCommand,                       // pfnAddServerCommand()

	// Added in SDK 2.2:
	v8_Voice_GetClientListening,               // pfnVoice_GetClientListening()
	v8_Voice_SetClientListening,               // pfnVoice_SetClientListening()

	// Added for HL 1109 (no SDK update):
	v8_GetPlayerAuthId,                        // pfnGetPlayerAuthId()

	// Added 2003-11-10 (no SDK update):
	v8_SequenceGet,                            // pfnSequenceGet()
	v8_SequencePickSentence,                   // pfnSequencePickSentence()
	v8_GetFileSize,                            // pfnGetFileSize()
	v8_GetApproxWavePlayLen,                   // pfnGetApproxWavePlayLen()
	v8_IsCareerMatch,                          // pfnIsCareerMatch()
	v8_GetLocalizedStringLength,               // pfnGetLocalizedStringLength()
	v8_RegisterTutorMessageShown,              // pfnRegisterTutorMessageShown()
	v8_GetTimesTutorMessageShown,              // pfnGetTimesTutorMessageShown()
	v8_ProcessTutorMessageDecayBuffer,         // pfnProcessTutorMessageDecayBuffer()
	v8_ConstructTutorMessageDecayBuffer,       // pfnConstructTutorMessageDecayBuffer()
	v8_ResetTutorMessageDecayData,             // pfnResetTutorMessageDecayData()

	// Added Added 2005-08-11 (no SDK update)
	v8_QueryClientCvarValue,                   // pfnQueryClientCvarValue()
	// Added Added 2005-11-22 (no SDK update)
	v8_QueryClientCvarValue2,                  // pfnQueryClientCvarValue2()
};

C_DLLEXPORT int GetEngineFunctions(enginefuncs_t *pengfuncsFromEngine,
		int *interfaceVersion)
{
	if(!pengfuncsFromEngine) {
		UTIL_LogPrintf("GetEngineFunctions called with null pengfuncsFromEngine");
		return(FALSE);
	}
	else if(*interfaceVersion != ENGINE_INTERFACE_VERSION) {
		UTIL_LogPrintf("GetEngineFunctions version mismatch; requested=%d ours=%d", *interfaceVersion, ENGINE_INTERFACE_VERSION);
		// Tell metamod what version we had, so it can figure out who is out of date.
		*interfaceVersion = ENGINE_INTERFACE_VERSION;
		return(FALSE);
	}
	memcpy(pengfuncsFromEngine, &meta_engfuncs, sizeof(enginefuncs_t));
	return(TRUE);
}
