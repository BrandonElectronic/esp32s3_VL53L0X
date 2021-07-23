#include "tof_test.c"
#include "vl53l0x.h"

void app_main(void)
{
uint16_t test;

vl53l0x_t * tof_obj=vl53l0x_config(I2C_NUM_1,I2C_SCL,I2C_SDA,Xshut_gpio,vl530_slave_address,Mode2v8_en);

vl53l0x_init(tof_obj);
vl53l0x_setSignalRateLimit(tof_obj,0.5);
vl53l0x_setMeasurementTimingBudget(tof_obj, 40000);
vl53l0x_startContinuous(tof_obj,800);

while(1)

{

test = vl53l0x_readRangeContinuousMillimeters(tof_obj);
//uint16_t 
//test = vl53l0x_readRangeSingleMillimeters (tof_obj);
//printf("Distance %dmm \n",(test<100?test:(test/10)));
printf("Distance %dmm \n",test);
vTaskDelay(1000/portTICK_PERIOD_MS);

}

}