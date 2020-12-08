/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze=NULL;
   
   if(argc < 2){
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
  
   mymaze = read_maze(argv[1], &rows, &cols);
   
   if (mymaze == NULL){
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze,rows,cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
   for(int i = 0; i < rows; i++){
     delete [] mymaze[i];
   }
  
   delete [] mymaze;

   return 0;
}

bool isValid(char**maze, int rows, int cols){
  int starts = 0;
  int fins = 0;
  for (int r = 0; r < rows; r++){
    for(int c = 0; c < cols; c++){
      if (maze[r][c] == 'S'){
        starts++;
      }
      if (maze[r][c] == 'F'){
        fins++;
      }
    }
  }
  
  if( starts == 1 && fins == 1){
    return true;
  }
  return false;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) {
  /*
   * add start location to q
  while q is not empty do
    let loc = extract oldest item from front of q
    for each neighbor of loc
      if neighbor is open and not yet explored
        add neighbor to back of q
        let predecessor of neighbor = loc
   *
   */
  
  Queue path(rows*cols);
  Location start;
  bool fin = false;
  
  if (isValid(maze,rows,cols)){
    for (int r = 0; r < rows; r++){
      for(int c = 0; c < cols; c++){
        if (maze[r][c] == 'S'){
          start.row = r;
          start.col = c;
        }
      }
    }
  }else{
    return -1;
  }
  
  path.add_to_back(start);
  int ** seen = new int*[rows];
  Location ** predecessor = new Location*[rows];
  for (int r = 0; r < rows; r++){
    seen[r] = new int[cols];
    predecessor[r] = new Location[cols];
  }
  
  
  
  seen[start.row][start.col] = 1;
  for (int r = 0; r < rows; r++){
    for(int c = 0; c < cols; c++){
      seen[r][c] = 0;
      predecessor[r][c].row = -1;
      predecessor[r][c].col = -1;
    }
  }
  
  //               N  W  S E
  int move_r[4] = {-1,0,1,0};
  int move_c[4] = {0,-1, 0,1};
  //check if that location is valid and in bounds
      //check if this is the Finish
      //if it is, set fin to true and backtrack 
      //else if its a '.' and it hasnt been visited yet
      //mark it as such and update the predecessor array
      //add this loc to the back of the path
  
  while (!fin && !path.is_empty()){
    Location loc = path.remove_from_front();
    
    for (int i = 0; i < 4; i++){
      Location neighbor;
      neighbor.row = loc.row + move_r[i];
      neighbor.col = loc.col + move_c[i];
      
      if (neighbor.row >= 0 && neighbor.row < rows &&
          neighbor.col >= 0 && neighbor.col < cols){
        if (maze[neighbor.row][neighbor.col] == 'F'){
          fin = true;
          while (maze[loc.row][loc.col] != 'S'){
            maze[loc.row][loc.col] = '*';
            loc = predecessor[loc.row][loc.col];
          }
        }else if (maze[neighbor.row][neighbor.col] == '.' 
                  && seen[neighbor.row][neighbor.col] == 0){
          //cout << " HELLO" << endl;
          seen[neighbor.row][neighbor.col] = 1;
          predecessor[neighbor.row][neighbor.col] = loc;
          path.add_to_back(neighbor);
        }
      }
    }
  }
    
  for(int r = 0; r < rows; r++){
    delete [] predecessor[r];
    delete [] seen[r];
   }
  delete [] predecessor;
  delete [] seen;
  if(fin){
   return 1;
  }else{
   return 0;
  }
}
