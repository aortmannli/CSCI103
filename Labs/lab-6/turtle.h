#include <cmath>
#include "draw.h"
using namespace std;


class Turtle{
  private:
    //all data memebers are private
    double x, y, dir;
    Color colour;
    bool visible;
  
  public:
    //constructor w default params
		//Turtle();
    Turtle(double x0 = 0, double y0 = 0, double dir0 = 180);
    
    //method declarations
    void move(double dist);
    void turn(double deg);
    void setColor(Color c);
    void off();
    void on();
    
};
