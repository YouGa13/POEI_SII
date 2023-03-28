#include "stm32f103xb.h"

#define DIGIT_LIST_LENGTH 11

// Structure d'un segment
typedef struct
{
    GPIO_TypeDef *gpio; // Registre correspondant au port
    char pin;           // N° de pin sur le port
} segment_t;

// Correspondance pin <-> segment
segment_t led7_pinout[8] = {
    {GPIOA, 4},  // Segment a
    {GPIOB, 0},  // Segment b
    {GPIOA, 8},  // Segment c
    {GPIOB, 10}, // Segment d
    {GPIOB, 5},  // Segment e
    {GPIOA, 1},  // Segment f
    {GPIOA, 0},  // Segment g
    {GPIOA, 7}}; // Segment h

// Comment allumer chaque segment pour afficher chaque chiffre ( dans l'ordre a b c d e f g h)
char digit[DIGIT_LIST_LENGTH] = {
    0b11111100,
    0b01100000,
    0b11011010,
    0b11110010,
    0b01100110,
    0b10110110,
    0b10111110,
    0b11100000,
    0b11111110,
    0b11110110,
    0b00000001};

void display_to_led7(char digit)
{
    // On parcours les segments
    for (int i = 0; i < 8; i++)
    {
        unsigned int segment_mask = (0b10000000 >> i); // Masque pour le segment i (ex : i=2 -> segment c -> 0b00100000)

        if (digit & segment_mask) // On masque le pattern "digit" pour savoir si on doit allumer/éteindre le segment i
        {
            unsigned int brx_mask = 1 << (led7_pinout[i].pin + 16); // Masque pour sélectionner BRx avec x le n° de pin
            led7_pinout[i].gpio->BSRR |= brx_mask;                  // Set BRx : mettre la pin x à l'état BAS pour allumer le segment
        }
        else
        {
            unsigned int bsx_mask = 1 << (led7_pinout[i].pin); // Masque pour sélectionner BSx avec x le n° de pin
            led7_pinout[i].gpio->BSRR |= bsx_mask;             // Set BSx : mettre la pin x à l'état HAUT pour éteindre le segment
        }
    }
}

void init_led7()
{
    // On parcours les segments
    for (int i = 0; i < 8; i++)
    {
        // Setup RCC
        if (led7_pinout[i].gpio == GPIOA) // Si le segment i est connecté au GPIOA
        {
            RCC->APB2ENR &= ~(0b1 << 2); // Clear le bit correspondant au GPIOA
            RCC->APB2ENR |= 0b1 << 2;    // Set le bit correspondant au GPIOA pour activer la clock sur ce port
        }
        else if (led7_pinout[i].gpio == GPIOB)
        {
            RCC->APB2ENR &= ~(0b1 << 3);
            RCC->APB2ENR |= 0b1 << 3;
        }
        else if (led7_pinout[i].gpio == GPIOC)
        {
            RCC->APB2ENR &= ~(0b1 << 4);
            RCC->APB2ENR |= 0b1 << 4;
        }
        else if (led7_pinout[i].gpio == GPIOD)
        {
            RCC->APB2ENR &= ~(0b1 << 5);
            RCC->APB2ENR |= 0b1 << 5;
        }
        else if (led7_pinout[i].gpio == GPIOE)
        {
            RCC->APB2ENR &= ~(0b1 << 6);
            RCC->APB2ENR |= 0b1 << 6;
        }

        // Setup IO mode
        if (led7_pinout[i].pin < 8) // Pour les pin 0 à 7, on utilise CRL
        {
            unsigned int clear_mask = 0b1111 << 4 * led7_pinout[i].pin; // Masque pour selectionner les 4 bits correspondant au mode de la pin du segment i
            led7_pinout[i].gpio->CRL &= ~(clear_mask);                  // Clear les 4 bits du registre GPIOx.CRL correspondant au mode

            unsigned int set_mask = 0b0010 << 4 * led7_pinout[i].pin; // Masque pour activer le mode "output in push-pull @ 2MHz" de la pin du segment i
            led7_pinout[i].gpio->CRL |= (set_mask);                   // Set les bits du registre GPIOx.CRL correspondant au mode
        }
        else // Pour les pin 8 à 15, on utilise CRH
        {
            unsigned int clear_mask = 0b1111 << 4 * (led7_pinout[i].pin - 8); // Masque pour selectionner les 4 bits correspondant au mode de la pin du segment i
            led7_pinout[i].gpio->CRH &= ~(clear_mask);                        // Clear les 4 bits du registre GPIOx.CRH correspondant au mode

            unsigned int set_mask = 0b0010 << 4 * (led7_pinout[i].pin - 8); // Masque pour activer le mode "output in push-pull @ 2MHz" de la pin du segment i
            led7_pinout[i].gpio->CRH |= (set_mask);                         // Set les bits du registre GPIOx.CRH correspondant au mode
        }
    }

    // Eteindre tous les segments
    display_to_led7(0b00000000);
}

void init_button()
{
    /* enable clock for PORTs C */
    RCC->APB2ENR &= ~(0b1 << 4); /* clear IOPCEN */
    RCC->APB2ENR |= 0b1 << 4;    /* set IOPCEN */

    GPIOC->CRH &= ~(0b1111 << 20); /* clear CNF13 */
    GPIOC->CRH |= (0b1000 << 20);  /* set CNF13 to 10 & MODE13 to 00 */
}

void wait_push_button()
{
    while (!(GPIOC->IDR & (0b1 << 13)))
        ;
    while (GPIOC->IDR & (0b1 << 13))
        ;
}

int main(void)
{
    init_led7();
    init_button();

    // display_to_led7(0b11111111); // Joyeux noël

    while (1)
    {
        // Changer le digit affiché à chaque appuis sur le bouton
        for (int i = 0; i < DIGIT_LIST_LENGTH; i++)
        {
            display_to_led7(digit[i]);
            wait_push_button();
        }
    }
}
