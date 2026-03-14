// clang-format off
#include "stm32f1xx_hal.h"
// clang-format on

#include "Hardware/LED.h"

#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"

void LED_init(void)
{
    GPIO_InitTypeDef Init_Struct;

    __HAL_RCC_GPIOC_CLK_ENABLE();

    Init_Struct.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
    Init_Struct.Mode  = GPIO_MODE_OUTPUT_PP;
    Init_Struct.Pull  = GPIO_PULLUP;
    Init_Struct.Speed = GPIO_SPEED_HIGH;

    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_SET);
    HAL_GPIO_Init(GPIOC, &Init_Struct);
}