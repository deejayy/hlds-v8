#include <extdll.h>
#include <meta_api.h>
#include <cbase.h>
#include <player.h>
#include <usercmd.h>

#include <v8.h>

#include "common.h"
#include "hldsv8.h"
#include "hldsv8_shared.h"

using namespace v8;

/**
 * V8 Common: Check whether args[id] is a valid client entity
 *
 * @params FunctionCallbackInfo args virtual arguments: id
 *
 * @return bool
 */
int v8c_CheckClient(const v8::FunctionCallbackInfo<Value> &args, const char* funcName)
{
	if (args.Length() > 0) {
		int id = args[0]->ToInt32()->Value();
		if (id) {
			if (entities[id]) {
				return id;
			} else {
				ALERT(at_logged, "%s: invalid entity (disconnected?)\n", funcName);
			}
		}
	} else {
		ALERT(at_logged, "%s: missing arguments\n", funcName);
	}

	return 0;
}

/**
 * V8 Common: Get player's name
 *
 * @params FunctionCallbackInfo args virtual arguments: id
 *
 * @return v8::String
 */
void v8c_GetPlayerName(const v8::FunctionCallbackInfo<Value> &args) {
	Handle<Value> result = Null(isolate);

	if (int id = v8c_CheckClient(args, __FUNCTION__)) {
		result = V8STR(STRING(entities[id]->v.netname));
	}

	args.GetReturnValue().Set(result);
}

/**
 * V8 Common: Get player's auth id (steam id)
 *
 * @params FunctionCallbackInfo args virtual arguments: id
 *
 * @return v8::String
 */
void v8c_GetPlayerAuthId(const v8::FunctionCallbackInfo<Value> &args) {
	Handle<Value> result = Null(isolate);

	if (int id = v8c_CheckClient(args, __FUNCTION__)) {
		result = V8STR(g_engfuncs.pfnGetPlayerAuthId(entities[id]));
	}

	args.GetReturnValue().Set(result);
}

/**
 * V8 Common: Get player's info key buffer (\key\value...)
 *
 * @params FunctionCallbackInfo args virtual arguments: id
 *
 * @return v8::String
 */
void v8c_GetPlayerInfoKeyBuffer(const v8::FunctionCallbackInfo<Value> &args) {
	Handle<Value> result = Null(isolate);

	if (int id = v8c_CheckClient(args, __FUNCTION__)) {
		result = V8STR(g_engfuncs.pfnGetInfoKeyBuffer(entities[id]));
	}

	args.GetReturnValue().Set(result);
}

/**
 * V8 Common: Get player's user id (#uid)
 *
 * @params FunctionCallbackInfo args virtual arguments: id
 *
 * @return v8::String
 */
void v8c_GetPlayerUserId(const v8::FunctionCallbackInfo<Value> &args) {
	Handle<Value> result = Null(isolate);

	if (int id = v8c_CheckClient(args, __FUNCTION__)) {
		result = V8NUM(g_engfuncs.pfnGetPlayerUserId(entities[id]));
	}

	args.GetReturnValue().Set(result);
}

/**
 * V8 Common: Get player's WON id
 *
 * @params FunctionCallbackInfo args virtual arguments: id
 *
 * @return v8::String
 */
void v8c_GetPlayerWONId(const v8::FunctionCallbackInfo<Value> &args) {
	Handle<Value> result = Null(isolate);

	if (int id = v8c_CheckClient(args, __FUNCTION__)) {
		result = V8NUM(g_engfuncs.pfnGetPlayerWONId(entities[id]));
	}

	args.GetReturnValue().Set(result);
}

void v8c_RegUserMsg(const v8::FunctionCallbackInfo<Value> &args) {
	String::Utf8Value name(args[0]->ToString());
	int iSize = args[1]->ToInt32()->Value();
	int msgid = g_engfuncs.pfnRegUserMsg(*name, iSize);
	args.GetReturnValue().Set(V8NUM(msgid));
}

/**
 * Convert a vec3_t array to an Object
 */
Handle<Object> v8c_Vec3tToObject(vec3_t vec)
{
	Context::Scope context_scope(context);

	Handle<Object> vecObj = V8OBJ();
	vecObj->Set(V8STR("x"), V8NUM(vec[0]));
	vecObj->Set(V8STR("y"), V8NUM(vec[1]));
	vecObj->Set(V8STR("z"), V8NUM(vec[2]));

	return vecObj;
}

