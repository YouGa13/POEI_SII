#ifndef STMF100REGISTER_H
#define STMF100REGISTER_H

#ifdef TESTING
	#include "stm32f103_testDriver.h"
#else
	#include "stm32f103xb.h"
#endif

typedef struct s_pin {
	GPIO_TypeDef* gpio_register;
	unsigned      pin_register;
} Pin_t;

#endif /* STMF100REGISTER_H */
