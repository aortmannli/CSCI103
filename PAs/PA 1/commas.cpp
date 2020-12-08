/********************************************************
 * CS 103 PA 1: Commas
 * Name:
 * USC email:
 * Comments (you want us to know):
 *
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 *
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int digits = 0;
int counter = 1;
int print_digs(long long a){
  if (a < 10){
    cout << a;
  }else{
    print_digs(a/10);
    cout << a%10;
    counter++;
    if(counter%3 == 0 && counter < digits-1){
      cout << ",";
    }
  }
}

int print_even(long long digs, long long a){
  long long hold1 = a;
  long long power = 0;
  
  for (int d = 0; d < digs; d++){
      if ((d+1)% 3 != 0 || d == 0){
        power = pow(10,digs-(d+1));
        hold1 = a/power;
        cout << (hold1%10);
      }else if (d != (digs-1)){
        power = pow(10,digs-(d+1));
        hold1 = a/power;
        cout << (hold1%10);
        cout << ",";
      }else{
        cout << (a%10);
        
      } 
   }
  return 0;
}

int main(){
  int64_t n;
  cout << "Enter an integer:" << endl;

  /* Your code here */
  cin >> n;
  
  if (n < 0){
    cout << "-";
  }
  n = abs(n);
  
  digits = log10(n)+1;
  long long hold = n;

  if (digits % 3 != 0 && n != 0){
    for(int i = 0; i < digits % 3; i++){
      hold = n/(pow(10,digits-(i+1)));
      cout << (hold%10);
    }
    
    if (digits > (digits % 3)){
      cout << ",";
    }
  }else if (n == 0){
    cout << 0 ;
  } 
   
  print_even(digits - (digits % 3), n);
  
  //print_digs(n);
  cout << endl;


  /* End of your code */
  return 0;
}
