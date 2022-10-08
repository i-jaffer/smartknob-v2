#ifndef __GC9A01_H_
#define __GC9A01_H_

#include "./hal/gc9a01_hal.h"
#include "stdio.h"
#include "stdint.h"

void GC9A01_init(void);
void GC9A01_set_brightness(uint8_t brightness);
uint8_t GC9A01_get_brightness(void);
void GC9A01_draw_point(uint16_t x,uint16_t y,uint16_t color);
void GC9A01_fill_block(uint16_t x , uint16_t y , uint16_t width , uint16_t height , uint16_t color);
void GC9A01_draw_map(uint16_t x,uint16_t y,uint16_t width , uint16_t hetght , uint16_t * color_map);
void GC9A01_sleep(void);
void GC9A01_wakeup(void);
void GC9A01_x_mirror_enable(void);
void GC9A01_x_mirror_disable(void);
void GC9A01_y_mirror_enable(void);
void GC9A01_y_mirror_disable(void);

void GC9A01_test(void);

#endif

