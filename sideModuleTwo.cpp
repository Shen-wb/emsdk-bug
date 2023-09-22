#include <string>
#include <cstdlib>
#include <ctime>
#include <string>

#include <emscripten.h>
#include "sideModuleTwo.h"

using namespace std;

SideModuleTwo::SideModuleTwo(const char* name, const char* birthday){
  this->name = name;
  this->birthday = birthday;
}
char* SideModuleTwo::getInfo(){
  auto strInfo = "SideModuleTwo: " + this->name + ", " + this->birthday;
  auto size = strInfo.size();
  auto pszInfo = new char[size+1];
  pszInfo[size] = '\0';
  strcpy(pszInfo, strInfo.c_str());
  return pszInfo;
}
const char* SideModuleTwo::generateRandomString(int len) {
    const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
    srand(time(nullptr));
    for(int i=0;i<len;i++){
      result += alphabet[rand() % alphabet.length()];
    }
    auto pszRes = new char[result.size()+1];
    pszRes[result.size()] = '\0';
    strcpy(pszRes, result.c_str());
    return pszRes;
}

extern "C" {
  SideModuleTwo* EMSCRIPTEN_KEEPALIVE emscripten_bind_SideModuleTwo_SideModule_2(char* name, char* birthday) {
    return new SideModuleTwo(name, birthday);
  }
  char* EMSCRIPTEN_KEEPALIVE emscripten_bind_SideModuleTwo_getInfo_0(SideModuleTwo* self) {
    return self->getInfo();
  }
  const char* EMSCRIPTEN_KEEPALIVE emscripten_bind_SideModuleTwo_generateRandomString_1(SideModuleTwo* self,  int len) {
    return self->generateRandomString(len);
  }
}