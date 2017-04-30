/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 2
/* --------------------------- */

//$Id$
#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"
#include "rectangle.hpp"

/**
 * @class filled_rectangle
 * @author Niels
 * @date 23/04/2017
 * @file filled_rectangle.hpp
 * @brief Class voor het maken van een ingekleurde rechthoek.
 * 
 * Bevat constuctor and print functie.
 */

class filled_rectangle{
private:
    int start_x;
    int end_x;
    int start_y;
    int end_y;
    window & w;
    rectangle & r;
public:
    filled_rectangle(window & w, rectangle & r, int start_x, int end_x, int start_y, int end_y):
        start_x(start_x),
        end_x(end_x),
        start_y(start_y),
        end_y(end_y),
        w(w),
        r(r)
    {}
    void print();
};

#endif // FILLED_RECTANGLE_HPP
