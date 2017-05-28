// example:
// definition of the functions of a rectangle object

#include "drawable.hpp"
#include "rectangle.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end, const vector & size, const vector & bounce):
   drawable( w, start, size, bounce ),
   start(start),
   end( end ),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
{}

void rectangle::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
}

