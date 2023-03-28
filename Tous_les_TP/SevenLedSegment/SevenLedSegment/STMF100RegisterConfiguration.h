#ifndef STMF100REGISTER_CONFIGURATION_H
#define STMF100REGISTER_CONFIGURATION_H

#include "STMF100Register.h"

/*Utility Section*/
typedef enum e_ope { SET, CLEAR, TOGGLE } ope_t;
typedef enum e_iomode { READ = 0b1000, WRITE_2MHz = 0b0010, RESET = 0b1111 } iomode_t;
void modify_Memory_With_Operator_Value(uint32_t* adresse, ope_t ope_type, int value, unsigned char offset);
/*Utility Section*/

/* CLOCK Section */
uint8_t get_APB2EN_register(GPIO_TypeDef* gpio_register);
void enable_clock(Pin_t pin);
/* CLOCK Section */

/* GPIO->CR Section */
void operation_CR(Pin_t* pin, ope_t ope_type, int value);
void init_GPIO_Pin(Pin_t pin, iomode_t iomode);
/* GPIO->CR Section */

/* GPIO->ODR Section */
void operation_ODR(Pin_t* pin, ope_t ope_type);

/* GPIO->BSRR Section */
void operation_BSRR(Pin_t* pin, ope_t ope_type);

#endif /* STMF100REGISTER_CONFIGURATION_H */

bool isPattternInMemoryOffset(uint32_t registre, uint8_t offset, int pattern, int patternBits);
