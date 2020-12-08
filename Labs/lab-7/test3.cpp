#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
  //BigInt first("DADCAFE", 16); // hexadecimal
  //BigInt second("AAABEEF", 16);
	
	BigInt first("DADCAFE", 16); // hexadecimal
  BigInt second("AAABEEF", 17);
	
  try{
    first.add(second);
    cout << first.to_string()<< endl;
  }catch(const char* msg){
    cerr << msg << endl;
  }
  
  
  return 0;
}
