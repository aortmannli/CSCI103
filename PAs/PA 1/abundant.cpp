/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name: Angel Li
 * USC email: liangeli@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <cmath>
#include <iostream>
using namespace std;

int ab_sum(int a){
  int sum = 0; 
    
  for(int i = 1; i<= sqrt(a); i++){
    if (a%i == 0){
      if (a/i == i){
        sum += i;
      }else{
        sum += i;
        sum += a/i;
      }
    }
  }
  sum -= a;
  return sum;
}

bool isAbundant(int a){
  return ab_sum(a)>a;
}


int main(){
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /* Your code here */
  
  int n;
  cin >> n;
  
  //because the 0 signifies end of list its the while breaker
  while(n != 0){
    //declaring abundancy variable
    int ab = 0;
    
    //if the input num is abundant potentially do reassignment of top nums
    if (isAbundant(n)){
      num_abundant++;
      //defining ab for this n
      ab = ab_sum(n);
      
      //cout << n << "'s abundancy is " << ab << endl;
      //ressignment of top values
      if (ab_sum(n) > a3){
        if (ab_sum(n) > a2){
          if (ab_sum(n) > a1){
            a3 = a2;
            n3 = n2;
            a2 = a1;
            n2=  n1;
            a1 = ab;
            n1 = n;
          }else{
            a3 = a2;
            n3 = n2;
            a2 = ab;
            n2 = n;
          }
        }else{
          n3 = n;
          a3 = ab;
        }
      }
    }
    
    //taking in next input
    cin >> n;
  }
  
  
    
  /* End of your code */
  
  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
