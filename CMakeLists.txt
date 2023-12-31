cmake_minimum_required(VERSION 3.10)

# set the project name
project(A VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EM_BUILD_VERBOSE 1)
set(CMAKE_VERBOSE_MAKEFILE 1)
set(VERBOSE 1)

# maybe usefull option for compile and link
# -s ALLOW_TABLE_GROWTH
# -fPIC
# -s DISABLE_EXCEPTION_CATCHING=1
# -s EXCEPTION_CATCHING_ALLOWED=[]
# -msimd128
# -fexceptions
# -fno-PIC
# -s ALLOW_MEMORY_GROWTH=1
# --no-entry
# --closure 1

# set compile options
# when use multiple "-s" in old cmake: https://gitlab.kitware.com/cmake/cmake/-/issues/15826
# or you can use set_target_properties instead
# -mnontrapping-fptoint # safari in ios not support it
add_compile_options(-Oz -sDISABLE_EXCEPTION_CATCHING=1 -sASSERTIONS=1 -flto -fPIC -DDM_CONSOLE_LOG=1
  -DWASM -DCPU_ONLY -DDBR_ALL_IN_ONE -D__linux__ -D__WASM__ -D__WASM__Full__FEATURE__ -D__WASM_NO_EXECPTION__
  -Wno-deprecated-declarations
  -Wno-unused-value
  -Wno-parentheses
  -Wno-switch
  -Wno-return-type
  -Wno-enum-compare-switch
  -Wno-delete-incomplete
  -Wno-tautological-constant-out-of-range-compare
  -Wno-invalid-source-encoding
  -Wno-writable-strings
  -Wno-format
  -Wno-extra-tokens
  -Wno-missing-declarations
  -Wno-comment
  -Wno-enum-compare
  -Wno-macro-redefined
  -Wno-implicit-const-int-float-conversion
  -Wno-inconsistent-missing-override
  -Wno-uninitialized
  -Wno-ignored-attributes
  -Wno-unused-command-line-argument
)

# set link options
#add_link_options(-Oz) # require cmake >= 3.13
# -mnontrapping-fptoint # safari in ios not support it
set(CMAKE_EXE_LINKER_FLAGS "--bind -s DISABLE_EXCEPTION_CATCHING=1 ${CMAKE_EXE_LINKER_FLAGS} -flto")

# add the executable for A
# add_executable(A A.cpp)

# target_include_directories(A PUBLIC
# "/home/keillion/emsdk/upstream/emscripten/system/include"
# )

# https://emscripten.org/docs/compiling/Dynamic-Linking.html

# add the executable for mainModule
add_executable(mainModule mainModule.cpp)

target_include_directories(mainModule PUBLIC
  "/home/ubuntu/Desktop/dynamic_linking/emsdk-cheatlist/"
)

set_target_properties(mainModule PROPERTIES COMPILE_FLAGS " -s MAIN_MODULE=2 -fPIC -s ERROR_ON_UNDEFINED_SYMBOLS=0" LINK_FLAGS " -s MAIN_MODULE=1 -fPIC -s ERROR_ON_UNDEFINED_SYMBOLS=0 --post-js mainModuleGlu.js")

# add the executable for sideModule
add_executable(sideModule sideModule.cpp)

target_include_directories(sideModule PUBLIC
  "/home/ubuntu/Desktop/dynamic_linking/emsdk-cheatlist/"
)

# use -v to get more info about `including lib[...]` messages
set_target_properties(sideModule PROPERTIES COMPILE_FLAGS " -v -s SIDE_MODULE=2 -fPIC -s EXPORT_ALL=1" LINK_FLAGS " -v -s SIDE_MODULE=1 -fPIC -s EXPORT_ALL=1" SUFFIX ".wasm")

# add the executable for sideModule
# add_executable(sideModuleTwo sideModuleTwo.cpp)

#target_include_directories(sideModuleTwo PUBLIC
# "/home/ubuntu/Desktop/dynamic_linking/emsdk-cheatlist/"
#)

# use -v to get more info about `including lib[...]` messages
# set_target_properties(sideModuleTwo PROPERTIES COMPILE_FLAGS " -v -s SIDE_MODULE=2 -fPIC -s EXPORT_ALL=1" LINK_FLAGS " -v -s SIDE_MODULE=2 -fPIC -s EXPORT_ALL=1" SUFFIX ".wasm")
