/*
 * DAC80004Driver.c
 *
 * Created: 18/02/2018 22:01:22
 *  Author: reuben
 */ 

#include "DAC80004Driver.h"

void DACInit(void)
{
	//set all the pin modes
	ioport_set_pin_dir(SCLK_DACPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(SDIN_DACPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(NSYNC_DACPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(SDO_DACPIN, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(NCLR_DACPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(NLDAC_DACPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(POR_DACPIN, IOPORT_DIR_OUTPUT);
	
	
	//make POR_DACPIN set to 1 at start up to set to mid scale
	ioport_set_pin_level(POR_DACPIN, 1);
	
	//set to nSync line to high as no command is currently being sent
	ioport_set_pin_level(NSYNC_DACPIN, 1);
	
	//make clr high for a bit and then low for a bit and then high again to reset chip
	ioport_set_pin_level(NCLR_DACPIN, 1);
	ioport_set_pin_level(NCLR_DACPIN, 0);
	ioport_set_pin_level(NCLR_DACPIN, 1);
	
	//pull nLDAC to low to put the chip into synchronous mode. This means that as soon as a command has been sent the shift register copied to the actual DAC buffer(I think)
	ioport_set_pin_level(NLDAC_DACPIN, 0);
}

void DACWriteCommand(uint32_t command)
{
	//set sync to low to start writing to the shift register on clock fall.
	
	//set SCLK to high
	
	//wait for  abit
	
	//for every bit (32)
	
		//set SDIN 
		
		//set SCLK to high
	
		//wait a bit
		
		//set SCLK to low 
		
		//wait for a bit
		
	//set SCLK to high 
	
	//wait for  a bit
	
	//set sync to high 
	
}

void DACWriteChannel(int c, uint16_t d)
{
	
}