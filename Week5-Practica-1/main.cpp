/**
 * @file main.cpp
 * @date 26/5/17
 * @author Niels de Waal
 * Jorn Bunk
 * @brief Code voor practicum week 5 opdracht 1
 * 
 * Decorator voor het maken van een AND gate tussen twee input pins.
 */

#include "hwlib.hpp"

/**
 * @class pin_in_AND
 * @author Niels
 * @date 26/05/2017
 * @file main.cpp
 * @brief Decorator voor AND gate
 * 
 * Decorator heeft twee pin_in's als input en levert output op basis van de state van beide pins.
 */
class pin_in_AND : public hwlib::pin_in {
private:
   hwlib::pin_in & slave1;
   hwlib::pin_in & slave2;
   
public:
   pin_in_AND( hwlib::pin_in & slave1, hwlib::pin_in & slave2 ): 
	  slave1(slave1),
	  slave2(slave2){}
   
   bool get() override {
	   return (slave1.get() && slave2.get());
   } 
};

/**
 * @brief Main functie opdracht 1
 * 
 * Werking van decorator wordt gedemonstreerd d.m.v het laten blinken van een led 
 * als bijde input pins hoog zijn.
 */
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   auto pin1	= target::pin_in( target::pins::d8);
   auto pin2	= target::pin_in( target::pins::d9 );
   
   auto led 	= target::pin_out(1, 27);
   
   // LED on when switch is pressed
   auto result	= pin_in_AND(pin1, pin2);
   
   //result.direction_set_input();
   
   if(result.get) {
	   hwlib::blink(led);
   }
}
