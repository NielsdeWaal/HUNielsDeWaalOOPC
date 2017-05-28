#ifndef BALL_HPP
#define BALL_HPP

/**
 * @class ball
 * @author Niels
 * @date 19/05/2017
 * @file ball.hpp
 * @brief ball classe
 */
#include "window.hpp"
#include "vector.hpp"
#include "circle.hpp"

class ball : public circle {
private:
   vector speed;
public:
   ball( window & w, const vector & midpoint, int radius, const vector & speed );
   void update() override;
   void interact( drawable & other ) override;
};

#endif // BALL_HPP
