# Embedded Learning Journey

I'm a 3rd-year Electrical Engineering student at Western Sydney University, learning embedded systems from the ground up: Arduino UNO first, then ESP32, then STM32. I'm also learning circuit design along the way, from paper schematics to KiCad and my own PCBs.

This repo is my daily log. Each folder is one Arduino sketch (open the `.ino` file in the Arduino IDE). Serial Monitor runs at **115200 baud**.

## Plan (about 15 weeks)

| Weeks | Firmware | Hardware |
|---|---|---|
| 1–4 | C basics, LEDs, buttons, sensors (Arduino UNO, then ESP32) | Schematic symbols, resistors, voltage dividers, pull-ups, transistors, start KiCad |
| 5–6 | DIY IoT: displays, Wi-Fi, phone-controlled devices | Power supplies, regulators, reading datasheets |
| 7–10 | STM32 the professional way: HAL, timers, interrupts, I2C, SPI, FreeRTOS | Analog circuits, then my first PCB (weeks 9–10) |
| 11–15 | A finished project to show employers | A custom PCB for that project, made at JLCPCB |

## Progress

| Day | Topic | Sketches |
|---|---|---|
| 1 | Blink, digital output | [day01-blink](day01-blink), [day01-led-chaser](day01-led-chaser) |
| 2 | Variables, for loops, Serial | [day02-variables-kitt](day02-variables-kitt), [day02-speed-up-celebrate](day02-speed-up-celebrate), [day02-blink-counter-serial](day02-blink-counter-serial) |
| 3 | Operators, Ohm's law, int vs float division | [day03-operators-ohms-law](day03-operators-ohms-law) |
| 4 | if/else, logic operators, analog input, buttons | [day04-if-else-voltage-warning](day04-if-else-voltage-warning), [day04-led-current-check](day04-led-current-check), [day04-button-led](day04-button-led), [day04-logic-leap-year](day04-logic-leap-year) |
| 5 | for and while loops, break, polling a button | [day05-count-up](day05-count-up), [day05-countdown](day05-countdown), [day05-even-numbers](day05-even-numbers), [day05-sum-1-to-100](day05-sum-1-to-100), [day05-resistor-sweep](day05-resistor-sweep), [day05-while-doubling](day05-while-doubling), [day05-battery-hours](day05-battery-hours), [day05-break-infinite-loop](day05-break-infinite-loop), [day05-wait-for-button](day05-wait-for-button) |
| 6 | Reading user input over Serial; Ohm's law calculator; choosing LED resistors | [day06-serial-blink-count](day06-serial-blink-count), [day06-ohms-law-calculator](day06-ohms-law-calculator), [day06-rgb-led-sequence](day06-rgb-led-sequence) |
| 7 | Review week 1; button edge detection and debounce | [day07-rgb-color-cycler](day07-rgb-color-cycler) |

## Side projects

- [Ultrasonic distance LEDs](projects/ultrasonic-distance-leds): HC-SR04 sensor turns a red LED on when something is within 10 cm.
- [Ultrasonic distance bar](projects/ultrasonic-distance-bar): a button switches it on/off; blue, green and red LEDs light up like a parking sensor as something gets closer.

## Hardware I use

Arduino UNO, breadboard, red/green/blue 5 mm LEDs, resistors (E12), 10k potentiometer, tactile push button, HC-SR04 ultrasonic sensor. ESP32 and a multimeter are on the way.

## Things I learned the hard way

- `7 / 60` is `0` in C: integer division. Write `7.0 / 60`.
- Global counters keep their value between `loop()` runs, so reset them.
- A button needs **edge detection** (act only when it changes from released to pressed) and a short **debounce** delay.
- A floating input pin reads random values; use `INPUT_PULLUP`.
- LED brightness is not proportional to current; your eyes are a bad meter.
