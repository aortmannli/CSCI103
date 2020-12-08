#include "bigint.h"
#include <iostream>
#include <string>
#include <climits>
#include <bits/stdc++.h> 
using namespace std;

/*
//   Create a default BigInt with base 10.
*/
BigInt::BigInt(){
    base = 10;
    isPositive = true;
    vec.push_back(0);
}

/*
//  Create a BigInt with a specified base.
*/
BigInt::BigInt(int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    
    base = setbase;
    isPositive = true;
    vec.push_back(0);
}

/*
//  Create a BigInt from int (base 10) with a specified base.
//  Here you would convert an int (base 10) into a specified base.
//  e.g., (10,2) <-- 10 base 10 to base 2 --> result:  BigInt with value 1010 base 2
//  e.g., (100,16) <--- 100 base 10 to base 16 --> result: BigInt with value 64 base 16
*/
BigInt::BigInt(int input,int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    
    base = setbase;
    isPositive = (input >= 0);
    if(!isPositive){
        input *= -1;
    }
    
    string num;
    
    if (input == 0){
        num = "0";
    }
    
    if(base != 10 && input != 0){  
        int i = 0; 
        char res[100];
  
        while (input > 0){
            if(input % base >= 0 && input%base <= 9){
                res[i++]  = (char)((input%base) + 48);
            }else{
                res[i++]  = (char)((input%base) +55);
            }
            input /= base; 
        } 
        res[i] = '\0'; 

        num = res;
        reverse(num.begin(),num.end());
        
    }else{
        num = std::to_string(input);
    }
    
    
    
    for(unsigned int i = 0; i < num.size(); i++){
        if(base > 10 && num[num.size()-i-1] > 64){
            vec.push_back(num[num.size()-i-1]-55);
        }else{
            vec.push_back(num[num.size()-i-1]-48);
        }
    }
    
} //idt this works

/*
//  Create a BigInt from string with a specified base.
//  You can assume that the string number input is in the same
//      base as the setbase input.
*/
BigInt::BigInt(const string &s, int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    string num = s;
    
    if (s[0] == '-'){
        isPositive = false;
        for(unsigned int i = 1; i < num.size(); i++){
            if(base > 10 && num[num.size()-i] > 64){
                vec.push_back(num[num.size()-i]-55);
            }else{
                vec.push_back(num[num.size()-i]-48);
            }
            
        }
        
    }else{
        isPositive = true;
        for(unsigned int i = 0; i < num.size(); i++){
            if(base > 10 && num[num.size()-i-1] > 64){
                vec.push_back(num[num.size()-i-1]-55);
            }else{
                vec.push_back(num[num.size()-i-1]-48);
            }
        }
    }
    
}

/*
//  Create a BigInt from another BigInt.
//  This is a copy constructor.
//  Simply use the assignment operator.
*/
BigInt::BigInt(const BigInt &b){
    base = b.base;
    isPositive = b.isPositive;
    vec = b.vec;
}

/*
// Destructure. You do not have to add anything.
// This function is complete
*/
BigInt::~BigInt(){}



/*
// Convert to string and return the string
//  Display it in its corresponding base
*/
string BigInt::to_string(){

    /************* You complete *************/
    string str;
    
    if (!isPositive){
        str.push_back('-');
    }
    
    for(unsigned int i = 0; i < vec.size(); i++){
        if(base > 10 && vec[vec.size()-i-1] > 9){
            str += char(vec[vec.size()-i-1] + 55);
        }else{
            str += char(vec[vec.size()-i-1] + 48);
        }

    }
    
    return str;
}

/*
//  Convert BigInt to integer base 10 and return that int
//    If BigInt > INT_MAX, return INT_MAX.
//    If BigInt < INT_MIN, return INT_MIN.
*/
int BigInt::to_int() const{
    /************* You complete *************/
    
    unsigned int result = 0;
    unsigned int intMax= 2147483647;
    
    
    int size = vec.size();
    
    for(unsigned int i = 1; i <= vec.size(); i++){
        result = result * base + vec[size-i];
    }
    
    
    if (result > intMax){
        result = intMax;
    }
    
    int out = (int)result;
    
    if (!isPositive){
        if(result == intMax){
            out++;
        }
        out *= -1;
    }
    
    
    return out;
}

