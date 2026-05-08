#ifndef __BOARD_H_
#define __BOARD_H_

#include "led.h"
#include "botton.h"
#include <stddef.h>

extern led_desc_t led9;
extern led_desc_t led10;
extern botton_desc_t key0;

void board_lowlevel_init(void);

#endif /* __BOARD_H_ */
