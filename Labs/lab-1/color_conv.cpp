/* Author: YOUR NAME HERE
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int r = 0;
  int g = 0;
  int b = 0;
 
  cout << "Enter 3 integers (red, green, and blue), in that order:";
  // Enter your code here
  cin >> r>> g>> b; 
 
  double red = r/255.00;
  double green = g/255.00;
  double blue = b/255.00;
  
  double white = max(max(red,green),blue);
  double cyan = (white - red)/ white;
  double magenta = (white - green)/ white;
  double yellow = (white - blue)/ white;
  double black = 1 - white;
  
  cout << "cyan: " << cyan << endl;
  cout << "magenta: " << magenta << endl;
  cout << "yellow: " << yellow << endl;
  cout << "black: " << black << endl;
   
   return 0;
}