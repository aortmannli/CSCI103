#include "bigint.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    BigInt a(100, 10);
    BigInt b(10,10);
    
    cout << a.to_string() << endl;
    cout << b.to_string() << endl;
    
    return 0;
}