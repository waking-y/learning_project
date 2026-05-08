#include <stdbool.h>
#include <stdint.h>
#include "board.h"

static void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm__("nop");
    }
}

void key_on_press(void *arg)
{
    led_toggle(arg);
}

int main(void)
{
    board_lowlevel_init();
    led_init(led9);
    led_init(led10);
    botton_init(key0);

    botton_set_callback(key0, key_on_press, led10);

    while (1)
    {
        ;
    }
}
