#ifndef __GC9A01_HAL_H_
#define __GC9A01_HAL_H_

#include "stdint.h"

void gc9a01_hal_init(void);
void gc9a01_hal_delay_ms(uint16_t ms);
void gc9a01_hal_hard_reset(void);
void gc9a01_hal_data_send( uint8_t *  data ,uint16_t len );
void gc9a01_hal_cmd_send( uint8_t * cmd , uint16_t len);
void gc9a01_hal_cmd_send_with_param( uint8_t cmd , uint8_t *param , uint8_t dat_len );
void gc9a01_hal_blk_pwm_set(uint8_t percent);

#endif

