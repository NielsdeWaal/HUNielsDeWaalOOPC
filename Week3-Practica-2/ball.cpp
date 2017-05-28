#include "ball.hpp"
#include <iostream>

/**
 * @brief update functie voor ball classe.
 * 
 * Locatie wordt aangepast op basis van speed.
 */
void ball::update(){
   location += speed;
}

/**
 * @brief ball constructor
 * @param w window
 * @param midpoint startpunt ball
 * @param radius straal van ball
 * @param speed start snelheid van ball.
 */
ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

/**
 * @brief interact functie voor detectie interactie met andere objecten.
 * @param other
 * 
 * If statement kijkt of object niet met zichzelf in aanraking is en roept
 * drawable overlaps functie aan.
 */
void ball::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         speed.x *= other.bounce.x;
         speed.y *= other.bounce.y;
      }
   }
}