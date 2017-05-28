#include "balled_wall.hpp"
#include "rectangle.hpp"
#include "window.hpp"

/**
 * @brief constructor balled_wall
 * @param w window
 * @param start start vector
 * @param end end vector
 * @param size size vector
 * 
 * Superclass van rectangle wordt aangemaakt.
 */
balled_wall::balled_wall(window & w, const vector & start, const vector & end, const vector & size):
	rectangle(w, start, end, size)
{}

/**
 * @brief interact functie voor detectie interactie met andere objecten.
 * @param other
 * 
 * If statement kijkt of object niet met zichzelf in aanraking is en roept
 * drawable overlaps functie aan.
 */
void balled_wall::interact(drawable & other) {
	if ( this != & other && overlaps( other ) ) {
		shrinking = true;
	}
}

/**
 * @brief Functie voor het tekenen van object in window object.
 * 
 * rectangle wordt getekend.
 */
void balled_wall::draw() {
	line left(w, 	vector( start.x, start.y ), 	vector( start.x, end.y   ) );
	line right(w, 	vector( end.x,   start.y ), 	vector( end.x,   end.y   ) );
	line top(w, 	vector( start.x, start.y ), 	vector( end.x,   start.y ) );
	line bottom(w, 	vector( start.x, end.y   ), 	vector( end.x,   end.y   ) );
	
	left.draw();
	right.draw();
	top.draw();
	bottom.draw();
}

/**
 * @brief Functie die interactie afhandeld.
 * 
 * Als een object kleiner aan het worden is, worden de vectoren aangepast.
 * Als het object te klein is word deze naar de linker boven hoek verplaatst en 
 * word de grote 0.
 */
void balled_wall::update() {
	if ((size.y == 0 || size.y == 0) && shrinking) {
		size = vector(0,0);
		start = vector(0,0);
		end = vector(0,0);
		shrinking = false;
	} else if (shrinking) {
		start += vector(1,1);
		end += vector(-1,-1);
		size += vector(-2,-2);
		shrinking = false;
	}
}
