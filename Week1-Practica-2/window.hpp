/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 2
/* --------------------------- */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windows.h"

class window {
   int x_size;
   int y_size;
   int scale;
   
   // needed to use the OS window
   HDC hdc;
   
public:
   window( int x_size, int y_size, int scale );
   void draw( int x, int y );
   void clear();
};

#endif // WINDOW_HPP
