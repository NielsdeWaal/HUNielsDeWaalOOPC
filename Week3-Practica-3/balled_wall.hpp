#ifndef BALLED_WALL_HPP
#define BALLED_WALL_HPP

/**
 * @class balled_wall
 * @author Niels
 * @date 20/05/2017
 * @file balled_wall.hpp
 * @brief Rectangle die kleiner wordt naarmate hij meer interactie heeft met andere objecten.
 */

#include "drawable.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "vector.hpp"
#include "window.hpp"

class balled_wall : public rectangle
{
private:
	bool shrinking = false;
public:
	balled_wall(window & w, const vector & start, const vector & end, const vector & size);
	void update() override;
	void interact(drawable & other) override;
	void draw();

};

#endif // BALLED_WALL_HPP
