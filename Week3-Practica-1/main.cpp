#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "rectangle.hpp"
#include "wall.hpp"

int main(){
	window w( vector( 128, 64 ), 2 );
	
	line top( w, vector(   0,  0 ), vector( 127,  0 ) );
	line right( w, vector( 127,  0 ), vector( 127, 63 ) );
	line bottom( w, vector( 127, 63 ), vector(   0, 63 ) );
	line left( w, vector(   0, 63 ), vector(   0,  0 ) );
	
	wall rect(w, vector(20, 30), vector(30, 40), 5);
	
	drawable * objects[] = {&rect, &top, &left, &right, &bottom};
	
	for(;;){
	  w.clear();
	  for( auto & p : objects ){
		 p->draw();
	  }
	  wait_ms( 100 );
	  for( auto & p : objects ){
		  p->update();
	  }
	}
}