/**
 * Check whether a callback is defined in context
 *
 * @param char* name function name
 *
 * @return int CB_*
 */
int v8c_CheckCallbackIsDefined(const char *name)
{
	int result = CB_NA;

	Context::Scope context_scope(context);

	Handle<String>   myName = V8STR(name);
	Handle<Function> fn     = Handle<Function>::Cast(context->Global()->Get(myName));

	if (fn->GetName()->ToString()->Equals(myName)) {
		result = CB_DEFINED;
	} else {
		ALERT(at_logged, "[HLDSV8] No %s defined in script!\n", name);
		result = CB_UNDEFINED;
	}

	return result;
}

/**
 * Universal callback with params and return value
 *
 * @param char*          name      function name
 * @param int            isDefined is the callback defined in script
 * @param Handle<Object> params    js object with arguments
 *
 * @return Handle<Value>
 */
Handle<Value> v8c_UCallbackReturn(const char *name, Handle<Object> params)
{
	Context::Scope context_scope(context);

	Handle<Value>    callbackReturn = Null(isolate);
	Handle<String>   myName = V8STR(name);
	Handle<Function> fn     = Handle<Function>::Cast(context->Global()->Get(myName));

	const int      fnArgc = 1;
	Handle<Value>  fnArgs[fnArgc]  = { params };

	Handle<Value> fnReturnValue = fn->Call(context->Global(), fnArgc, fnArgs);

	int metaResult = 1;
	if (fnReturnValue->IsInt32()) {
		metaResult = fnReturnValue->ToInt32()->Value();
	} else {
		Handle<Object> fnReturnObject = Handle<Object>::Cast(fnReturnValue);
		metaResult     = fnReturnObject->Get(V8STR("vres"))->ToInt32()->Value();
		callbackReturn = fnReturnObject->Get(V8STR("retval"));
	}
	SET_META_RESULT(META_RES(metaResult ? metaResult : 1));

	return callbackReturn;

}

/**
 * Universal callback with params
 *
 * @param char*          name      function name
 * @param int            isDefined is the callback defined in script
 * @param Handle<Object> params    js object with arguments
 *
 * @return Handle<Value>
 */
META_RES v8c_UCallback(const char *name, Handle<Object> params)
{
	Context::Scope context_scope(context);

	Handle<String>   myName = V8STR(name);
	Handle<Function> fn     = Handle<Function>::Cast(context->Global()->Get(myName));

	const int      fnArgc = 1;
	Handle<Value>  fnArgs[fnArgc]  = { params };

	int      res     = fn->Call(context->Global(), fnArgc, fnArgs)->ToInt32()->Value();
	META_RES result  = META_RES(res ? res : 1);

	return result;
}

META_RES v8c_UCallback(const char *name)
{
	Context::Scope context_scope(context);
	Handle<Object> params = V8OBJ();

	return v8c_UCallback(name, params);
}

META_RES v8c_UCallback(const char *name, int id)
{
	Context::Scope context_scope(context);
	Handle<Object> params = V8OBJ();
	params->Set(V8STR("id"), V8NUM(id));

	return v8c_UCallback(name, params);
}

/**
 * Global JS window object
 */
static void jsWindowObjectAccessor(Local<String> property, const PropertyCallbackInfo<Value>& info) {
	info.GetReturnValue().Set(info.Holder());
}

/**
 * window.console.log() implementation
 *
 * @params FunctionCallbackInfo args virtual arguments: str, ...
 *
 * @return v8::Null
 */
static void jsConsolePrint(const v8::FunctionCallbackInfo<Value> &args) {
	for (int i=0; i < args.Length(); i++) {
		String::Utf8Value str(args[i]->ToString());
		ALERT(at_logged, "%s\n", *str);
	}

	args.GetReturnValue().Set(Null(isolate));
}

/**
 * Report an exception from script compiling
 *
 * @param Isolate  isolate
 * @param TryCatch try_catch
 *
 * @return void
 */
