/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 2
/* --------------------------- */

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2 );
   rectangle r(w, 5, 5, 20, 30);
   
   filled_rectangle fr(w, r, 5, 20, 5, 30);
   fr.print();
   
   return 0;
}
