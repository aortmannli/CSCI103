#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];


//straight line
void draw_line(int x0, int y0, int x1, int y1){
  if (y0 == y1){
    for (int j = x0; j < x1; j++){
      if (y0 >= 0 && j >= 0 && y0 < 256 && j < 256){
        image[y0][j] = 0;
      }
    }
  }
  if (x0 == x1){
    for (int k = y0; k < y1; k++){
      if (k >= 0 && x0 >= 0 && k < 256 && x0 < 256){
        image[k][x0] = 0;
      }
    }
  }
}

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
  int h = top + height;
  if (h > 256) { h = 256; }
  int w = left + width;
  if (w > 256) { w = 256; }
  
  //horizontal
  draw_line(left, top, w, top);
  draw_line(left, h, w, h);
  
  //vertical
  draw_line(left, top, left, h);
  draw_line(w, top, w, h);
}


// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
  int x = 0;
  int y = 0;
  double h = height/2;
  double w = width/2;
  for (double theta = 0; theta < 2*M_PI; theta += 0.001 ){
    x = (w*cos(theta)) + cx;
    y = (h*sin(theta)) + cy;
    if ( x < 256 && y < 256 && x >= 0 && y >= 0){
      image[y][x] = 0;
    }
  }
}


int main() {
  bool run = true;
  int mode = -1;
  int x0 = 0;
  int y0 = 0;
  int height = 0;
  int width = 0; 
  
  // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
  
  // Main program loop here
  // while loop works
  while (run){
    cout << "To draw a rectangle, enter: 0 top left height width" << endl;
    cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
    cout << "To save your drawing as output.bmp and quit, enter: 2" << endl;
    cin >> mode;
    if (mode == 2 || mode > 2){
      run = false;
    }else{
      cin >> x0 >> y0 >> height >> width;
      if (mode == 0){
        draw_rectangle(x0,y0, height, width);
      }else if (mode == 1){
        draw_ellipse(x0, y0, height, width);
      }
    }
  }
  
  //cout << (unsigned int)(image[i][j]) << endl;

 
  
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}