#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
   BigInt a("13");
  
  int foo = a.v[0];
  
  cout << foo << endl;
  
  return 0;
}