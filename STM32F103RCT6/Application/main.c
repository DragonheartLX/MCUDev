#include <stm32f1xx_hal.h>

#include "delay/delay.h"
#include "led.h"
#include "sys/sys.h"

int main(void)
{
    HAL_Init();                     //初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
    LED_Init();                     //初始化LED

    while (1)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET); //LED0亮
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);   //LED1灭
        delay_ms(500);                                        //延时500ms
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);   //LED0灭
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET); //LED1亮
        delay_ms(500);                                        //延时500ms
    }
}