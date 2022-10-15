#ifndef __GC9A01_H_
#define __GC9A01_H_

#include "gc9a01_macro.h"
#include "./hal/gc9a01_hal.h"
#include "stdio.h"
#include "stdint.h"

void GC9A01_init(void);
void GC9A01_set_brightness(uint8_t brightness);
uint8_t GC9A01_get_brightness(void);
void GC9A01_fill_block(uint8_t x , uint8_t y , uint8_t width , uint8_t height , uint16_t color);
void GC9A01_draw_map(uint8_t x,uint8_t y,uint8_t width , uint8_t hetght , uint16_t * color_map);
void GC9A01_sleep(void);
void GC9A01_wakeup(void);
void GC9A01_x_mirror_enable(void);
void GC9A01_x_mirror_disable(void);
void GC9A01_y_mirror_enable(void);
void GC9A01_y_mirror_disable(void);

#if GC9A01_TEST
void GC9A01_test(void);
#endif

#endif

