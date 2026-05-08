#include "board.h"
#include "led_desc.h"
#include "botton_desc.h"

void board_lowlevel_init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOE, ENABLE); // Enable GPIOF and GPIOE  clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

// -------------------LED Description------------------
static struct led_desc _led9= {GPIOF, GPIO_Pin_9, Bit_RESET, Bit_SET};
static struct led_desc _led10 = {GPIOF, GPIO_Pin_10, Bit_RESET, Bit_SET};
led_desc_t led9 = &_led9;
led_desc_t led10 = &_led10;


// -------------------Botton Description------------------
static struct botton_desc _key0 = {
    GPIOE, GPIO_Pin_4, GPIO_PuPd_DOWN, EXTI_Trigger_Rising,
    EXTI_Line4, EXTI_PortSourceGPIOE, GPIO_PinSource4, EXTI4_IRQn,
    NULL, NULL
};
botton_desc_t key0 = &_key0;

// -------------------IRQ Handler------------------
void EXTI4_IRQHandler(void) 
{
    botton_irq_handler(key0); // 将硬件中断信号，导向你的面向对象处理框架
}
