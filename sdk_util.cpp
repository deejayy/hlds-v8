#include <extdll.h>
#include <enginecallback.h>		// ALERT()

#include "osdep.h"				// win32 vsnprintf, etc

//=========================================================
// UTIL_LogPrintf - Prints a logged message to console.
// Preceded by LOG: ( timestamp ) < message >
//=========================================================
void UTIL_LogPrintf( char *fmt, ... )
{
	va_list			argptr;
	static char		string[1024];
	
	va_start ( argptr, fmt );
	vsnprintf ( string, sizeof(string), fmt, argptr );
	va_end   ( argptr );

	// Print to server console
	ALERT( at_logged, "%s", string );
}
