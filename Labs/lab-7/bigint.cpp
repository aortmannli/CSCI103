#include "bigint.h"
#include<iostream>
#include <math.h> 

using namespace std;

BigInt::BigInt(string s, int b){
  num = s;
	base = b;
  if (base < 2 || base > 36){
    throw "Invalid base";
  }
  
  for(int i = 0; i < num.size(); i++){
		if(base > 10 && num[num.size()-i-1] > 64){
			v.push_back(num[num.size()-i-1]-55);
		}else{
			v.push_back(num[num.size()-i-1]-48);
		}
    
  }
  
  
}

string BigInt::to_string(){
  string str;
  
  
  for(int i = 0; i < v.size(); i++){
		if(base > 10 && v[v.size()-i-1] > 9){
			str += char(v[v.size()-i-1] + 55);
		}else{
			str += char(v[v.size()-i-1] + 48);
		}
    
  }
  
  
 
  return str;
}

string BigInt::Decimal(string str, int b){
  string out;
  int len = str.size();
  int p = 1;
  int num = 0;
  
  for(int i = len-1; i >= 0; i--){
    num += (char)str[i] * p;
    p *= b;
  }
  
  for (int i = log(num); i > 0; i--){
    str += char(num/pow(10,i)+ 48);
  }
  
  return str;
}

void BigInt::add(BigInt foo){
  if (base != foo.base){
    throw "Addition is only possible with numbers of the same base.";
  }
  
  bool carry = false;
  
  while(v.size() != foo.v.size()){
    if (v.size() > foo.v.size()){
      foo.v.push_back(0);
    }else{
      v.push_back(0);
    }
  }
  
  
  for(int i = 0; i < v.size(); i++){
    int sum = v[i]+foo.v[i];
    
    if (carry){
      sum++;
      carry = false;
    }
    
    if (sum < base){
      v[i] = sum;
    }else{
      v[i] = sum - base;
      carry = true;
    }
    
    if (carry && i == v.size()-1){
      v.push_back(1);
      break;
    }
  }
}