/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 3
/* --------------------------- */

/**
 * @brief Klasse voor het maken van een huisje.
 * @param[in] curtains_closed Waarde voor bepalen toestand van gordijnen.
 * @param[in] xOffset
 * @param[in] yOffset
 * @param[in] w
 */
 
#include <iostream>

#include "stupid_house.hpp"
#include "window.hpp"
#include "filled_rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"

stupid_house::stupid_house(int curtains_closed, int xOffset, int yOffset, 
							window & w):
    curtains_closed(curtains_closed),
    xOffset(xOffset),
	yOffset(yOffset),
	w(w),
	r(rectangle 		(w, 25+xOffset, 20+yOffset, 45+xOffset, 40+yOffset)),
	t(triangle 			(w, 20+xOffset, 20, 15, 30)),
	c(circle 			(w, 35+xOffset, 13+yOffset, 3)),
	fr(filled_rectangle (w, r, 35+xOffset, 40+xOffset, 25+yOffset, 35+yOffset)),
	rr(rectangle 		(w, 35+xOffset, 25+yOffset, 40+xOffset, 35+yOffset))
{
}

/**
 * @brief print functie voor stupid_house klasse.
 * 
 * Basis elementen worden geprint.
 * 
 * Hierna word bepaald of de gorijnen gesloten zijn of open.
 */
void stupid_house::print() {
   t.print();
   r.print();
   c.print();
   
   if (curtains_closed) {
        fr.print();
   } else {
        rr.print();
   }
}
