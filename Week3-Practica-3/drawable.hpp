#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ostream>
#include "window.hpp"
#include "vector.hpp"

class drawable {
protected:
   window w;
   vector location;
   vector size;
public:
   vector bounce;
   drawable( window & w, const vector & location, const vector & size = vector(1,1), const vector & bounce = vector(1,1));   
   bool overlaps( const drawable & other );
   virtual void draw() = 0;
   virtual void update(){}
   virtual void interact( drawable & other ){}
};

#endif // DRAWABLE_HPP
