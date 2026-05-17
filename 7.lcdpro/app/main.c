#include <stdint.h>
#include "stm32f4xx.h"
#include "board.h"
#include "st7789_desc.h"
#include "st7789.h"
#include "image.h"
#include "cpu_delay.h"

#define delay_ms(ms)  cpu_delay((ms)*1000)

int main(void)
{
    board_lowlevel_init();
    ST7789_Init();
    ST7789_Clear(WHITE);
    delay_ms(500);
    
    ST7789_Clear(BLACK);
    delay_ms(500);
    
    // 颜色方块
    ST7789_FillRect(20, 20, 100, 100, RED);
    ST7789_FillRect(120, 20, 100, 100, GREEN);
    ST7789_FillRect(20, 120, 100, 100, BLUE);
    ST7789_FillRect(120, 120, 100, 100, YELLOW);
    delay_ms(1000);
    
    
    // 显示英文字符串 
    ST7789_Clear(BLACK);
    ST7789_ShowString(10, 10, "Hello STM32F407!", GREEN, BLACK, 16, 0);
    ST7789_ShowString(10, 30, "ST7789 SPI LCD", CYAN, BLACK, 16, 0);
    ST7789_ShowString(10, 50, "Color: RGB565", MAGENTA, GREEN, 32, 0);
    delay_ms(2000);
    
    // 显示图片 
    ST7789_Clear(BLACK);
    ST7789_ShowImage(0, 0, &my_demo_ikun);

    
    while (1)
    {
        ;
    }
}
