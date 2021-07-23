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

//EMSCRIPTEN_BINDINGS(SideModule){
//  class_<SideModule>("SideModule")
//    .constructor<string,string>()
//    .function("getInfo", &SideModule::getInfo);
//}

