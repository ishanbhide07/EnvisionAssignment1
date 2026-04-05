#include <stdint.h>
#define RCC_BASE        0x40023800
#define GPIOA_BASE      0x40020000
#define TIM6_BASE       0x40001000
#define RCC_AHB1ENR     RCC_BASE + 0x30
#define RCC_APB1ENR     RCC_BASE + 0x40
#define GPIOA_MODER     GPIOA_BASE + 0x00
#define GPIOA_ODR       GPIOA_BASE + 0x14
#define TIM6_CR1        TIM6_BASE + 0x00
#define TIM6_SR         TIM6_BASE + 0x10
#define TIM6_PSC        TIM6_BASE + 0x28
#define TIM6_ARR        TIM6_BASE + 0x2C
int main(void)
{
    RCC_AHB1ENR |= (1U << 0);
    GPIOA_MODER |= (1U << 10);
    RCC_APB1ENR |= (1U << 4);
    TIM6_CR1 |= (1U << 0);
    TIM6_PSC  = 15999;
    TIM6_ARR  = 1999;
    TIM6_CR1 |= (1U << 7);
    while (1)
    {
        if (TIM6_SR & (1U << 0))
        {
            GPIOA_ODR ^= (1U << 5);
            TIM6_SR &= ~(1U << 0);
        }
    }
}
