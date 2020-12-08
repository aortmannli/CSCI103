#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


// sum an array of numbers
int test1(int* data, int len)
{
  int sum = 0;
  // used to be less than or equal to, deleted =
  for(int i=0; i < len; i++){
    sum += data[i];
  }
  return sum;
}

// Allocate a random number array
char* test2_init(int len)
{
  char buf[80];
  cout << "Enter a word: ";
  cin >> buf;
  char* mydat = new char[strlen(buf)+1];
  strcpy(mydat, buf);
  return mydat;
}

char* test2_reverse(char* word)
{
  int len = strlen(word);
  char* otherword = new char[len];
  
  for(int i=0; i < strlen(word); i++){
    otherword[i] = word[len-i-1];
  }
  //last index should be at len-1 used to be len+1
  otherword[len-1] = '\0';
  //
  //delete [] word;
  return otherword;
}

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please enter the test number you want to run [1-2]" << endl;
    return 1;
  }
  const int len = 7;
  int test = atoi(argv[1]);

  if(test == 1){
    // Test should sum up the array values and print it
    // used to be int * data = new int[len]
    // but there is no need for a pointer 
    int data[len];
    for(int i=0; i < len; i++){
      data[i] = rand()%100;
    }
    int sum = test1(data, len);
    cout << "Test 1 sum is " << sum << endl;
  }

  else if(test == 2){
    // Test should create a random string & then reverse a copy
    char* myword = test2_init(len);
    cout << "myword is " << myword << endl;
 
    char* o = test2_reverse(myword);    
    cout << "otherword is " << o << endl;
   
    delete [] myword;
    //myword = NULL;
    delete [] o;
    //o= NULL;
    
  }
  else {
    cout << "Unknown test number" << endl;
  }

  return 0;
}
