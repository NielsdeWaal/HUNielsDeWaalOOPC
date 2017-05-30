#include "hwlib.hpp"

//$Id$

/**
 * @file main.cpp
 * @date 30/5/17
 * @author Niels de Waal
 * Jorn Bunk
 * @brief Code voor practicum week 6 opdracht 1
 * 
 * Code voor de interface met het OLED display. Rechthoek wordt getekend en bewogen.
 */

/**
 * @brief Schrijf inhoud array naar OLED.
 * @param array Framebuffer
 * @param display reference naar I2C OLED display
 * 
 * Nested for loop kijkt welke pixel geprint moet worden en pushed deze naar de
 * hwlib interface. Voor extra snelheid worden alleen de benodigde pixels geschreven.
 */
void pushBuffer(int array[][64], hwlib::glcd_oled & display) {
	for(uint8_t i = 0; i < display.size.x; ++i) {
		for(uint8_t j = 0; j < display.size.y; ++j) {
			if(array[i][j] == 1){
				display.write(hwlib::location(i,j), hwlib::black); ///< Kleur op het scherm lijkt toch echt wit.
			}
		}
	}	
}

/**
 * @brief Schuift inhoud array 10 plaatsen omhoog
 * @param array Te verschuifen array
 * 
 * Inhoud array wordt 10 plaatsen omhoog verplaatst.
 */
void shiftArrayUp(int array[][64]) {
	for(int i = 0; i < 10; i++) {
		int *flat = (int *)array;
		int temp = flat[0];

		for ( size_t i = 1; i < 128*64; ++i )
			flat[i-1] = flat[i];

		flat[128*64-1] = temp;
	}
}

/**
 * @brief Reset array en schrijf rechthoek op originele locatie.
 * @param array Te reseten array
 * 
 * Verschillende for loops handelen verschillende aspecten van de reset af.
 * Eerste loop leegt array. Andere 4 tekenen verschillende lijnen.
 */
void resetArray(int array[][64]) {
	for(int i = 0; i < 128; ++i) {
		for(int j = 0; j < 64; ++j) {
			array[i][j] = 0;
		}
	}
	
	for(int i = 32; i <= 98; i++) {
		array[i][48] = 1;
	}
	for(int i = 32; i <= 98; i++) {
		array[i][16] = 1;
	}
	
	for(int i = 16; i <= 48; i++) {
		array[32][i] = 1;
	}
	for(int i = 16; i <= 48; i++) {
		array[98][i] = 1;
	}
}

/**
 * @brief main functie.
 * @return 0 bij goed verloop.
 */

int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;

	namespace target = hwlib::target;

	auto scl = target::pin_oc(target::pins::scl);
	auto sda = target::pin_oc(target::pins::sda);
	
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	
	auto display = hwlib::glcd_oled(i2c_bus, 0x3c);
	
	display.clear();
	
	int framebuffer[128][64] = {0};
	
	resetArray(framebuffer);
	
	while(true) {
		pushBuffer(framebuffer, display);
		shiftArrayUp(framebuffer);
		display.clear();
		pushBuffer(framebuffer, display);
		resetArray(framebuffer);
		display.clear();
	}
	return 0;
}
