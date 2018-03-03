/*
 * LTC2326Driver.c
 *
 * Created: 24/02/2018 15:37:00
 *  Author: reuben
 */ 

#include "LTC2326Driver.h"

#include "asf.h"


void InitADC(void)
{
	//set all the pin modes
	ioport_set_pin_dir(CNV_ADCPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(BUSY_ADCPIN, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SCK_ADCPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(SDO_ADCPIN, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(CHAIN_ADCPIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(RDLSDI_ADCPIN, IOPORT_DIR_OUTPUT);
	
	//make CHAIN_ADCPIN set to 0 at start up to set the device to normal mode
	ioport_set_pin_level(CHAIN_ADCPIN, 0);
	
	//make RDLSDI_ADCPIN set to 0 at start up to enable thew data
	ioport_set_pin_level(RDLSDI_ADCPIN, 0);
	
	//set cnv to low to start with
	ioport_set_pin_level(CNV_ADCPIN, 0);
	
	//sck to low to start
	ioport_set_pin_level(SCK_ADCPIN, 0);
	
}

uint16_t ReadADC(void)
{
	
	//set cnv (convert) signal to high to start a conversion
	ioport_set_pin_level(CNV_ADCPIN, 1);
	
	//wait some time
	delay_us(10);
	
	//wait for Busy to be low 
	while(ioport_get_pin_level(BUSY_ADCPIN)); 
	
	//wait some time
	delay_us(10);
	
	//reset convert signal
	ioport_set_pin_level(CNV_ADCPIN, 0);
	
	//clk low
	ioport_set_pin_level(SCK_ADCPIN, 0);
	
	//read each bit
	uint16_t finalData = 0; 
	for(int i = 0; i < 16; i++)
	{
		//read data 
		int dataBit = ioport_get_pin_level(SDO_ADCPIN);
		
		finalData = (finalData << 1) | (dataBit & 0x1);
		
		//wait a bit
		delay_us(10);
		
		//clk next data value
		ioport_set_pin_level(SCK_ADCPIN, 1);
		
		//wait a bit
		delay_us(10);
		
		//clk low
		ioport_set_pin_level(SCK_ADCPIN, 0);
	}
	
	return finalData;
}
