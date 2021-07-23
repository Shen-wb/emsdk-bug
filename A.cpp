#include <string>
#include "emscripten/emscripten.h"
#include "emscripten/bind.h"
#include "emscripten/val.h"

using namespace std;
using namespace emscripten;

class A{
public:
  string name;
  string birthday;
  A(string name, string birthday){
    this->name = name;
    this->birthday = birthday;
  }
  string getInfo(){
    return "A: " + this->name + ", " + this->birthday;
  }
};

EMSCRIPTEN_BINDINGS(A){
  class_<A>("A")
    .constructor<string,string>()
    .function("getInfo", &A::getInfo);
}
