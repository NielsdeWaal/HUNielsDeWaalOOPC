#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "rectangle.hpp"
#include "wall.hpp"

int main(){
	window w( vector( 128, 64 ), 2 );
	
	//line top( w, vector(   0,  0 ), vector( 127,  0 ) );
	wall top(w, vector(0,0), 		vector(123,3), 	5, vector(124, 4), vector(1, -1));
	//line right( w, vector( 127,  0 ), vector( 127, 63 ) );
	wall right(w, vector(124,0), 	vector(127,59), 5, vector(4, 60), vector(-1, 1));
	//line bottom( w, vector( 127, 63 ), vector(   0, 63 ) );
	wall bottom(w, vector(4,60), 	vector(127,63), 	5, vector(124, 4), vector(1, -1));
	//line left( w, vector(   0, 63 ), vector(   0,  0 ) );
	wall left(w, vector(0,4), 		vector(3,127), 	5, vector(4, 60), vector(-1, 1));
	
	ball b(w, vector( 60, 40 ), 9, vector( -5, -2 ));//, top, left, right, bottom);
	
	//wall rect(w, vector(20, 30), vector(30, 40), 5);
	
	drawable * objects[] = {&b, &top, &left, &right, &bottom};
	
	for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 200 );
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

