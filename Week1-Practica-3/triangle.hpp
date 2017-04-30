/* --------------------------- */
// Niels de Waal
// 1698041
// Jorn Bunk
// Week 1 opdracht 3
/* --------------------------- */

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "line.hpp"
#include "window.hpp"

/**
 * @class triangle
 * @author Niels
 * @date 23/04/2017
 * @file triangle.hpp
 * @brief klasse bepaling voor triangle object.
 * 
 * Bevat definitie voor constructor en print functie.
 */
class triangle
{
private:
    line bottom, left, right;
public:
    triangle(window & w, int start_x, int start_y, int height, int length);
    void print();
};

#endif // TRIANGLE_HPP
