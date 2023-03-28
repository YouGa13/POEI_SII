#ifndef STMF100_testDriver_H
#define STMF100_testDriver_H

#include <stdint.h>

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
} GPIO_TypeDef;

typedef struct
{
	uint32_t APB2ENR;
} RCC_TypeDef;

GPIO_TypeDef GPIOA_ = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
};
#define GPIOA  (&GPIOA_)

GPIO_TypeDef GPIOB_ = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
};
#define GPIOB (&GPIOB_)

GPIO_TypeDef GPIOC_ = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
};
#define GPIOC (&GPIOC_)

GPIO_TypeDef GPIOD_ = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
};
#define GPIOD (&GPIOD_)

GPIO_TypeDef GPIOE_ = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
};
#define GPIOE (&GPIOE_)

RCC_TypeDef RCC_ = {
    0x0,
};
#define RCC (&RCC_)

#endif /* STMF100_testDriver_H */
