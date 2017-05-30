/**
 * @file main.cpp
 * @date 21/5/17
 * @author Niels de Waal
 * Jorn Bunk
 * @brief Code voor practicum week 5 opdracht 1
 * 
 * Code voor het laten branden van een rij led lampjes.
 * Deze worden aan de hand van een counter (die door knopjes worden bestuurd), 
 * incrementeel aangestuurd.
 */

#include "hwlib.hpp"

/**
 * @brief Functie voor het incrementeel aansturen van ledjes.
 * 
 * Wait functies worden gebruikt voor het debouncen van de knoppen.
 * 
 * @param leds
 * @param up
 * @param down
 */
void counter(hwlib::port_out & leds, hwlib::pin_in & up, hwlib::pin_in & down) {
	bool upHigh = false;
	bool downHigh = false;
	
	int counter = 0;
	while(1) {
	if(up.get() && !upHigh) {
		hwlib::wait_ms( 200 );
		if (counter == 4) {
			counter = 4;
		} else {
			counter++;
		}
		upHigh = true;
	} else if (down.get() && !downHigh) {
		hwlib::wait_ms( 200 );
		if (!counter) {
			counter = 0;
		} else {
			counter--;
		}
		downHigh = true;
	} else if (!down.get() && upHigh) {
		hwlib::wait_ms( 200 );
		upHigh = !upHigh;
	} else if (!up.get() && downHigh) {
		hwlib::wait_ms( 200 );
		downHigh = !downHigh;
	}
	
	if (counter == 0) {
		leds.set(0);
	} else if (counter == 1) {
		leds.set(1);
	} else if (counter == 2) {
		leds.set(3);
	} else if (counter == 3) {
		leds.set(7);
	} else if (counter == 4) {
		leds.set(15);
	} else if (counter == 5) {
		leds.set(31);
	} else if (counter == 6) {
		leds.set(63);
	} else if (counter == 7) {
		leds.set(127);
	} else if (counter == 8) {
		leds.set(255);
	}
	
	}
}

/**
 * @brief Main functie 
 * 
 * Alle parameters worden opgezet.
 * Hierna word de functie aangeroepen voor het uitvoeren van de opdracht.
 */

int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;

	namespace target = hwlib::target;

	auto led = target::pin_in_out(1, 27);
	led.direction_set_output();

	auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		shcp, 
		ds, 
		hwlib::pin_in_dummy 
	);

	auto chip = hwlib::hc595(spi, stcp);

	auto led0 	= target::pin_out(target::pins::d7);
	auto led1 	= target::pin_out(target::pins::d6);
	auto led2 	= target::pin_out(target::pins::d5);
	auto led3 	= target::pin_out(target::pins::d4);
	
	auto leds 	= hwlib::port_out_from_pins(led0, led1, led2, led3, chip.p1, chip.p2, chip.p3, chip.p4);
	
	auto up 	= target::pin_in(target::pins::d3);
	auto down 	= target::pin_in(target::pins::d2);
	
	counter(leds, up, down);
}
