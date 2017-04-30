#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <math.h>

/**
 * @class vector
 * @author Niels
 * @date 28/04/2017
 * @file vector.hpp
 * 
 * @brief Vector klasse voor practica opdracht 2.2.3.
 * 
 * Klasse voor het aanmaken van vectoren. Bevat verschillende operators
 * die overloaded zijn zodat ze aansluiten op het correct gebruik van vectoren.
 */

class vector
{
private:
    int x; ///< x-coördinaat vector.
    int y; ///< y-coördinaat vector.
	
	/**
	 * @brief Functie voor vinden inwendig product.
	 * 
	 * Het inproduct wordt uitgerekend als vectoren (a, b) en (c, d),
	 * hierbij is het inproduct: a*c + b*d.
	 * @param[in] lhs vector waarop het inproduct uitgerekend wordt.
	 * @param[in] rhs vector waarmee het inproduct wordt uitgerekend.
	 * @return Het inproduct van rhs op lhs.
	 */
	int dotProduct(const vector & lhs, const vector & rhs) const {
		return (lhs.x*rhs.x + lhs.y*rhs.y);
	}
	
	/**
	 * @brief Functie voor uitrekenen van lengte vector.
	 * 
	 * Lengte van vector (a, b) = sqrt(a^2 + b^2).
	 * @param[in] v Vector waarvan lengte wordt bepaald.
	 * @return Lengte van vector v.
	 */
	float vectorMagnitude(const vector & v) const {
		return sqrt(pow(v.x, 2) + pow(v.y, 2));
	}
public:
	/**
	 * @brief Constructor voor vector.
	 * 
	 * @param[in] x Waarde voor x in vector (x ,y).
	 * @param[in] y Waarde voor y in vector (x ,y).
	 */
    vector(int x = 0, int y = 0):
        x(x),
        y(y)
        {}
    
	/**
	 * @brief Operator voor optellen vectoren.
	 * 
	 * Twee vectoren worden bij elkaar opgeteld.
	 * @param[in] rhs Vector waarvan de waarden bij de vector worden opgeteld.
	 * @return Vector met de opgetelde waarden.
	 */
    vector operator+(const vector & rhs) const {
        return vector(x + rhs.x, y + rhs.y);
    }
    
	/**
	 * @brief Operator voor optellen van vector bij vector.
	 * 
	 * Vector wordt bij andere vector opgeteld.
	 * @param[in] rhs Vector waarvan de waarden bij de vector worden opgeteld.
	 * @return Vector waarbij de waarden zijn opgeteld.
	 */
    vector & operator+=(const vector & rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
	
	/**
	 * @brief Operator voor aftrekken van vector bij vector.
	 * 
	 * Waarden van vector rhs worden van vector afgetrokken.
	 * @param[in] rhs Vector die van vector moet worden afgetrokken.
	 * @return Vector met afgetrokken waarden.
	 */
	vector operator-(const vector & rhs) const {
		return vector(x - rhs.x, y - rhs.y);
	}
    
	/**
	 * @brief Operator voor vermenigvuldigen van vector met scalair.
	 * 
	 * Waarden van vector worden vermenigvuldigd met scalair multiplicative.
	 * @param[in] multiplicative Waarde waarmee vector vermenigvuldigd wordt.
	 * @return Vermenigvuldigde vector.
	 */
    vector operator*(const int multiplicative) const {
        return vector(x * multiplicative, y * multiplicative);
    }
	
	/**
	 * @brief Operator voor vermenigvuldigen scalair met vector.
	 * 
	 * Deze functie doet het zelfde als de andere operator*. Deze versie
	 * bezit het vermogen om gebruikt te worden met het scalair voor de vector.
	 * @param[in] multiplicative Scalair om mee te vermenigvuldigen.
	 * @param[in] rhs Vector die vermenigvuldigd wordt met scalair.
	 * @return Vermenigvuldigde vector.
	 */
	friend vector operator*(int multiplicative, const vector & rhs) {
	vector ret(rhs); ///< Tijdelijke vector voor uitvoeren bewerking.
	ret = ret * multiplicative; 
	return ret;
	}
    
	/**
	 * @brief Operator voor vermenigvuldigen van vector met scalair.
	 * 
	 * Operator voor vermenigvuldigen van scalair op vector.
	 * @param[in] multiplicative Scalair om mee te vermenigvuldigen.
	 * @return Vermenigvuldigde vector.
	 */
    vector & operator*=(const int multiplicative) {
        x *= multiplicative;
        y *= multiplicative;
        return *this;
    }
    
	/**
	 * @brief Operator voor printen van vector.
	 * 
	 * Formatting van vector voor uitvoer naar stream.
	 * @param[out] lhs Directed stream voor output.
	 * @param[in] rhs Vector die geformat moet worden.
	 * @return lhs met correcte uitvoer van vector.
	 */
    friend std::ostream & operator<<(std::ostream & lhs, const vector & rhs) {
        return lhs
        << "("
        << rhs.x << ", "
        << rhs.y << ")";
    }
    
	/**
	 * @brief Operator voor vergelijking twee vectoren op gelijkhijd.
	 * 
	 * Twee vector worden gecontroleerd op het gelijkwaardig zijn in waarden.
	 * @param[in] rhs Vector om mee vergeleken te worden.
	 * @return Bool waarde op basis van gelijkheid.
	 */
    bool operator==(const vector rhs) const {
        return (x == rhs.x) && (y == rhs.y);
    }
	
	/**
	 * @brief Functie voor bepalen hoek met vector a.
	 * 
	 * De hoek tussen vector en vector a wordt uitgerekend.
	 * @param[in] a Vector waarop hoek bepaald wordt.
	 * @return Hoek waarde in radialen.
	 */
	float getAngle(const vector & a) const {
		int dotResult = dotProduct(a, *this); ///< inproduct tussen A en Vector.
		float vectorMagnitudeA = vectorMagnitude(a); ///< Lengte vector A.
		float vectorMagnitudeB = vectorMagnitude(*this); ///< Lengte van vector.
		return acos(dotResult/(vectorMagnitudeA*vectorMagnitudeB));
	}
};

#endif // VECTOR_HPP
