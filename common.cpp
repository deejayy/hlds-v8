#include <stdio.h>
#include <stdlib.h>

#include "sdk_util.h"

char* fileReader(char* fileName)
{
	FILE*  pFile;
	long   lSize;
	char*  pBuffer;
	size_t result;

	pFile = fopen(fileName, "rb");
	if (pFile == NULL) {
		UTIL_LogPrintf("File read error");
	} else {
		fseek(pFile, 0, SEEK_END);
		lSize = ftell(pFile);
		rewind(pFile);
		pBuffer = (char*) calloc(sizeof(char) * lSize, sizeof(char));
		if (pBuffer == NULL) {
			UTIL_LogPrintf("Cannot allocate buffer");
		} else {
			result = fread(pBuffer, 1, lSize, pFile);
			if (result != lSize) {
				UTIL_LogPrintf("Read error");
			} else {
				fclose(pFile);
			}
		}
	}

	return pBuffer;
}
