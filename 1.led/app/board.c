#include "board.h"
#include "led_desc.h"

void board_lowlevel_init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
}

static struct led_desc _led1 = { GPIOF, GPIO_Pin_9, Bit_RESET, Bit_SET};
static struct led_desc _led2 = { GPIOF, GPIO_Pin_10, Bit_RESET, Bit_SET};

led_desc_t led1 = &_led1;
led_desc_t led2 = &_led2;
