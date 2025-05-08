#include "button_driver.h"

Button button_create(uint8_t button_pin, uint8_t led_pin) {
    Button btn = {0};

    if (button_pin <= 7) {
        btn.ddr = &DDRD;
        btn.port = &PORTD;
        btn.pin = &PIND;
        btn.bit = button_pin;
    } else {
        btn.ddr = &DDRB;
        btn.port = &PORTB;
        btn.pin = &PINB;
        btn.bit = button_pin - 8;
    }

    if (led_pin <= 7) {
        btn.led_ddr = &DDRD;
        btn.led_port = &PORTD;
        btn.led_bit = led_pin;
    } else {
        btn.led_ddr = &DDRB;
        btn.led_port = &PORTB;
        btn.led_bit = led_pin - 8;
    }

    return btn;
}

void button_init(Button* btn) {
    // پیکربندی پین دکمه به عنوان ورودی با pull-up
    *(btn->ddr) &= ~(1 << btn->bit);
    *(btn->port) |= (1 << btn->bit);

    // پیکربندی پین LED به عنوان خروجی
    *(btn->led_ddr) |= (1 << btn->led_bit);
}

uint8_t button_pressed(Button* btn) {
    // وقتی دکمه فشرده شود (پین پایین = 0)، مقدار برمی‌گردد 1
    return !((*(btn->pin)) & (1 << btn->bit));
}

void button_toggle_led(Button* btn) {
    *(btn->led_port) ^= (1 << btn->led_bit);
}