/*
//  Compare a and b.
//     If a = b, return 0.
//     If a < b, return -1.
//     If a > b, return 1.
*/
int BigInt::compare(const BigInt &b) const{
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    
    //if a is pos and b is neg
    if (isPositive && !b.isPositive){
        return 1;
    }else if (!isPositive && b.isPositive){
        //if b is positive and a is negative
        return -1;
    }
    
    //if both numbers are positive, you can compare sizes
    if (isPositive && b.isPositive){
        if (vec.size() > b.vec.size()){
            return 1;
        }else if (vec.size() < b.vec.size()){
            return -1;
        }else{
            for(int i = vec.size()-1; i >= 0; i--){
                if (vec[i] > b.vec[i]){
                    return 1;
                }else if (vec[i] < b.vec[i]){
                    return -1;
                }
            }
        }
        
        
    }
    
    //if both numbers are negative, you can compare sizes
    if(!isPositive && !b.isPositive){
        if (vec.size() > b.vec.size()){
            return -1;
        }else if (vec.size() < b.vec.size()){
            return 1;
        }
        // if they are equal lengths
        for(int i = vec.size()-1; i >= 0; i--){
            
            if (vec[i] > b.vec[i]){
                return -1;
            }else if (vec[i] < b.vec[i]){
                return 1;
            }
            
        }
        
    
    }
    
    return 0;

}



/*
//  Assignment operator. (i.e., BigInt a = b;)
*/
const BigInt & BigInt::operator = (const BigInt &b){
  base = b.base;
  vec = b.vec;
  isPositive = b.isPositive;
    
  return *this;
}

/*
//  Addition assignment operator.
//    - Compute a = a + b.
*/
const BigInt & BigInt::operator += (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    
    unsigned int len = max(b.vec.size(),vec.size());
    vector<int> temp(len);
    bool pos = true;
    bool carry = false;
    
    if ((isPositive && b.isPositive)){
       //if they'r eboth positive then just add like normal
        for(unsigned int i = 0; i < len; i++){
            int sum;
            if (i >= b.vec.size()){
                sum = vec[i]+0;
            }else if (i >= vec.size()){
                sum = 0+b.vec[i];
            }else{
                sum = vec[i]+b.vec[i];
            }

            if (carry){
              sum++;
              carry = false;
            }

            if (sum < base){
              temp[i] = sum;
            }else{
              temp[i] = sum - base;
              carry = true;
            }

            if (carry && i == len-1){
              temp.push_back(1);
              break;
            }
        }
        
    }
    else if(isPositive || b.isPositive){
        bool isALarger = false;
        if(!isPositive){
            isPositive = true;
            isALarger = this->compare(b) > 0;
            isPositive = false;
        }else{
            isPositive = false;
            isALarger = this->compare(b) < 0;
            isPositive = true;
        }
        
        //if a is the larger one then u do a-b
        if (isALarger){
            
            for (unsigned int i = 0 ; i < vec.size(); i++){
                int diff;
                if (i >= b.vec.size()){
                    diff = vec[i]-0;
                }else{
                    diff = vec[i]-b.vec[i];
                }
                
                if(carry){
                    diff--;
                    carry = false;
                }
                
                if(diff < 0){
                    temp[i] = diff + base;
                    carry = true;
                }else{
                    temp[i] = diff;
                }  
            }
            
            pos = isPositive;
        }else if (!isALarger){
            for (unsigned int i = 0 ; i < b.vec.size(); i++){
                int diff;
                if (i >= vec.size()){
                    diff = b.vec[i]-0;
                }else{
                    diff = b.vec[i]-vec[i];
                }
                
                if(carry){
                    diff--;
                    carry = false;
                }
                
                if(diff < 0){
                    temp[i] = diff + base;
                    carry = true;
                }else{
                    temp[i] = diff;
                }
            }
            
            pos = b.isPositive;
        }
            
    }
    else{
        for(unsigned int i = 0; i < len; i++){
            int sum;
            if (i >= b.vec.size()){
                sum = vec[i]+0;
            }else if (i >= vec.size()){
                sum = 0+b.vec[i];
            }else{
                sum = vec[i]+b.vec[i];
            }

            if (carry){
              sum++;
              carry = false;
            }

            if (sum < base){
              temp[i] = sum;
            }else{
              temp[i] = sum - base;
              carry = true;
            }

            if (carry && i == len-1){
              temp.push_back(1);
              break;
            }
        }
        pos = isPositive;
    }
    
    
    
    bool allEqual = std::equal(temp.begin() + 1, temp.end(), temp.begin()); 
    if(allEqual && temp[0] == 0){
        while(temp.size() != 1){
            temp.pop_back();
        }
        pos = true;
    }
    while(temp.back() == 0 && temp.size() >1){
        temp.pop_back();
    }
    vec = temp;
    isPositive = pos;
    return *this;
}


