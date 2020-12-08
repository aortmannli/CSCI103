/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Angel Li
 * USC email: liangeli@usc.edu
 * Comments (you want us to know):
 * 
 * Description:
 * This program simulates a game of 21/Blackjack between a single player 
 * and a dealer. The player has to provide a seed, and then the game begins.
 * The player has a choice between Hitting (adding a card) and Standing 
 * (comparing sums with the dealer), an input of any other kind causes the 
 * program to quit. The getBestScore() function calculates the best score, 
 * converting Aces from value of 11 to 1 if necessary to not Bust. Should 
 * either the Player or Dealer, bust, or the player chooses to Stand, the 
 * program evaluates the two sums and displays the winner. It then asks the
 * user if they wish to play again. Any response other than 'y' causes the 
 * program to quit. The games are simulated using two while loops, one 
 * representing the game overall and the other representing each "round."
 *
 ******************************************************************************/

#include <iostream>
#include <cstdlib>


using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[]){  
  int c = -1;
  int temp = 0;
  for(int i = 51; i > 0; i--){
    c = rand() % (i+1);
    //switching the cards
    temp = cards[i];
    cards[i] = cards[c];
    cards[c] = temp;
  }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id){
  int s = id/13;
  int num = id - (s*13) ;

  cout << type[num] << "-" << suit[s];
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id){
  int s = id/13;
  int num = id - (s*13) ;
  return value[num];
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards){
  for (int a = 0; a < numCards; a++){
    printCard(hand[a]);
    cout << " ";
  }
  cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards){
  int sum = 0;
  int aces[4] = {-1,-1,-1,-1};
  //idx holds the number of aces as well sa the future idx
  int idx = 0;
  
  // calculates sum treating all aces like 11s
  //however it takes note of every ace index
  for (int a = 0; a < numCards; a++){
    sum += cardValue(hand[a]);
    if ((hand[a] + 1 ) % 13 == 0){
      aces[idx] = a;
      idx++;
    }
  }
  
  if (sum > 21){
    for (int i = 0; i < idx; i++){
        if (sum > 21) {sum -= 10;}
    }
  }
  return sum;
}

//method checks if the Player Lost, Won, or Tied
void gameScore(int p[], int d[], int p_idx, int d_idx){
  // p[] and d[] are phand and dhand. p_idx and d_idx are pIdx and dIdx
  int p_sum = getBestScore(p, p_idx);
  int d_sum = getBestScore(d, d_idx);
  
  if (d_sum > 21 || p_sum == 21 || (p_sum > d_sum && p_sum < 21)){
    cout << "Win " << p_sum << " "<< d_sum << endl;
  }else if (p_sum > 21 || d_sum == 21 || (d_sum > p_sum && d_sum < 21)){
    cout << "Lose " << p_sum << " "<< d_sum << endl;
  }else if (p_sum == d_sum){
    cout << "Tie " << p_sum << " "<< d_sum << endl;
  }
  cout << endl;
}

void setup(int c[], int d[], int p[]){
    //populate deck
    for (int a = 0; a < 52; a++){
      c[a] = a;
    }
  
    //shuffle deck
    shuffle(c);

    //card to dealer
    d[0] = c[1];
    d[1] = c[3];
    cout << "Dealer: ? ";
    printCard(d[1]);
    cout << endl;

    //card to player
    p[0] = c[0];
    p[1] = c[2];
    cout << "Player:";
    printHand(p,2);
}


int main(int argc, char* argv[]){
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------
  
  bool play = true;
  char input;
  
  //while loop represents each game, loops back around each round 
  //uses bool play as breaker, evaluted at the end of each round
  while(play){
    //setup method
    setup(cards,dhand,phand); 
    
    int deck = 4;
    int dIdx = 2;
    int pIdx = 2;
    bool round = true;
    
    //checks if player immediately hits 21
    if (getBestScore(phand, 2) == 21){
      //if player already won first off then let dealer hit until hes at 17 or more
      while(getBestScore(dhand,dIdx) < 17){
        dhand[dIdx] = cards[deck];
        dIdx++;
        deck++;
      }
      //print out dealers hand
      cout << "Dealer:";
      printHand(dhand, dIdx);
      
      //prints out game outcome
      gameScore(phand,dhand,pIdx, dIdx);
      
      //asks if user wants to play again
      cout << "Play again? [y/n]" << endl;
      cin >> input;
      round = false;
    }

    //while loop represents each round, called until a Bust or a Stand
    //uses bool round as breaker, evaluted when the round outcome is evaluated
    while (round){
      cout << "Type 'h' to hit and 's' to stay:" << endl;
      cin >> input;
      
      if (input != 's' && input != 'h'){
        cout << "Please use valid commands.";
        return 0;
      }
      
      //if player chooses to hit
      if (input == 'h'){
        phand[pIdx] = cards[deck];
        cout << "Player:";
        printHand(phand, pIdx+1);  
        pIdx++;
        deck++;
      }

      //Checks if Player busts
      if (getBestScore(phand, pIdx) > 21){
        cout << "Player busts" << endl; 
        gameScore(phand,dhand,pIdx,dIdx);
        
        cout << "Play again? [y/n]" << endl;
        cin >> input;
        round = false;
      }else if (getBestScore(phand, pIdx) == 21){
        //if player already won then let dealer hit until hes at 17 or more
        while(getBestScore(dhand,dIdx) < 17){
          dhand[dIdx] = cards[deck];
          dIdx++;
          deck++;
        }
        
        //print out dealers hand and game outcome
        cout << "Dealer:";
        printHand(dhand, dIdx);
        gameScore(phand, dhand, pIdx, dIdx);
        
        //plays again
        cout << "Play again? [y/n]" << endl;
        cin >> input;
        round = false;
      }


      //if player chooses to stay
      if (input == 's'){
        //if player already won then let dealer hit until hes at 17 or more
        while(getBestScore(dhand,dIdx) < 17){
          dhand[dIdx] = cards[deck];
          dIdx++;
          deck++;
        }
        
        //prints out dealer hand and announces if the dealer busts
        cout << "Dealer:";
        printHand(dhand, dIdx);
        
        if (getBestScore(dhand, dIdx) > 21){
          cout << "Dealer busts" << endl; 
        }
        
        //prints out game outcome
        gameScore(phand,dhand,pIdx,dIdx);  
        cout << "Play again? [y/n]" << endl;
        cin >> input;
        round = false;
      }
    }
    
    //checks if the user said anything other than 'y'
    //in response to Play again? and quits if not
    if (input != 'y'){
      play = false;
    }
  }
  return 0;
}

