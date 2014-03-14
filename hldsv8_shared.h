/**
 * Callback function status
 */
enum {
	CB_NA = 0,
	CB_UNDEFINED,
	CB_DEFINED
};

#define V8STR(str) String::NewFromUtf8(isolate, str)
#define V8NUM(num) Number::New(isolate, num)
#define V8OBJ() Object::New(isolate)
