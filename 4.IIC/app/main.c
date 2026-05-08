#include <stdbool.h>
#include <stdint.h>
#include "board.h"
#include <stdio.h>
#include <string.h>

static void delay_ms(volatile uint32_t count)
{
    count *= 10000;
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
    char write_str[] = "Hello, AT24C02!";
    char read_str[30] = {0};
    const uint8_t eeprom_addr = 0x00;
    char test_char = 0x55;
    char read_char = 0;

    board_lowlevel_init();
    usart1_init(debug_usart1);
    led_init(led9);
    led_init(led10);
    botton_init(key0);
    at24c02_init(at24c02);

    botton_set_callback(key0, key_on_press, led10);


    for (uint16_t i = 0; i < strlen(write_str); i++) {
        at24c02_write_byte(at24c02, eeprom_addr + i, write_str[i]);
    }
    
    at24c02_read_buffer(at24c02, eeprom_addr, (uint8_t *)read_str, strlen(write_str)); // 读取所有写入的数据，包括特殊字符
    at24c02_write_byte(at24c02, eeprom_addr, test_char); // 在字符串末尾写入一个特殊字符，验证边界条件
    read_char = at24c02_read_byte(at24c02, eeprom_addr); // 读取所有写入的数据，包括特殊字符

    printf("EEPROM Test\r\n");
    printf("Write String: %c\r\n", test_char);
    printf("Write Buffer: %s\r\n", write_str);
    printf("Read String : %c\r\n", read_char);
    printf("Read Buffer : %s\r\n", read_str);


    // 步骤 C: 验证数据是否完全一致
    if (strcmp(&test_char, &read_char) == 0) {
        // 如果字符串一字不差地被成功存入并读出，点亮 LED9
        printf("Result: EEPROM Test Success!\r\n");
        led_on(led9);
    } else {
        printf("Result: EEPROM Test Failed!\r\n");
    }

    if (strcmp(write_str, read_str) == 0) {
        printf("Buffer Test: Success!\r\n");
        led_on(led10);
    } else {
        printf("Buffer Test: Failed!\r\n");
    }

    while (1)
    {
        ;
    }
}
