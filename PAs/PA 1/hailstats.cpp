#include <iostream>
#include <cmath>
using namespace std;

int find_length(int num){
  int length = 0;
  while (num != 1){
    if (num % 2 == 0){
      num /= 2;
      //cout << num << " ";
    }else{
      num = num*3 +1;
      //cout << num << " ";
    }
    length++;
  }
  return length;
}

int main(){
  int start;
  int end;
  int min_l = -1;
  int max_l = -1;
  int min_n;
  int max_n;
  
  cout << "Enter the range that you want to search: ";
  cin >> start >> end;
  cout << endl;
  
  if( start <= end ){
    for(int i = start; i < end+1; i++){
      int len = find_length(i); 
      if (min_l == -1 || len < min_l){
        min_l = len;
        min_n = i;
      }
      if (len > max_l){
        max_l = len;
        max_n = i;
      }
    }
  }else{
    cout << "Invalid range";
    return 0;
  }
  
  cout << "Minimum length: " << min_l << endl;
  cout << "Achieved by: " << min_n << endl;
  cout << "Maximum length: " << max_l << endl;
  cout << "Achieved by: " << max_n << endl;
  
}