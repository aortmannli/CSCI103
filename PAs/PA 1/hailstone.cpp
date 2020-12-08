#include <iostream>
#include <cmath>
using namespace std;

int main(){

  int length = 0;
  int num;

  cout << "Enter a number:" ;
  cin >> num;
  cout << endl;

  while (num != 1){
    if (num % 2 == 0){
      num /= 2;
      cout << num << " ";
    }else{
      num = num*3 +1;
      cout << num << " ";
    }
    length++;
  }

  cout << endl;
  cout << "Length: " << length << endl;
  
}