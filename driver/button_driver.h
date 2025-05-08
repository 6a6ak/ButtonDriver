#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include <stdint.h>
#include <avr/io.h>

typedef struct {
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t* pin;
    uint8_t bit;

    volatile uint8_t* led_ddr;
    volatile uint8_t* led_port;
    uint8_t led_bit;
} Button;

Button button_create(uint8_t button_pin, uint8_t led_pin);
void button_init(Button* btn);
uint8_t button_pressed(Button* btn);
void button_toggle_led(Button* btn);

#endif
