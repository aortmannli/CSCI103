#include <iostream>
using namespace std;

int main(){
  int i;
  int ones= 0;
  int tens = 0;
  int hundreds = 0;
  
  cout << "Enter an integer between 0 and 999:";
  // Enter your code here
  cin >> i;
  cout << "\n";
  ones = i % 10;
  tens = (i/10) % 10;
  hundreds = (i/100) % 10;
  
  
  cout << "1's digit is " << ones << endl;
  cout << "10's digit is " << tens << endl;
  cout << "100's digit is: " << hundreds << endl;
 
 
}