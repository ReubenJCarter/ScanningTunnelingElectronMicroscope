/*
 * DAC80004Driver.h
 *
 * Created: 18/02/2018 20:59:55
 *  Author: reuben
 */ 


#ifndef DAC80004DRIVER_H_
#define DAC80004DRIVER_H_

#include <stdint.h>

#define SCLK_DACPIN		PIO_PD26_IDX//Serial interface shift clock
#define SDIN_DACPIN		PIO_PC31_IDX//Serial interface digital input
#define NSYNC_DACPIN	PIO_PD30_IDX//Serial interface synchronization, active low
#define SDO_DACPIN		PIO_PA19_IDX//Serial interface digital output for readback and daisy chaining
#define NCLR_DACPIN		PIO_PC13_IDX//Clear DAC pin, falling edge sensitive
#define NLDAC_DACPIN	PIO_PC30_IDX//Load DAC pin, active low
#define POR_DACPIN		PIO_PA17_IDX//power on reset pin. 0 at power on = zero output, 1 = mid scale

void DACInit(void);
void DACWriteCommand(uint32_t command);
void DACWriteChannel(int c, uint16_t d);


#endif /* DAC80004DRIVER_H_ */