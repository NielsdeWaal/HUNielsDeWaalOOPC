/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 3
/* --------------------------- */

//$Id$

/**
 * @file filled_rectangle.cpp
 *
 * @brief Bestand met code voor inkleuren van rechthoek.
 */

#include "filled_rectangle.hpp"

/**
 * @brief Tekend een ingekleurde rechthoek.
 * 
 * Een nested for loop gaat over de pixels die binnen het vlak liggen en maakt ze zwart.
 */

void filled_rectangle::print() {
    for (int x = start_x + 1; x <= end_x; x++) {
        for (int y = start_y + 1; y <= end_y; y++) {
            w.draw(x, y);
        }
    }
}

