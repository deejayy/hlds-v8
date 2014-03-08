#include <extdll.h>

#include <dllapi.h>
#include <meta_api.h>
#include "hldsv8.h"

static DLL_FUNCTIONS gFunctionTable = 
{
	&v8_GameInit,					// pfnGameInit
	&v8_Spawn,						// pfnSpawn
	&v8_Think,						// pfnThink
	&v8_Use,						// pfnUse
	&v8_Touch,						// pfnTouch
	&v8_Blocked,					// pfnBlocked
	&v8_KeyValue,					// pfnKeyValue
	&v8_Save,						// pfnSave
	&v8_Restore,					// pfnRestore
	&v8_SetAbsBox,					// pfnSetAbsBox

	&v8_SaveWriteFields,			// pfnSaveWriteFields
	&v8_SaveReadFields,				// pfnSaveReadFields

	&v8_SaveGlobalState,			// pfnSaveGlobalState
	&v8_RestoreGlobalState,			// pfnRestoreGlobalState
	&v8_ResetGlobalState,			// pfnResetGlobalState

	&v8_ClientConnect,				// pfnClientConnect
	&v8_ClientDisconnect,			// pfnClientDisconnect
	&v8_ClientKill,					// pfnClientKill
	&v8_ClientPutInServer,			// pfnClientPutInServer
	&v8_ClientCommand,				// pfnClientCommand
	&v8_ClientUserInfoChanged,		// pfnClientUserInfoChanged
	&v8_ServerActivate,				// pfnServerActivate
	&v8_ServerDeactivate,			// pfnServerDeactivate

	&v8_PlayerPreThink,				// pfnPlayerPreThink
	&v8_PlayerPostThink,			// pfnPlayerPostThink

	&v8_StartFrame,					// pfnStartFrame
	&v8_ParmsNewLevel,				// pfnParmsNewLevel
	&v8_ParmsChangeLevel,			// pfnParmsChangeLevel

	&v8_GetGameDescription,			// pfnGetGameDescription
	&v8_PlayerCustomization,		// pfnPlayerCustomization

	&v8_SpectatorConnect,			// pfnSpectatorConnect
	&v8_SpectatorDisconnect,		// pfnSpectatorDisconnect
	&v8_SpectatorThink,				// pfnSpectatorThink
	
	&v8_Sys_Error,					// pfnSys_Error

	&v8_PM_Move,					// pfnPM_Move
	&v8_PM_Init,					// pfnPM_Init
	&v8_PM_FindTextureType,			// pfnPM_FindTextureType
	
	&v8_SetupVisibility,			// pfnSetupVisibility
	&v8_UpdateClientData,			// pfnUpdateClientData
	&v8_AddToFullPack,				// pfnAddToFullPack
	&v8_CreateBaseline,				// pfnCreateBaseline
	&v8_RegisterEncoders,			// pfnRegisterEncoders
	&v8_GetWeaponData,				// pfnGetWeaponData
	&v8_CmdStart,					// pfnCmdStart
	&v8_CmdEnd,						// pfnCmdEnd
	&v8_ConnectionlessPacket,		// pfnConnectionlessPacket
	&v8_GetHullBounds,				// pfnGetHullBounds
	&v8_CreateInstancedBaselines,	// pfnCreateInstancedBaselines
	&v8_InconsistentFile,			// pfnInconsistentFile
	&v8_AllowLagCompensation,		// pfnAllowLagCompensation
};

C_DLLEXPORT int GetEntityAPI2(DLL_FUNCTIONS *pFunctionTable, 
		int *interfaceVersion)
{
	if(!pFunctionTable) {
		UTIL_LogPrintf("GetEntityAPI2 called with null pFunctionTable");
		return(FALSE);
	}
	else if(*interfaceVersion != INTERFACE_VERSION) {
		UTIL_LogPrintf("GetEntityAPI2 version mismatch; requested=%d ours=%d", *interfaceVersion, INTERFACE_VERSION);
		//! Tell metamod what version we had, so it can figure out who is out of date.
		*interfaceVersion = INTERFACE_VERSION;
		return(FALSE);
	}
	memcpy(pFunctionTable, &gFunctionTable, sizeof(DLL_FUNCTIONS));
	return(TRUE);
}
