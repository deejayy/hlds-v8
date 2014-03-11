extern "C" { void *__dso_handle = NULL; }

extern void jsInitialize               ();

#include <v8.h>

extern void v8c_GetPlayerName          (const v8::FunctionCallbackInfo<v8::Value> &args);
extern void v8c_GetPlayerAuthId        (const v8::FunctionCallbackInfo<v8::Value> &args);
extern void v8c_GetPlayerInfoKeyBuffer (const v8::FunctionCallbackInfo<v8::Value> &args);
extern void v8c_GetPlayerUserId        (const v8::FunctionCallbackInfo<v8::Value> &args);
extern void v8c_GetPlayerWONId         (const v8::FunctionCallbackInfo<v8::Value> &args);

extern int                   v8c_CheckCallbackIsDefined (const char *name);
extern v8::Handle<v8::Value> v8c_UCallback (const char *name, v8::Handle<v8::Object> params);
