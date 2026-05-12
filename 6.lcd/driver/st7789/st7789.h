#ifndef __ST7789_H__
#define __ST7789_H__

#include <stdbool.h>
#include <stdint.h>
#include "font.h"

#define ST7789_WIDTH    240
#define ST7789_HEIGHT   320

#define mkcolor(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3))

void st7789_init(void);
void st7789_fill_color(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color);
void st7789_write_ascii(uint16_t x, uint16_t y, char *str, uint16_t color, uint16_t bg_color, const font_t *font);

#endif /* __ST7789_H__ */
