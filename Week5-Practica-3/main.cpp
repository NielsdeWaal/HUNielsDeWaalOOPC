/**
 * @file main.cpp
 * @date 21/5/17
 * @author Niels de Waal
 * Jorn Bunk
 * @brief Code voor practicum week 4 opdracht 2
 * 
 * Code voor het laten branden van een rij led lampjes.
 * Deze worden aan de hand van een counter (die door knopjes worden bestuurd), 
 * incrementeel aangestuurd.
 */

#include "hwlib.hpp"
#include "hwlib-hc595.hpp"

class pin_out_invert : public hwlib::pin_out {
private: 
	hwlib::pin_out &slave;
public:
	pin_out_invert(hwlib::pin_out & slave):
	slave(slave)
	{}
	
	void set(bool x, hwlib::buffering buf = hwlib::buffering::unbuffered) {
		slave.set(!x);
	}
};

class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 4 ];     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( 
      bool v, 
      hwlib::buffering buf = hwlib::buffering::unbuffered  
   ){
      for( auto p  : list ){
          p->set( v );
      }
   }
};

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   	namespace target = hwlib::target;
	auto ds   = target::pin_out( target::pins::d5 ); //SER
	auto shcp = target::pin_out( target::pins::d3 ); //SRCLK
	auto stcp = target::pin_out( target::pins::d4 ); //RCLK

	auto led5 = hwlib::target::pin_out( hwlib::target::pins::d10 );
	auto led6 = hwlib::target::pin_out( hwlib::target::pins::d9 );
	auto led7 = hwlib::target::pin_out( hwlib::target::pins::d8 );
	auto led8 = hwlib::target::pin_out( hwlib::target::pins::d7 );

	auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		shcp, 
		ds, 
		hwlib::pin_in_dummy 
	);

	auto chip = hwlib::hc595(spi, stcp);

	auto led5inv = pin_out_invert(led5);
	auto led6inv = pin_out_invert(led6);
	auto led7inv = pin_out_invert(led7);
	auto led8inv = pin_out_invert(led8);
	
	auto inverted = pin_out_all(led5inv, led6inv, led7inv, led8inv);
	auto normal = pin_out_all(chip.p1, chip.p2, chip.p3, chip.p4);
	
	auto all = pin_out_all(normal, inverted);
	
	hwlib::kitt(all);
}