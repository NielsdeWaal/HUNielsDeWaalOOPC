/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 2
/* --------------------------- */

#include "circle.hpp"

void circle::print(){
    
   // don't draw anything when the size would be 0 
   if( radius < 1 ){
      return;       
   }
   
   // http://en.wikipedia.org/wiki/Midpoint_circle_algorithm
   
   int fx = 1 - radius;
   int ddFx = 1;
   int ddFy = -2 * radius;
   int x = 0;
   int y = radius;
      
   // top and bottom
   w.draw( mid_x + 0, mid_y + radius );
   w.draw( mid_x + 0, mid_y - radius );
      
   // left and right 
   w.draw( mid_x + radius, mid_y + 0 );
   w.draw( mid_x + radius, mid_y - 0 );
    
   while( x < y ){
      
      // calculate next outer circle point
      if( fx >= 0 ){
        y--;
        ddFy += 2;
        fx += ddFy;
      }
      x++;
      ddFx += 2;
      fx += ddFx;   
      
      w.draw( mid_x + x, mid_y + y );
      w.draw( mid_x - x, mid_y + y );
      w.draw( mid_x + x, mid_y - y );
      w.draw( mid_x - x, mid_y - y );
      w.draw( mid_x + y, mid_y + x );
      w.draw( mid_x - y, mid_y + x );
      w.draw( mid_x + y, mid_y - x );
      w.draw( mid_x - y, mid_y - x );
   }
}
