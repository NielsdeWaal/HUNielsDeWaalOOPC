/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 2
/* --------------------------- */

#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"

#include "line.hpp"

class line {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
   window & w;
public:
   line( window & w, int start_x, int start_y, int end_x, int end_y ):
      start_x( start_x ),
      start_y( start_y ),
      end_x( end_x ),
      end_y( end_y ),
      w( w )
   {}
   void print();
};

#endif // LINE_HPP
