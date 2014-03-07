#include <extdll.h>
#include <meta_api.h>
#include <cbase.h>

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

void v8_ServerActivate (edict_t *pEdictList, int edictCount, int clientMax)
{
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

	SET_META_RESULT(MRES_HANDLED);
}

qboolean v8_ClientConnect (edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128])
{
	Context::Scope context_scope(context);

	Handle<String>   myName = String::NewFromUtf8(isolate, "ClientConnect");
	Handle<Function> fn     = Handle<Function>::Cast(context->Global()->Get(myName));

	if (fn->GetName()->ToString()->Equals(myName)) {
		const int      fnArgc  = 3;
		Handle<String> name    = String::NewFromUtf8(isolate, pszName);
		Handle<String> address = String::NewFromUtf8(isolate, pszAddress);
		Handle<String> authId  = String::NewFromUtf8(isolate, g_engfuncs.pfnGetPlayerAuthId(pEntity));
		
		Handle<Value>  fnArgs[fnArgc]  = { name, address, authId };

		Handle<Value>  result  = fn->Call(context->Global(), fnArgc, fnArgs);
	} else {
		ALERT(at_logged, "[HLDSV8] No ClientConnect defined in script!\n");
	}

	SET_META_RESULT(MRES_IGNORED);
	return 1;
}
