#include <iostream>
#include <cmath>

using namespace std;


int main() {
  int height = 30;
  double length = 0;
  int angle = 0;
  double pi = 2 * acos(0.0); 
  
  cout <<"Enter angle between 15 - 75: ";
  cin >> angle;
  
  if (angle < 15 || angle > 75){
    cout << "please follow input instruction" << endl;
    return 0;
  }
  
  length = (tan(angle * (pi/ 180.0)));
  
  int l = 0;
  for (int a = 0; a < height; a++){
    //cout << "Length: " <<l<< endl;

    for (int b = 0; b < l; b++){
       cout << "*";
    }
    
    cout << "\n";
    
    if (20 <= floor(a * length) && floor(a * length) <= 30 ){
      l = 20;
    }else{
      l = floor(a * length);
    }
    
  }
}