/*
//  Subtraction assignment operator.
//    - Compute a = a - b
*/
const BigInt & BigInt::operator -= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    
    unsigned int len = max(b.vec.size(),vec.size());
    vector<int> temp(len);
    bool pos = true;
    bool carry = false;
   
    //if they are both negative then its basically -(A+B)
    if(!isPositive && b.isPositive){
        for(unsigned int i = 0; i < len; i++){
            int sum;
            if (i >= b.vec.size()){
                sum = vec[i]+0;
            }else if (i >= vec.size()){
                sum = 0+b.vec[i];
            }else{
                sum = vec[i]+b.vec[i];
            }

            if (carry){
              sum++;
              carry = false;
            }

            if (sum < base){
              temp[i] = sum;
            }else{
              temp[i] = sum - base;
              carry = true;
            }

            if (carry && i == len-1){
              temp.push_back(1);
              break;
            }
        }
        
        pos = false;
    }
    
    //if A is pos and B is neg then its (A+B)
    if(isPositive && !b.isPositive){
        for(unsigned int i = 0; i < len; i++){
            int sum;
            if (i >= b.vec.size()){
                sum = vec[i]+0;
            }else if (i >= vec.size()){
                sum = 0+b.vec[i];
            }else{
                sum = vec[i]+b.vec[i];
            }

            if (carry){
              sum++;
              carry = false;
            }

            if (sum < base){
              temp[i] = sum;
            }else{
              temp[i] = sum - base;
              carry = true;
            }

            if (carry && i == len-1){
              temp.push_back(1);
              break;
            }
        }
        pos = true;
    }
    
    //if A and B are both positive its A + (-B)
    if((isPositive && b.isPositive) || (!isPositive && !b.isPositive)){
        bool isALarger = false;
        if(isPositive){
            isALarger = this->compare(b) > 0;
        }else{
            isALarger = this->compare(b) < 0;
        }
        
        //if a is the larger one then u do a-b
        if (isALarger){
            for (unsigned int i = 0 ; i < vec.size(); i++){
                int diff;
                if (i >= b.vec.size()){
                    diff = vec[i]-0;
                }else{
                    diff = vec[i]-b.vec[i];
                }
                
                if(carry){
                    diff--;
                    carry = false;
                }
                
                if(diff < 0){
                    temp[i] = diff + base;
                    carry = true;
                }else{
                    temp[i] = diff;
                }  
            }
            if (isPositive && b.isPositive){
                pos = true;
            }else{
                pos = false;
            }
            //pos = isPositive;
            
        }else if (!isALarger){
            for (unsigned int i = 0 ; i < b.vec.size(); i++){
                int diff;
                if (i >= vec.size()){
                    diff = b.vec[i]-0;
                }else{
                    diff = b.vec[i]-vec[i];
                }
                
                if(carry){
                    diff--;
                    carry = false;
                }
                
                if(diff < 0){
                    temp[i] = diff + base;
                    carry = true;
                }else{
                    temp[i] = diff;
                }
            }
            if (isPositive && b.isPositive){
                pos = true;
            }else{
                pos = false;
            }
            if (isPositive && b.isPositive){
                pos = false;
            }else{
                pos = true;
            }
            //pos = b.isPositive;
        }else{
            for(unsigned int i = 0; i < len; i++){
                int sum;
                if (i >= b.vec.size()){
                    sum = vec[i]+0;
                }else if (i >= vec.size()){
                    sum = 0+b.vec[i];
                }else{
                    sum = vec[i]+b.vec[i];
                }

                if (carry){
                  sum++;
                  carry = false;
                }

                if (sum < base){
                  temp[i] = sum;
                }else{
                  temp[i] = sum - base;
                  carry = true;
                }

                if (carry && i == len-1){
                  temp.push_back(1);
                  break;
                }
            }
            
            pos = isPositive;
        }
    }

    bool allEqual = std::equal(temp.begin() + 1, temp.end(), temp.begin()); 
    if(allEqual && temp[0] == 0){
        while(temp.size() != 1){
            temp.pop_back();
        }
        pos = true;
    }
    while(temp.back() == 0 && temp.size() >1){
        temp.pop_back();
    }
    vec = temp;
    isPositive = pos;
    return *this;
}

