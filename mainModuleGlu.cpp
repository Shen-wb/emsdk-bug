
#include <emscripten.h>
#include <stdlib.h>

//EM_JS_DEPS(webidl_binder, "$intArrayFromString,$UTF8ToString");

extern "C" {

// Define custom allocator functions that we can force export using
// EMSCRIPTEN_KEEPALIVE.  This avoids all webidl users having to add
// malloc/free to -sEXPORTED_FUNCTIONS.
EMSCRIPTEN_KEEPALIVE void webidl_free(void* p) { free(p); }
EMSCRIPTEN_KEEPALIVE void* webidl_malloc(size_t len) { return malloc(len); }


EM_JS(void, array_bounds_check_error, (size_t idx, size_t size), {
  throw 'Array index ' + idx + ' out of bounds: [0,' + size + ')';
});

static void array_bounds_check(size_t array_size, size_t array_idx) {
  if (array_idx < 0 || array_idx >= array_size) {
    array_bounds_check_error(array_idx, array_size);
  }
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

// MainModule

MainModule* EMSCRIPTEN_KEEPALIVE emscripten_bind_MainModule_MainModule_2(char* name, char* birthday) {
  return new MainModule(name, birthday);
}

char* EMSCRIPTEN_KEEPALIVE emscripten_bind_MainModule_getInfo_0(MainModule* self) {
  return self->getInfo();
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_MainModule_shenDebug_1(MainModule* self, int n) {
  return self->shenDebug(n);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_MainModule___destroy___0(MainModule* self) {
  delete self;
}

}

