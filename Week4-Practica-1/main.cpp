#include "hwlib.hpp"

//$Id$

/**
 * @file main.cpp
 * @date 20/5/17
 * @author Niels de Waal
 * Jorn Bunk
 * @brief Code voor practicum week 4 opdracht 1
 * 
 * Code voor het laten branden van een rij led lampjes, knight rider style.
 */

/**
 * @brief main functie.
 * @return 0 bij goed verloop.
 */

int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;

	namespace target = hwlib::target;

	auto led0 = hwlib::target::pin_out(target::pins::d7);
	auto led1 = hwlib::target::pin_out(target::pins::d6);
	auto led2 = hwlib::target::pin_out(target::pins::d5);
	auto led3 = hwlib::target::pin_out(target::pins::d4);
	
	for(;;) {
		
		led0.set(1);
		led1.set(1);
		
		hwlib::wait_ms( 200 ); 
		
		led0.set(0);
		led2.set(1);
		
		hwlib::wait_ms( 200 ); 
		
		led1.set(0);
		led3.set(1);
		
		hwlib::wait_ms( 200 ); 
		
		led3.set(0);
		led1.set(1);
		
		hwlib::wait_ms( 200 ); 
		
		led2.set(0);
		led1.set(1);
		led0.set(1);
		
	}
	
	return 0;
}
