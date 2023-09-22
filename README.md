build =>

../emsdk/upstream/emscripten/tools/webidl_binder mainModule.idl mainModuleGlu

emcmake cmake .

emmake make

open liveSever => testMS.html
