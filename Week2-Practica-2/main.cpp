#include <iostream>

#include "ostream"
#include "vector.hpp"
#include "catch_with_main.hpp"

TEST_CASE("Constructor, default values") {
	vector v(1, 2);
	REQUIRE(v == vector(1, 2));
}

TEST_CASE("Print function, full contructor") {
   vector v(3, 4);
   std::stringstream s;
   s << v;
   REQUIRE(s.str() == "(3, 4)");   
}

TEST_CASE("Adding vector + vector") {
	vector v(3, 4);
	vector x = v + vector (4, 3);
	REQUIRE(v == vector(3, 4));
	REQUIRE(x == vector(7, 7));
}

TEST_CASE("Adding vector into vector") {
	vector v(3, 4);
	v += vector(2,2);
	REQUIRE(v == vector(5,6));
}

TEST_CASE("Adding vector into vector, with return") {
	vector v( 1, 2 );
	vector x = ( v += vector(1, 4)); 
	REQUIRE(v == vector(2, 6));     
	REQUIRE(x == vector(2, 6)); 
}

TEST_CASE("Multiply vector, int") {
	vector v(1, 2);
	vector x = v * 2;
	REQUIRE(x == vector(2, 4));
}

TEST_CASE("Multiply int, vector") {
	vector v(1, 2);
	vector x = 2 * v;
	REQUIRE(x == vector(2, 4));
}

TEST_CASE("Multiply int into vector") {
	vector v(3, 4);
	v *= 2;
	REQUIRE(v == vector(6, 8));
}

TEST_CASE("Multiply vector into vector, with return") {
	vector v( 1, 2 );
	vector x = ( v *= 2);
	REQUIRE(v == vector(2, 4));
	REQUIRE(x == vector(2, 4)); 
}

TEST_CASE("Angle between vectors") {
	vector v(2,2);
	vector w(5, -3);
	float result = v.getAngle(w);
	REQUIRE(result == Approx(1.32582f));
}