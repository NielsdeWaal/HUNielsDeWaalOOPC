/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 3
/* --------------------------- */

//$Id$
#ifndef STUPID_HOUSE_HPP
#define STUPID_HOUSE_HPP

#include "window.hpp"
#include "filled_rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"

/**
 * @class stupid_house
 * @author Niels
 * @date 23/04/2017
 * @file stupid_house.hpp
 * @brief Klasse voor het tekenen van een dom huisje.
 * 
 * Bestand bevat klasse met public constructor en print functie.
 */
class stupid_house
{
private:
    int curtains_closed;
	int xOffset;
	int yOffset;
    window & w;
    filled_rectangle fr;
    circle c;
    triangle t;
    rectangle r;
    rectangle rr;
public:
    stupid_house(int curtains_closed, int xOffset, int yOffset, window & w);
    void print();
};

#endif // STUPID_HOUSE_HPP