/*
//  Multiplication assignment operator.
//    - Compute a = a * b;
*/
const BigInt & BigInt::operator *= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    BigInt out(base);
    int carry = 0;
    int prod = 0;
    int blen = b.vec.size();
    int alen = vec.size();
    bool pos = ((isPositive && b.isPositive) || (!isPositive && !b.isPositive));
    
    for(int i =0 ; i < blen; i++){
        string buffer(i, '0');
        BigInt temp(buffer, base);
        
        for(int j = 0; j < alen; j++){
            prod = b.vec[i] * vec[j];
            
            
            if(carry > 0){
                prod += carry;
            }
            
            if(prod >= base){
                carry = (prod/base);
                prod -= (base*carry);
            }else{
                carry = 0;
            }
            
            
            temp.vec.push_back(prod);
            
            
            if (carry > 0 && j == alen-1){
              if (carry > base){
                  temp.vec.push_back(carry-base+1);
                  
              }else{
                  temp.vec.push_back(carry);
              }
              
              break;
            }
            
        }
        
        out += temp;
        carry = 0;
    }
    
    out.isPositive=pos;
    if(out.vec.size() == 1 && out.vec[0] == 0){
        out.isPositive = true;
    }
    *this = out;
    return *this;
}

/*
//  Division assignment operator.
//    - Call 'divisionMain' to compute a = a / b;
*/
const BigInt & BigInt::operator /= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/
    
    BigInt q(base);
    BigInt r(base);

    divisionMain(b, q, r);

    *this = q;
    return *this;
}
/*
//  Modulus assignment operator.
//    - Call 'divisionMain' to compute a = a % b.
//    - Note: remainder takes the sign of the dividend.
*/
const BigInt & BigInt::operator %= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/
    
    BigInt q(base);
    BigInt r(base);

    divisionMain(b, q, r);
    
    if(r.vec.size() ==1 && r.vec[0] == 0){
        r.isPositive = true;
    }
    
    *this = r;
    return *this;
}

