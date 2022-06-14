# emsdk-cheatlist

Use cmake + [emsdk](https://emscripten.org/index.html) to build multiple wasm in one time.



## Class A

Use [embind](https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html).

Test: `testA.html`




## Class MainModule

[Dynamic link](https://emscripten.org/docs/compiling/Dynamic-Linking.html) sideModule.

Use [webidl](https://emscripten.org/docs/porting/connecting_cpp_and_javascript/WebIDL-Binder.html).

Test: `testMS.html`



## How to Build

```shell
$ ~/emsdk/upstream/emscripten/tools/webidl_binder mainModule.idl mainModuleGlue
$ emcmake cmake .
$ emmake make
``` 

In order to see which system libs are actually needed. [refer](https://emscripten.org/docs/compiling/Dynamic-Linking.html#system-libraries)
```shell
$ emmake make VERBOSE=1
```


## Note

`html` need to be host in an HTTP server. The mimetype of `.wasm` needs to set as `application/wasm`.



## Todo

Test if `char *` in webidl has memory leak.
