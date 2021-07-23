#ifndef __KEILLION_MAIN_MODULE_H__
#define __KEILLION_MAIN_MODULE_H__

#include <string>
#include "sideModule.h"

//class MainModule;
//{
using namespace std;

class MainModule{
public:
  string name;
  string birthday;
  MainModule(const char* name, const char* birthday);
  char* getInfo();
};

//}
#endif
