cmake_minimum_required(VERSION 3.10)

# set the project name
project(A VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# maybe usefull option for compile and link
# -s ALLOW_TABLE_GROWTH
# -fPIC
# -s DISABLE_EXCEPTION_CATCHING=0
# -msimd128
# -fexceptions
# -s EXCEPTION_CATCHING_ALLOWED
#  -fno-PIC

# set compile options
add_compile_options(-Oz --bind -mnontrapping-fptoint)

# set link options
#add_link_options(-Oz) # require cmake >= 3.13
set(CMAKE_EXE_LINKER_FLAGS "-Oz --bind -mnontrapping-fptoint -s ALLOW_TABLE_GROWTH ${CMAKE_EXE_LINKER_FLAGS}")

# add the executable for A
add_executable(A A.cpp)

target_include_directories(A PUBLIC
  "/home/keillion/emsdk/upstream/emscripten/system/include"
)

# https://github.com/emscripten-core/emscripten/wiki/Linking

# add the executable for mainModule
add_executable(mainModule mainModule.cpp)

target_include_directories(mainModule PUBLIC
  "/home/keillion/emsdk/upstream/emscripten/system/include"
)

set_target_properties(mainModule PROPERTIES COMPILE_FLAGS " -s MAIN_MODULE=1 -fPIC -s ERROR_ON_UNDEFINED_SYMBOLS=0" LINK_FLAGS " -s MAIN_MODULE=1 -fPIC -s ERROR_ON_UNDEFINED_SYMBOLS=0 --post-js mainModuleGlue.js")

# add the executable for sideModule
add_executable(sideModule sideModule.cpp)

target_include_directories(sideModule PUBLIC
  "/home/keillion/emsdk/upstream/emscripten/system/include"
)

set_target_properties(sideModule PROPERTIES COMPILE_FLAGS " -s SIDE_MODULE=1 -fPIC -s EXPORT_ALL=1" LINK_FLAGS " -s SIDE_MODULE=1 -fPIC -s EXPORT_ALL=1" SUFFIX ".wasm")