/*
//  Main function for the Division and Modulus operator.
//     - Compute (q)uotient and (r)emainder: a = (b * q) + r.
//     - Note: NO fraction. This should behave like integer division
//             where 2/10 = 0, not 0.2
*/
void BigInt::divisionMain(const BigInt &b, BigInt &quotient, BigInt &remainder){

    /************* You complete *************/
    
    bool pos = ((isPositive && b.isPositive) || (!isPositive && !b.isPositive));
    bool rempos = isPositive;
    //checking if dividing by 1 or -1
    if(b.vec.size() == 1 && b.vec[0] == 1){
        if(!b.isPositive){
            isPositive = !isPositive;
        }
        
        quotient.vec = vec;
        quotient.isPositive = pos;
        return;
    }
    
    BigInt den(b);    //copy of b
    den.isPositive = true;
    isPositive = true;
    
    //checking if left is less than right
    //remainder with then be self
    vector<int> result; //final vector
    if(*this < den){
        remainder.vec = vec;
        remainder.isPositive = rempos;
        return;
    }else if (compare(den) == 0){
        
        quotient.vec[0] = 1;
        quotient.isPositive = pos;
        return;
    }
    
    
    BigInt dividend(base);
    dividend.vec.pop_back();
    
    for(unsigned int i = 0 ; i < den.vec.size(); i++){
        dividend.vec.push_back(vec.back());
        vec.pop_back();
    }
    
    vector<int> temp = vec;
    std::reverse(temp.begin(), temp.end());
    
    for(unsigned int i = 0; i <= vec.size(); i++){
        int count = 0;
        std::reverse(dividend.vec.begin(), dividend.vec.end());
        if(dividend.compare(den) > 0){
            
            //cout << dividend.to_string() << " / "  << den.to_string() << endl;
             
            while(dividend > den){
                dividend -= den;
                count ++;
                //cout << dividend.to_string() << " " <<count <<   endl;
            }
            
            if(dividend == den){
                dividend -= dividend;
                count++;
                
            }
            
            if(count < base){
                 result.push_back(count);
            }
            
            
        }else if(dividend.compare(den) == 0){
            dividend -= dividend;
            dividend.vec.pop_back();
            result.push_back(1);
            
            
        }else if(i != 0){
            
            result.push_back(0);
        }
        std::reverse(dividend.vec.begin(), dividend.vec.end());
        
        if (i < vec.size()){
            std::reverse(dividend.vec.begin(), dividend.vec.end());
            while(dividend.vec.size() > 0 && dividend.vec.back()== 0){
                //cout << "this is the zero man " << dividend.to_string() << endl;
                dividend.vec.pop_back();
            }
            std::reverse(dividend.vec.begin(), dividend.vec.end());
            
            dividend.vec.push_back(temp[i]); 
            
        }
        
        
        
    }
  
  //cout << dividend.to_string() << endl;
  std::reverse(result.begin(), result.end());
  std::reverse(dividend.vec.begin(), dividend.vec.end());
  while(result.size() > 0 && result.back() == 0){
      result.pop_back();
  }
    
  
  if(vec.size() == 1 && vec[0] == 0){
      isPositive = true;
  }
    
  quotient.isPositive = pos;
  quotient.vec = result;
  remainder = dividend;
  remainder.isPositive = rempos;
}

/*
//  Exponentiation assignment function.
//     - Compute a BigInt whose value is a = pow(a,b).
*/
const BigInt & BigInt::exponentiation(const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
    
    unsigned int power = 0;
    unsigned int size = b.vec.size();
    
    for(unsigned int i = 1; i <= size; i++){
        power = power * base + b.vec[size-i];
    }
  
    //handling base cases like base = 1 or 0
    if(vec.size() == 1){
        if(vec[0] == 1){ 
            if (!isPositive && power% 2 == 0){
                isPositive = true;
            }
            
            return *this;
        }else if(vec[0] == 0){
            if (power == 0){
                vec[0] = 1;
                return *this;
            }
            return *this;
        }
    }
    
    //checks if pow is 1, pow = 0 automatically handled
    if (power == 1){
        return *this;
    }
   
    
    BigInt result(1,base);
    BigInt ebase(*this);
    
    while(power > 0){
        if(power % 2 == 1){
            result *= ebase;
        }
        
        ebase *= ebase;
        
        power /= 2;
    }
    
 
  *this = result;
  
  return *this;
}

