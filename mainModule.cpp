#include "mainModule.h"

#include <string>
//#include "emscripten/emscripten.h"
//#include "emscripten/bind.h"
//#include "emscripten/val.h"

#include "mainModuleGlu.cpp"

using namespace std;
//using namespace emscripten;

MainModule::MainModule(const char* name, const char* birthday){
  this->name = name;
  this->birthday = birthday;
}
char* MainModule::getInfo(){
  auto sideModuleInstance = new SideModule(name.c_str(), birthday.c_str());
  //auto sideModule2Instance = new SideModuleTwo(name.c_str(), birthday.c_str());
  auto strSideModuleInfo = sideModuleInstance->getInfo();
  //auto strSideModuleInfo2 = sideModule2Instance->getInfo();
  delete sideModuleInstance;
  //delete sideModule2Instance;
  auto strInfo = "mainModule: " + this->name + ", " + this->birthday + "\n" + strSideModuleInfo;
  auto size = strInfo.size();
  auto pszInfo = new char[size+1];
  pszInfo[size] = '\0';
  strcpy(pszInfo, strInfo.c_str());
  return pszInfo;
}

int MainModule::shenDebug(int n) {
  int b = 4;
  if(b == 8 || b == 16) {
    return b;
  }
  else if(b == 2){
    emscripten_log(EM_LOG_CONSOLE, "number: %d", b);
    return b;
  }
  return 0;
}

//EMSCRIPTEN_BINDINGS(MainModule){
//  class_<MainModule>("MainModule")
//    .constructor<string,string>()
//    .function("getInfo", &MainModule::getInfo);
//}

