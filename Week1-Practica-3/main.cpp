/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 3
/* --------------------------- */

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"
#include "triangle.hpp"
#include "stupid_house.hpp"

int main(int argc, char **argv){
    window w( 128, 64, 2 );
    
	stupid_house sh(0, 0, 0, w);
	stupid_house sp(1, 50, 0, w);
	
    sh.print();
    sp.print();
    
    return 0;
}
