#include <emscripten.h>
#include "sideModule.h"

#include <string>
//#include "emscripten/emscripten.h"
//#include "emscripten/bind.h"
//#include "emscripten/val.h"

//#include "sideModuleGlue.cpp"

using namespace std;
//using namespace emscripten;

SideModule::SideModule(const char* name, const char* birthday){
  this->name = name;
  this->birthday = birthday;
}
char* SideModule::getInfo(){
  auto strInfo = "sideModule: " + this->name + ", " + this->birthday;
  auto size = strInfo.size();
  auto pszInfo = new char[size+1];
  pszInfo[size] = '\0';
  strcpy(pszInfo, strInfo.c_str());
  return pszInfo;
}
long long SideModule::fb(int n) {
  if(n<1) return 0;
  else if(n==1||n==2) return 1;
  return (fb(n-1)+fb(n-2));
}

extern "C" {
  SideModule* EMSCRIPTEN_KEEPALIVE emscripten_bind_SideModule_SideModule_2(char* name, char* birthday) {
    return new SideModule(name, birthday);
  }
  char* EMSCRIPTEN_KEEPALIVE emscripten_bind_SideModule_getInfo_0(SideModule* self) {
    return self->getInfo();
  }
  long long EMSCRIPTEN_KEEPALIVE emscripten_bind_SideModule_fb_1(SideModule* self, int n) {
    return self->fb(n);
  }
}

//EMSCRIPTEN_BINDINGS(SideModule){
//  class_<SideModule>("SideModule")
//    .constructor<string,string>()
//    .function("getInfo", &SideModule::getInfo);
//}

