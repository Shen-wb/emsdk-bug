#ifndef __KEILLION_SIDE_MODULE_TWO_H__
#define __KEILLION_SIDE_MODULE_TWO_H__

#include <string>

using namespace std;

class SideModuleTwo{
public:
  string name;
  string birthday;
  SideModuleTwo(const char* name, const char* birthday);
  char* getInfo();
  const char* generateRandomString(int len);
};

//}
#endif
