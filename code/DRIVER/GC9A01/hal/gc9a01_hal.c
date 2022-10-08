#include "gc9a01_hal.h"

#include "gpio.h"
#include "spi.h"
#include "FreeRTOS.h"
#include "task.h"

#define RES_RESET()   HAL_GPIO_WritePin( GPIOA , GPIO_PIN_0 , (GPIO_PinState)RESET )
#define RES_SET()     HAL_GPIO_WritePin( GPIOA , GPIO_PIN_0 , (GPIO_PinState)SET )
#define CS_SET()
#define CS_RESET()
#define DC_SET()
#define DDC_RESET()
#define SPI_SEND(dat,len)   HAL_SPI_Transmit( &hspi1 , (uint8_t*)dat, len, 1000 )
#define DELAY_MS(ms)        vTaskDelay( ms/portTICK_PERIOD_MS )
#define PWM_WITDH_SET(us)
#define PWM_CYCLE_SET(us)

void gc9a01_hal_init(){
    //MX_SPI1_Init();
    //MX_GPIO_Init();
}

void gc9a01_hal_delay_ms(uint16_t ms){
    DELAY_MS(ms);
}

void gc9a01_hal_hard_reset(void){
    CS_RESET();
    RES_SET();
    DELAY_MS(50);
    RES_RESET();
    DELAY_MS(50);
    RES_SET();
    DELAY_MS(150);
    CS_SET();
}

void gc9a01_hal_data_send( uint8_t *  data ,uint16_t len ){
    DC_SET();
    CS_SET();
    SPI_SEND(data,len);
    CS_RESET();
}

void gc9a01_hal_cmd_send( uint8_t * cmd , uint16_t len){
    DDC_RESET();
    CS_SET();
    SPI_SEND(cmd,len);
    CS_RESET();
}

void gc9a01_hal_cmd_send_with_param( uint8_t  cmd , uint8_t *param , uint8_t  dat_len ){

}

void gc9a01_hal_blk_pwm_set(uint8_t  percent){
    PWM_CYCLE_SET(1000);
    PWM_WITDH_SET(percent*10);
}

