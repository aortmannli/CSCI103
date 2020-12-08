
#include "turtle.h"
#include <cmath>

using namespace std;

/*
Turtle::Turtle(){
	x = 0;
  y = 0;
  dir = 0;
  
  //default values
  colour = draw::BLACK;
  visible = true;
}*/

Turtle::Turtle(double x0, double y0, double dir0){
  //default parameters are set up in the header file as 0 0 0
  x = x0;
  y = y0;
  dir = dir0;
  
  //default values
  colour = draw::BLACK;
  visible = true;
}

void Turtle::move(double dist){
  // move the Turtle forward dist steps
  double theta = dir * (M_PI/180); //degree to radian conversion
  
  // draw if visible, make sure to set color again
  if (visible){
    setColor(colour);
    draw::line(x, y, x+dist*cos(theta), y+dist*sin(theta));
  }
  
  //update x and y values
  x += dist*cos(theta);
  y += dist*sin(theta);
}

void Turtle::turn(double deg){
  // turn the Turtle counterclockwise/left deg degrees
  dir += deg;
} 

void Turtle::setColor(Color c){
  draw::setcolor(c);
  colour = c;
}

void Turtle::off(){
  visible = false;
}

void Turtle::on(){
  visible = true;
}
  