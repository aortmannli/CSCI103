#include "turtle.h"
#include "draw.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void draw_sierpinski(Turtle, double, int);

int main(int argc, char* argv[]) {
  draw::setpenwidth(1); //thin pen
  draw::setrange(-100, 100); //canvas is 200x200
	
	if (argc !=2) {
      cerr << "Please enter a depth" << endl;
      std::exit(1);
	}
  
	int d = atoi(argv[1]); //sets triangle fractal depth
  if (d < 1){
      cerr << "Depth too low." << endl;
      std::exit(1);
  }

	/*
	Turtle waclaw(80,60,180); //turtle in the middle top of screen
  waclaw.setColor(draw::GREEN); //pen colot to green
	draw_sierpinski(waclaw, 160,d); //call draw function
	*/
	
  return 0;
}

void draw_sierpinski(Turtle buddy, double length, int depth){
  if (depth == 0){
    //if this is the last layer draw the innermost triangle
    for(int i = 0; i < 3; i++){
      buddy.move(length);
      buddy.turn(120);
    }
  }else{
    //depth is decreased every time until 
    //break cond is met for each inner triangle
    //until then keep drawing the inner triangles
    draw_sierpinski(buddy,length/2,depth-1);
    buddy.move(length/2);
    draw_sierpinski(buddy,length/2,depth-1);
    buddy.move(-length/2);
    draw::show(50);
    buddy.turn(60);
    buddy.move(length/2);
    buddy.turn(-60);
    draw_sierpinski(buddy,length/2,depth-1);
    buddy.turn(60);
    buddy.move(-length/2);
    buddy.turn(60);
    draw::show(50);
  }
}