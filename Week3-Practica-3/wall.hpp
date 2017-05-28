#ifndef WALL_HPP
#define WALL_HPP

#include "rectangle.hpp"
#include "line.hpp"
#include "vector.hpp"
#include "window.hpp"

class wall : public rectangle
{
private:
	//rectangle rect;
	int update_interval;
	int counter = 0;
	bool filled = false;
public:
	wall(window & w, const vector & start, const vector & end, const int update_interval, const vector & size, const vector & bounce = vector(1,1));
	void draw() override;
	void update();
};

#endif // WALL_HPP
