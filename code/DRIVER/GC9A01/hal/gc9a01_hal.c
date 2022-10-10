//encode : utf-8
#include "gc9a01_hal.h"

//hal realize include
#include "gpio.h"
#include "spi.h"
#include "FreeRTOS.h"
#include "task.h"

#define PIN_SET(PIN)    HAL_GPIO_WritePin( LCD_##PIN##_GPIO_Port , LCD_##PIN##_Pin , (GPIO_PinState)SET )
#define PIN_RESET(PIN)  HAL_GPIO_WritePin( LCD_##PIN##_GPIO_Port , LCD_##PIN##_Pin , (GPIO_PinState)RESET )

//实现以下宏定义即可完成移植 只重写宏仅适用与同步实现的4线spi接口以及同步实现并口的移植
//暂时不支持异步实现，异步实现会导致DC引脚错误，需要加入互斥锁或者排队机制才能使用异步实现
#define RES_SET()       PIN_SET(RES)
#define RES_RESET()     PIN_RESET(RES)
#define CS_SET()        PIN_SET(CS)
#define CS_RESET()      PIN_RESET(CS)
#define DC_SET()        PIN_SET(DC)
#define DC_RESET()      PIN_RESET(DC)
#define SEND(dat,len)   HAL_SPI_Transmit( &hspi1 , (uint8_t*)dat, len, 1000 )
#define DELAY_MS(ms)        vTaskDelay( ms/portTICK_PERIOD_MS )
#define PWM_DUTY_SET(percent)   PIN_SET(BLK)

void gc9a01_hal_init(){
    //MX_SPI1_Init();
    //MX_GPIO_Init();
    PIN_SET(BLK);
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
    gc9a01_hal_blk_pwm_set(100);
}

void gc9a01_hal_data_send( uint8_t *  data ,uint16_t len ){
    DC_SET();
    CS_RESET();
    SEND(data,len);
    CS_SET();
}

void gc9a01_hal_cmd_send( uint8_t * cmd , uint16_t len){
    DC_RESET();
    CS_RESET();
    SEND(cmd,len);
    CS_SET();
}

void gc9a01_hal_cmd_send_with_param( uint8_t  cmd , uint8_t *param , uint8_t  dat_len ){
    DC_RESET();
    CS_RESET();
    SEND(&cmd,1);
    if( param ){
        DC_SET();
        SEND(param,dat_len);
    }
    CS_SET();
}

void gc9a01_hal_blk_pwm_set(uint8_t  percent){
    PWM_DUTY_SET(percent);
}

