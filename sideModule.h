#ifndef __KEILLION_SIDE_MODULE_H__
#define __KEILLION_SIDE_MODULE_H__

#include <string>

//class SideModule;
//{
using namespace std;

class SideModule{
public:
  string name;
  string birthday;
  SideModule(const char* name, const char* birthday);
  char* getInfo();
  long long fb(int n);
};

//}
#endif