void ReportException(Isolate* isolate, TryCatch* try_catch) {
	HandleScope handle_scope(isolate);
	String::Utf8Value exception(try_catch->Exception()->ToString());
	Handle<Message> message = try_catch->Message();
	if (message.IsEmpty()) {
		// V8 didn't provide any extra information about this error; just
		// print the exception.
		ALERT(at_logged, "[HLDSV8] %s\n", *exception);
	} else {
		// Print (filename):(line number): (message).
		String::Utf8Value filename(message->GetScriptResourceName());
		int linenum = message->GetLineNumber();
		ALERT(at_logged, "[HLDSV8] %s:%i: %s\n", *filename, linenum, *exception);
		// Print line of source code.
		String::Utf8Value sourceline(message->GetSourceLine());
		ALERT(at_logged, "[HLDSV8] %s\n", *sourceline);
		String::Utf8Value stack_trace(try_catch->StackTrace());
		if (stack_trace.length() > 0) {
			ALERT(at_logged, "[HLDSV8] %s\n", *stack_trace);
		}
	}
}

/**
 * Execute JS snippet
 *
 * @param Isolate        isolate
 * @param Handle<String> source            js code
 * @param Handle<Value>  name              script name
 * @param bool           print_result      print result?
 * @param bool           report_exceptions call exception reporting on compilation / runtime exceptions
 */
bool ExecuteString(Isolate* isolate, Handle<String> source, Handle<Value> name, bool print_result, bool report_exceptions) {
	HandleScope handle_scope(isolate);
	TryCatch try_catch;
	Handle<Script> script = Script::Compile(source, name);
	if (script.IsEmpty()) {
		// Print errors that happened during compilation.
		if (report_exceptions)
			ReportException(isolate, &try_catch);
		return false;
	} else {
		Handle<Value> result = script->Run();
		if (result.IsEmpty()) {
			// Print errors that happened during execution.
			if (report_exceptions)
				ReportException(isolate, &try_catch);
			return false;
		} else {
			if (print_result && !result->IsUndefined()) {
				// If all went well and the result wasn't undefined then print
				// the returned value.
				String::Utf8Value str(result);
				ALERT(at_logged, "[HLDSV8] %s\n", *str);
			}
			return true;
		}
	}
}

/**
 * Initialize v8 js engine
 *
 * @return void
 */
void jsInitialize()
{
	Handle<ObjectTemplate> globalObject = ObjectTemplate::New();
	Handle<ObjectTemplate> console      = ObjectTemplate::New();
	Handle<ObjectTemplate> v8Common     = ObjectTemplate::New();

	globalObject->SetAccessor(V8STR("window" ), jsWindowObjectAccessor);
	globalObject->Set        (V8STR("console"), console);
	console     ->Set        (V8STR("log"    ), FunctionTemplate::New(isolate, jsConsolePrint));

	globalObject->Set        (V8STR("v8"), v8Common);
	v8Common    ->Set        (V8STR("getPlayerName"         ), FunctionTemplate::New(isolate, v8c_GetPlayerName));
	v8Common    ->Set        (V8STR("getPlayerUserId"       ), FunctionTemplate::New(isolate, v8c_GetPlayerUserId));
	v8Common    ->Set        (V8STR("getPlayerAuthId"       ), FunctionTemplate::New(isolate, v8c_GetPlayerAuthId));
	v8Common    ->Set        (V8STR("getPlayerInfoKeyBuffer"), FunctionTemplate::New(isolate, v8c_GetPlayerInfoKeyBuffer));
	v8Common    ->Set        (V8STR("getPlayerWONId"        ), FunctionTemplate::New(isolate, v8c_GetPlayerWONId));

	v8Common    ->Set        (V8STR("regUserMsg"            ), FunctionTemplate::New(isolate, v8c_RegUserMsg));

	context = Context::New(isolate, NULL, globalObject);
	Context::Scope context_scope(context);

	char* scriptSource = fileReader("/home/cstrike/inst/debug/cstrike/plugins/hldsv8/scripts/test.js");

	if (scriptSource != NULL) {
		if (!ExecuteString(isolate, V8STR(scriptSource), V8STR("test.js"), true, true)) {
			ALERT(at_logged, "[HLDSV8] Engine Started with errors!\n");
		}
	} else {
		ALERT(at_logged, "[HLDSV8] Engine failed to start, no script\n");
	}
}
