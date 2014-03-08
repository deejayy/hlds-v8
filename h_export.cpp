#include <extdll.h>

#include <h_export.h>

// From SDK dlls/h_export.cpp:

//! Holds engine functionality callbacks
enginefuncs_t g_engfuncs;
globalvars_t  *gpGlobals;

// Receive engine function table from engine.
// This appears to be the _first_ DLL routine called by the engine, so we
// do some setup operations here.
void WINAPI GiveFnptrsToDll( enginefuncs_t* pengfuncsFromEngine, globalvars_t *pGlobals )
{
	memcpy(&g_engfuncs, pengfuncsFromEngine, sizeof(enginefuncs_t));
	gpGlobals = pGlobals;
}
