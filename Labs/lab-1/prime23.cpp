#include <iostream>
using namespace std;

int whatPowerOf(int n,int b){
  // this function will return the degree by which n is a power of b
  int degree = 0;
    if (n > 1){
       while (n % b == 0){
          degree++;
          n /= b;
       }
    }
  //just keep dividing until 0th power
  if (n == 1){
    return degree;
  }
  //-1 here acts like a false boolean
  return -1;
}

int main(){
  int i;
  int Twos = 0;
  int Threes = 0;
  
  cout << "Enter a positive integer: ";
  cin >> i;
  
  // checks if i is a power of 2 or 3
  if (i%2 == 0 || i%3 == 0){
    if (whatPowerOf(i,2) != -1){
      Twos = whatPowerOf(i,2);
    }
    if (whatPowerOf(i,3) != -1){
      Threes = whatPowerOf(i,3);
    } 
  }
  if(i%2 == 0 && i%3 == 0){
    int n = i;
    int dva = 0;
    while (n%2 == 0){ 
      n = n/2; 
      dva++;
    } 
    
    if (whatPowerOf(int(n),3) != -1){
      Threes = whatPowerOf(n,3);
      Twos = dva;
    } 
  }

  
  if (Twos == 0 && Threes == 0){
    cout << "No"<< endl;
  }else{
    cout << "Yes \n";
    cout << "Twos=" << Twos << " Threes=" << Threes << endl;
  }
  
  return 0;
}


