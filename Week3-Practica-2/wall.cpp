#include "wall.hpp"
#include "rectangle.hpp"
#include "window.hpp"

/**
 * @brief wall constructor
 * @param w window
 * @param start start vector
 * @param end end vector
 * @param update_interval update_interval value
 * @param size size vector
 * @param bounce bounce vector
 * 
 * wall constructor
 */
wall::wall(window & w, const vector & start, const vector & end, const int update_interval, const vector & size, const vector & bounce):
	rectangle(w, start, end, size, bounce),
	update_interval(update_interval)
{}

/**
 * @brief Functie voor het tekenen van object in window object.
 * 
 * rectangle wordt getekend.
 */
void wall::draw() {
	if (filled) {
		for (int x = start.x + 1; x <= end.x; x++) {
			for (int y = start.y + 1; y <= end.y; y++) {
				w.draw(vector(x,y));
			}
		}
	} else {
		left.draw();
		right.draw();
		top.draw();
		bottom.draw();
	}
}

/**
 * @brief Functie die interactie afhandeld.
 * 
 * Update functie houd bij wanneer het object gevuld of niet gevult moet zijn.
 */
void wall::update() {
	counter++;
	
	if(counter == update_interval) {
		counter = 0;
		filled = !filled;
	}
}
