#include "STMF100RegisterConfiguration.h"

/*Utility Section*/
void modify_Memory_With_Operator_Value(uint32_t* adresse, ope_t ope_type, int value, unsigned char offset) {
    if (ope_type == CLEAR) {
        *adresse &= ~(value << offset);
    }
    else if (ope_type == SET) {
        *adresse |= value << offset;
    }
    else if (ope_type == TOGGLE) {
        *adresse ^= value << offset;
    }
}
/*Utility Section*/

/* CLOCK Section */
uint8_t get_APB2EN_register(GPIO_TypeDef* gpio_register) {
    if (gpio_register == NULL) {
        return NULL;
    }
    int offset = 0;
    if (gpio_register == GPIOA) {
        offset = 2;
    }
    else if (gpio_register == GPIOB) {
        offset = 3;
    }
    else if (gpio_register == GPIOC) {
        offset = 4;
    }
    else if (gpio_register == GPIOD) {
        offset = 5;
    }
    else if (gpio_register == GPIOE) {
        offset = 6;
    }
    return offset;
}

void enable_clock(Pin_t pin) {
    int offset = get_APB2EN_register(pin.gpio_register);
    uint32_t* adresseRegister = RCC->APB2ENR;
    modify_Memory_With_Operator_Value(adresseRegister, CLEAR, 1, offset);
    modify_Memory_With_Operator_Value(adresseRegister, SET, 1, offset);
}
/* CLOCK Section */

/* GPIO->CR Section */
void operation_CR(Pin_t* pin, ope_t ope_type, int value) {
    uint32_t* adresseRegistre = (pin->pin_register < 8) ? pin->gpio_register->CRL : pin->gpio_register->CRH;
    modify_Memory_With_Operator_Value(adresseRegistre, ope_type, value, 4 * pin->pin_register % 8);
}
void init_GPIO_Pin(Pin_t pin, iomode_t iomode) {
    enable_clock(pin);
    operation_CR(&pin, CLEAR, RESET);
    operation_CR(&pin, SET, iomode);
}
/* GPIO->CR Section */

/* GPIO->CR Section */
void operation_ODR(Pin_t* pin, ope_t ope_type) {
    uint32_t* adresseRegistre = pin->gpio_register->ODR;
    modify_Memory_With_Operator_Value(adresseRegistre, ope_type, 1, pin->pin_register);
}
/* GPIO->CR Section */

/* GPIO->BSRR Section */
void operation_BSRR(Pin_t* pin, ope_t ope_type) {
    int offset = pin->pin_register;
    if (ope_type == CLEAR) {
        offset += 16;
    }
    uint32_t* adresseRegistre = pin->gpio_register->BSRR;
    modify_Memory_With_Operator_Value(adresseRegistre, SET, 1, offset);
}
/* GPIO->BSRR Section */

bool isPattternInMemoryOffset(uint32_t registre, uint8_t offset, int pattern, int patternBits) {
    return false;
};


