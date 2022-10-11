#include "gc9a01.h"

#define GC9A01_send_color(color,len)	gc9a01_hal_data_send( (uint8_t*)color , len*2 )

static void GC9A01_set_region(uint8_t x , uint8_t y , uint8_t width , uint8_t height){
	uint8_t data[4];

	/*Column addresses*/
	data[0] = 0;
	data[1] = x;
	data[2] = 0;
	data[3] = x+width;
	gc9a01_hal_cmd_send_with_param( 0x2A , data , 4 );

	/*Page addresses*/
	data[0] = 0;
	data[1] = y;
	data[2] = 0;
	data[3] = y+height;
	gc9a01_hal_cmd_send_with_param( 0x2B , data , 4 );

	gc9a01_hal_cmd_send_with_param( 0x2C , NULL , 1);
}

void GC9A01_init(){
	gc9a01_hal_init();

    gc9a01_hal_hard_reset();
    gc9a01_hal_delay_ms(100);

    gc9a01_hal_cmd_send_with_param( 0xEF, (uint8_t*) NULL, 0);
	gc9a01_hal_cmd_send_with_param( 0xEB, (uint8_t*) "\x14", 1);
    gc9a01_hal_cmd_send_with_param( 0xFE, (uint8_t*) NULL, 0);
	gc9a01_hal_cmd_send_with_param( 0xEF, (uint8_t*) NULL, 0);
	gc9a01_hal_cmd_send_with_param( 0xEB, (uint8_t*) "\x14", 1);
	gc9a01_hal_cmd_send_with_param( 0x84, (uint8_t*) "\x40", 1);
	gc9a01_hal_cmd_send_with_param( 0x85, (uint8_t*) "\xFF", 1);
	gc9a01_hal_cmd_send_with_param( 0x86, (uint8_t*) "\xFF", 1);
	gc9a01_hal_cmd_send_with_param( 0x87, (uint8_t*) "\xFF", 1);
	gc9a01_hal_cmd_send_with_param( 0x88, (uint8_t*) "\x0A", 1);
	gc9a01_hal_cmd_send_with_param( 0x89, (uint8_t*) "\x21", 1);
	gc9a01_hal_cmd_send_with_param( 0x8A, (uint8_t*) "\x00", 1);
	gc9a01_hal_cmd_send_with_param( 0x8B, (uint8_t*) "\x80", 1);
	gc9a01_hal_cmd_send_with_param( 0x8C, (uint8_t*) "\x01", 1);
	gc9a01_hal_cmd_send_with_param( 0x8D, (uint8_t*) "\x01", 1);
	gc9a01_hal_cmd_send_with_param( 0x8E, (uint8_t*) "\xFF", 1);
	gc9a01_hal_cmd_send_with_param( 0x8F, (uint8_t*) "\xFF", 1);
	gc9a01_hal_cmd_send_with_param( 0xB6, (uint8_t*) "\x00\x00", 2);
	gc9a01_hal_cmd_send_with_param( 0x3A, (uint8_t*) "\x55", 1); // COLMOD
	gc9a01_hal_cmd_send_with_param( 0x90, (uint8_t*) "\x08\x08\x08\x08", 4);
	gc9a01_hal_cmd_send_with_param( 0xBD, (uint8_t*) "\x06", 1);
	gc9a01_hal_cmd_send_with_param( 0xBC, (uint8_t*) "\x00", 1);
	gc9a01_hal_cmd_send_with_param( 0xFF, (uint8_t*) "\x60\x01\x04", 3);
	gc9a01_hal_cmd_send_with_param( 0xC3, (uint8_t*) "\x13", 1);
	gc9a01_hal_cmd_send_with_param( 0xC4, (uint8_t*) "\x13", 1);
	gc9a01_hal_cmd_send_with_param( 0xC9, (uint8_t*) "\x22", 1);
	gc9a01_hal_cmd_send_with_param( 0xBE, (uint8_t*) "\x11", 1);
	gc9a01_hal_cmd_send_with_param( 0xE1, (uint8_t*) "\x10\x0E", 2);
	gc9a01_hal_cmd_send_with_param( 0xDF, (uint8_t*) "\x21\x0c\x02", 3);
	gc9a01_hal_cmd_send_with_param( 0xF0, (uint8_t*) "\x45\x09\x08\x08\x26\x2A", 6);
 	gc9a01_hal_cmd_send_with_param( 0xF1, (uint8_t*) "\x43\x70\x72\x36\x37\x6F", 6);
 	gc9a01_hal_cmd_send_with_param( 0xF2, (uint8_t*) "\x45\x09\x08\x08\x26\x2A", 6);
 	gc9a01_hal_cmd_send_with_param( 0xF3, (uint8_t*) "\x43\x70\x72\x36\x37\x6F", 6);
	gc9a01_hal_cmd_send_with_param( 0xED, (uint8_t*) "\x1B\x0B", 2);
	gc9a01_hal_cmd_send_with_param( 0xAE, (uint8_t*) "\x77", 1);
	gc9a01_hal_cmd_send_with_param( 0xCD, (uint8_t*) "\x63", 1);
	gc9a01_hal_cmd_send_with_param( 0x70, (uint8_t*) "\x07\x07\x04\x0E\x0F\x09\x07\x08\x03", 9);
	gc9a01_hal_cmd_send_with_param( 0xE8, (uint8_t*) "\x34", 1);
	gc9a01_hal_cmd_send_with_param( 0x62, (uint8_t*) "\x18\x0D\x71\xED\x70\x70\x18\x0F\x71\xEF\x70\x70", 12);
	gc9a01_hal_cmd_send_with_param( 0x63, (uint8_t*) "\x18\x11\x71\xF1\x70\x70\x18\x13\x71\xF3\x70\x70", 12);
	gc9a01_hal_cmd_send_with_param( 0x64, (uint8_t*) "\x28\x29\xF1\x01\xF1\x00\x07", 7);
	gc9a01_hal_cmd_send_with_param( 0x66, (uint8_t*) "\x3C\x00\xCD\x67\x45\x45\x10\x00\x00\x00", 10);
	gc9a01_hal_cmd_send_with_param( 0x67, (uint8_t*) "\x00\x3C\x00\x00\x00\x01\x54\x10\x32\x98", 10);
	gc9a01_hal_cmd_send_with_param( 0x74, (uint8_t*) "\x10\x85\x80\x00\x00\x4E\x00", 7);
    gc9a01_hal_cmd_send_with_param( 0x98, (uint8_t*) "\x3e\x07", 2);
	gc9a01_hal_cmd_send_with_param( 0x35, (uint8_t*) NULL, 0);
	gc9a01_hal_cmd_send_with_param( 0x21, (uint8_t*) NULL, 0);
	gc9a01_hal_cmd_send_with_param( 0x11, (uint8_t*) NULL, 0);

    gc9a01_hal_delay_ms(120);

	gc9a01_hal_cmd_send_with_param( 0x29, (uint8_t*) NULL, 0);
	gc9a01_hal_delay_ms(20);
}

void GC9A01_set_brightness(uint8_t brightness){
	gc9a01_hal_blk_pwm_set(brightness);
}

void GC9A01_test(){
	uint16_t color = 0xF800>>11;	//RED
	GC9A01_set_region( 0 , 0 , 239 , 239 );
	for( uint16_t temp = 0 ; temp < 240*240 ; temp++ ){
		GC9A01_send_color( &color , 1 );
	}
}

uint8_t GC9A01_get_brightness(){
	return 0;
}
