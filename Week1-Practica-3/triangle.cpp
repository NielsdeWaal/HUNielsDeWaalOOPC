/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 3
/* --------------------------- */

#include "triangle.hpp"
#include "window.hpp"

/**
 * @brief constructor voor triangle klasse.
 * @param w window object.
 * @param start_x start positie op de x-as.
 * @param start_y start positie op de y-as.
 * @param height hoogte van de driehoek.
 * @param length breedte van de driehoek.
 */
triangle::triangle(window & w, int start_x, int start_y, int height, int length):
    bottom(w, start_x, start_y, start_x+length, start_y),
    left(w, start_x, start_y, (start_x+(length/2)), start_y-height),
    right(w, start_x+length, start_y, (start_x+(length/2)), start_y-height)
{
}

/**
 * @brief Functie voor printen triangle object.
 * 
 * De drie lijnen worden geprint.
 */
void triangle::print() {
    bottom.print();
    left.print();
    right.print();
}


