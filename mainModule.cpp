#include "mainModule.h"

#include <string>
//#include "emscripten/emscripten.h"
//#include "emscripten/bind.h"
//#include "emscripten/val.h"

#include "mainModuleGlue.cpp"

using namespace std;
//using namespace emscripten;

MainModule::MainModule(const char* name, const char* birthday){
  this->name = name;
  this->birthday = birthday;
}
char* MainModule::getInfo(){
  auto sideModuleInstance = new SideModule(name.c_str(), birthday.c_str());
  auto sideModule2Instance = new SideModuleTwo(name.c_str(), birthday.c_str());
  auto strSideModuleInfo = sideModuleInstance->getInfo();
  auto strSideModuleInfo2 = sideModule2Instance->getInfo();
  delete sideModuleInstance;
  delete sideModule2Instance;
  auto strInfo = "mainModule: " + this->name + ", " + this->birthday + "\n" + strSideModuleInfo + "\n" + strSideModuleInfo2;
  auto size = strInfo.size();
  auto pszInfo = new char[size+1];
  pszInfo[size] = '\0';
  strcpy(pszInfo, strInfo.c_str());
  return pszInfo;
}

//EMSCRIPTEN_BINDINGS(MainModule){
//  class_<MainModule>("MainModule")
//    .constructor<string,string>()
//    .function("getInfo", &MainModule::getInfo);
//}

