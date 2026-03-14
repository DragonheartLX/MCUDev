#include "main.h"

#include "Hardware/LED.h"
#include "delay.h"
#include "sys.h"

int main(void)
{
    HAL_Init();
    Stm32_Clock_Init(RCC_PLL_MUL9);
    delay_init(72);
    LED_Init();
    while (1)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET); //LED0 亮
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);   //LED1 灭
        delay_ms(500);                                        //延时 500ms

        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);   //LED0 灭
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET); //LED1 亮
        delay_ms(500);                                        //延时 500ms
    }
}

void Error_Handler(void)
{
    __disable_irq();
    while (1)
    {
    }
}
#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {}
#endif /* USE_FULL_ASSERT */
