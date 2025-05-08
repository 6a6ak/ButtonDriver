#include <avr/io.h>
#include "driver/button_driver.h"
#include <util/delay.h>

int main(void) {
    Button btn = button_create(2, 13); // دکمه روی پین 2، LED روی 13
    button_init(&btn);

    uint8_t last_state = 0;

    while (1) {
        uint8_t current = button_pressed(&btn);
        if (current && !last_state) {
            button_toggle_led(&btn);
            _delay_ms(200); // جلوگیری از تکرار ناخواسته در شبیه‌ساز
        }
        last_state = current;
    }
}
