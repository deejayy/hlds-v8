extern void     v8_ServerActivate(edict_t *pEdictList, int edictCount, int clientMax);
extern qboolean v8_ClientConnect (edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128]);

extern "C" { void *__dso_handle = NULL; }
