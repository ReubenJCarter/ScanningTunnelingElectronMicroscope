/*
 * DAC80004Driver.h
 *
 * Created: 18/02/2018 20:59:55
 *  Author: reuben
 */ 


#ifndef DAC80004DRIVER_H_
#define DAC80004DRIVER_H_

#include <stdint.h>

#define SCLK_DACPIN //Serial interface shift clock
#define SDIN_DACPIN //Serial interface digital input
#define NSYNC_DACPIN //Serial interface synchronization, active low
#define SDO_DACPIN //Serial interface digital output for readback and daisy chaining
#define NCLR_DACPIN //Clear DAC pin, falling edge sensitive
#define NLDAC_DACPIN //Load DAC pin, active low
#define POR_DACPIN //power on reset pin. 0 at power on = zero output, 1 = mid scale

void DACInit(void);
void DACWriteCommand(uint32_t command);
void DACWriteChannel(int c, uint16_t d);


#endif /* DAC80004DRIVER_H_ */