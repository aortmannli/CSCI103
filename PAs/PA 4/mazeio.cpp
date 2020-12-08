/* 
mazeio.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include <fstream>
#include "mazeio.h"

using namespace std;

/*************************************************
 * read_maze:
 * Read the maze from the given filename into a 
 *  2D dynamically  allocated array.
 * 
 * Return the pointer to that array.
 * Return NULL (a special address) if there is a problem, 
 * opening the file or reading in the integer sizes.
 *
 * The first argument is the filename of the maze input.
 *  You should use an ifstream to open and read from this
 *  file.
 *
 * We also pass in two pointers to integers. These are
 * output parameters (i.e. declared by the caller and 
 * passed-by-reference for this function to fill in).
 * Fill the integers pointed to by these arguments
 * with the number of rows and columns 
 * read (the first two input values).
 *
 *************************************************/
char** read_maze(char* filename, int* rows, int* cols) {
  int r,c;
  
  ifstream file(filename);
  
  if (file.fail()) {
    cout << "File provided does not exist. Please try again." << endl;
    file.clear();
    return NULL;
  }
  
  file >> r >> c;
  if (file.fail()){
    cout << "Number of rows and columns" << endl;
    return NULL;
  }
  *rows = r;
  *cols = c;
  
  char** maze = new char*[r];
 
  //takes in exactly the number of words specified
  //words separated by whitespace
  for(int i = 0; i < r; i++){
    maze[i] = new  char[c];
  }
  
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      file >> maze[i][j];
      if (maze[i][j] != 'S' && maze[i][j] != 'F' 
          && maze[i][j] != '#' && maze[i][j] != '.'){
        cout << "Error, input format incorrect." << endl;
        return NULL;
      }
    }
  }
  
  //no more reading/writing to file 
  file.close();
  
  return maze;
}

/*************************************************
 * Print the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/
void print_maze(char** maze, int rows, int cols) {
  cout << rows << " " << cols << endl;
  for (int r = 0; r < rows; r++){
    for (int c = 0; c < cols; c++){
      cout << maze[r][c];
    }
    cout << endl;
  }
}