/*
//  Modulus Exponentiation assignment function.
//     - Compute a = (a ^ b) % m.
//     - Do NOT compute a^b directly and then % m. 
//         This is too computationally expensive.
*/
const BigInt & BigInt::modulusExp(const BigInt &b, const BigInt &m){
    if(base != b.base || base != m.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/

    BigInt result(1,base);
    BigInt ebase(*this);
    
    BigInt mod(m);
    
    
    unsigned long long int power = 0;
    
    unsigned int size = b.vec.size();
    
    
    for(unsigned int i = 1; i <= size; i++){
        power = power * base + b.vec[size-i];
    }
    unsigned long long int max = 1586926376031962872;
    if (power > max){
        BigInt temp(b);
        
        BigInt zero(0,base);
        BigInt one(1,base);
        BigInt two(2,base);
        
        while(temp > zero){
            if(temp % two == one){
                result *= ebase;
                result %= mod;
            }

            ebase *= ebase;
            ebase %= mod;

            temp /= two;
        
        }
        
        *this = result;
        return *this;
    }
    
    int i = 0;
    //cout << i << " result: " << result.to_string();
    //cout << " base: " << ebase.to_string();
    //cout << " pow: " << power << endl;
    
    while(power > 0){
        if(power % 2 == 1){
            result *= ebase;
            result %= mod;
        }
        
        ebase *= ebase;
        ebase %= mod;
        
        power /= 2;
        
        
        i++;
        //cout << i << " result: " << result.to_string();
        //cout << " base: " << ebase.to_string();
        //cout << " pow: " << power << endl;
        
    }

  *this = result;
  return *this;
  
}


//----------------------------------------------------
//* Operator overloading, non-member functions
//----------------------------------------------------


//Call the += function above to compute a BigInt whose value is a + b
BigInt operator + (const  BigInt &a, const BigInt & b){
    /************* You complete *************/
    BigInt out = a;
    out += b;
    return out;

}

//Call the -= function above to compute a BigInt whose value is a - b
BigInt operator - (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  
    BigInt out = a;
    out -= b;
    return out;
}

//Call the *= function above to compute a BigInt whose value is a * b
BigInt operator * (const  BigInt &a, const BigInt & b){
    BigInt out = a;
    out *= b;
    return out;

    /************* You complete *************/
}

//Call the /= function above to compute a BigInt whose value is a / b
BigInt operator / (const  BigInt &a, const BigInt & b){
    BigInt out = a;
    out /= b;
    return out;

    /************* You complete *************/
}

//Call the %= function above to compute a BigInt whose value is a % b
BigInt operator % (const  BigInt &a, const BigInt & b){
    BigInt out = a;
    out %= b;
    return out;
    /************* You complete *************/
}

//Call the exponentiation function above to compute a BigInt whose value is pow(a,b)
BigInt pow(const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  
  BigInt temp(a);
  BigInt output = temp.exponentiation(b);
  
  return output;
}

//Call the modulusExp function above to compute a BigInt whose value is (a ^ b) mod c
BigInt modPow(const BigInt &a, const BigInt &b, const BigInt &m){

    /************* You complete *************/
  
  BigInt temp(a);
  BigInt output = temp.modulusExp(b,m);
  
  return output;
}

//Call the compare function above to check if a == b
bool operator == (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  return (a.compare(b) == 0);
  
}

//Call the compare function above to check if a != b
bool operator != (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
    return (a.compare(b) != 0);
  
  
}

//Call the compare function above to check if a <= b
bool operator <= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
  return (a.compare(b) >= 0);
  
}

//Call the compare function above to check if a >= b
bool operator >= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  return (a.compare(b) <= 0);
  
}

//Call the compare function above to check if a > b
bool operator > (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  return (a.compare(b) == 1);
}

//Call the compare function above to check if a < b
bool operator < (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
    return (a.compare(b) == -1);
  
}