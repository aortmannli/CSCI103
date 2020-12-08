#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

int roll(){
  return (1 + rand() % 6);
}

void printHistogram(int counts[]){
   for(int a = 0; a < 21; a++){
     cout << a+4 << ": " ;
     for(int b = 0; b < counts[a]; b++){
       cout << "X";
     }
     cout << endl;
   }
}

int main() {
  int n;
  int current = 0;
  int sums[21];
  srand((unsigned) time(0));
  
  //populates array
  for(int a = 0; a < 21; a++){
    sums[a] = 0;
  }
  
  cout << "Enter an an intger value for the number of trials: ";
  cin >> n;
  
  //n number of trials
  for(int i = 0; i < n; i++){
    // 4 rolls
    for (int r = 0; r < 4; r++){
      current += roll();
    }
    
    //this isn't necessary but it just checks if the sum 
    // is in the [4,24] range
    if(current < 25 && current > 3){
      sums[current-4]++;
    }else{
      cout << "this is breaking my code:" << current << endl;
    }
    
    //reset current
    current = 0;
  }
  
  //cout << sums;
  printHistogram(sums); 
  
  return 0;
  
  /*
   *tests the roll function
  for(int a = 0; a < 10; a++){
    cout << roll() <<endl;
  } */
 
  /*int testCounts[21]; // 21 options of sum of 4 dice => [4,24]
  for (int i=0; i<21; i++)
    testCounts[i] = i/2; // fill the array
  printHistogram(testCounts); // call your method
  */
}