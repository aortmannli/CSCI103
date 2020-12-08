// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);
void printWord(char* word, int l);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};
// works: program, science, trojan, popcorn?, library, 

const int numWords = 10;

int main(){
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;
  int guessResult = -1;
    
  
  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];
  int len = strlen(targetWord);
  //char copyTarget[len];
  
  /*
  for (int i = 0; i < len; i++){
    copyTarget[i] = targetWord[i];
  }*/
  
  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter

  for (int a = 0; a < len+1; a++){
    if(a == len){
      word[a] = '\0';
    }else{
      word[a] = '*';
    }
  }
  
  
  //printWord(copyTarget, len);
  //cout << endl;
  
  // An individual game continues until a word
  // is guessed correctly or 10 turns have elapsed
  while (numTurns > 0 && !wordGuessed){
    cout << "Current word: "; 
    printWord(word,len);
    cout << endl;
    cout << numTurns << " remain...Enter a letter to guess" << endl;
    cin >> guess;
    
    guessResult = processGuess(word, targetWord, guess);
    // output of 0 means the guess was incorrect, player loses a turn
    // output of 1 means that the guess was correct, nothing happens, next turn
    // output of 2 means the player won - all letters were guessed
    
    if (guessResult == 0){
      numTurns--;
    }else if (guessResult == 2){
      cout << "The word was: ";
      printWord(word, len);
      cout << ". You win!" << endl;
      wordGuessed = true;
      return 0;
    }
  } 
 
  //Because in the case of winning, main() returns
  //This only gets called in the case of a loss
  cout << "Too many turns...You lose!" << endl;
  
  return 0;
}

//prints out the word 
void printWord(char word[], int l){
  for (int i = 0; i < l; i++){
    cout << word[i];
  }
}

//currently facing issues with computer and president and football

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess){
  int count = 0;
  //checks every letter in the word for matches
  //and converts from asterisk
  for (int i = 0; i < strlen(targetWord); i++){
    if (guess == targetWord[i]){
      word[i] = guess;
      count++;
    }
  }
  
  if(strcmp(word, targetWord) == 0){
        return 2;
  } else if (count > 0){
    return 1;
  }
  return 0;
}