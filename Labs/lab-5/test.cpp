// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;


int main(int argc, char* argv[]) {
  srand(time(0));
  char guess[80];

  bool wordGuessed = false;
  int numTurns = 10;
  
  int numWords;
  

  /* Add code to declare the wordBank array, read in each word
     and store it */
  if(argc < 2){
      cout << "usage: ./scramble <input file>" << endl;
      return -1;
  }
  
  ifstream file(argv[1]);
  
  if (file.fail()) {
    cout << "File provided does not exist. Please try again." << endl;
    file.clear();
    return -1;
  }
  
  file >> numWords;
  if (file.fail()){
    cout << "Number of words not specified." << endl;
    return -2;
  }
  
  char** wordBank = new char*[numWords];
  char word[50];
  int wordlen = 0;
  
  for(int i = 0; i < numWords; i++){
    file >> word;
    wordlen = strlen(word);
    wordBank[i] = new char[wordlen +1];
    strncpy(wordBank[i],word, wordlen+1);
    cout << word << endl;
  }

  file.close();
  
 
    
    
  return 0;
}