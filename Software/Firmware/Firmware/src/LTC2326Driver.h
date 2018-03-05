/*
 * LTC2326Driver.h
 *
 * Created: 24/02/2018 15:36:38
 *  Author: reuben
 */ 


#ifndef LTC2326DRIVER_H_
#define LTC2326DRIVER_H_

#include <stdint.h>
#include <asf.h>


#define CNV_ADCPIN		PIO_PC31_IDX//input(ADC) rising edge starts a new conversion
#define BUSY_ADCPIN		PIO_PB3_IDX//output goes high at start of new convesion, returns low when finished 
#define SCK_ADCPIN		PIO_PA0_IDX//input serial data clock input, data shifted out on the rising edge of clk
#define SDO_ADCPIN		PIO_PC30_IDX//output serial data output (2's complement format)
#define CHAIN_ADCPIN	PIO_PA19_IDX//input chain mode selector. when low, operates in normal mode
#define RDLSDI_ADCPIN	PIO_PB2_IDX//input whn chain is low the is a bus enable input, else its a data input


void InitADC(void);
uint32_t ReadADC(void);


#endif /* LTC2326DRIVER_H_ */