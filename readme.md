# Button-Controlled LED Driver (AVR - Bare Metal)

This project demonstrates how to implement a **bare-metal button driver** for AVR microcontrollers (such as the ATmega328p used in Arduino Uno).  
The goal is to turn an LED on or off **only when a button is pressed** — no blinking, no noise, just clean digital control.

---

## 🔧 Project Overview

- **Microcontroller:** ATmega328p (Arduino Uno)
- **Button:** Connected to digital pin 2 (with internal pull-up)
- **LED:** Built-in LED on digital pin 13
- **Debounce:** Basic toggle logic with delay
- **Environment:** Works with [Wokwi Simulator](https://wokwi.com) and real hardware
- **No Arduino functions used** (`digitalRead`, `digitalWrite`, etc. are not used)

---

## 📁 File Structure

```text
.
├── main.c                     # Main loop: polls button and toggles LED
├── driver/
│   ├── button_driver.h       # Driver header file
│   └── button_driver.c       # Driver source file
├── makefile                  # Compiles .elf and .hex using avr-gcc
└── README.md                 # This file
