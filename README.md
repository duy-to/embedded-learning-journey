# Embedded Learning Journey

I'm a 3rd-year Electrical Engineering student at Western Sydney University, learning embedded systems from the ground up: Arduino UNO first, then ESP32, then STM32. I'm also learning circuit design along the way, from paper schematics to KiCad and my own PCBs.

This repo is my daily log. Each `dayNN` folder holds that day's sketches, one folder per sketch (open the `.ino` file in the Arduino IDE). Serial Monitor runs at **115200 baud**.

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
| 1 | Blink, digital output | [blink](day01/blink), [led-chaser](day01/led-chaser) |
| 2 | Variables, for loops, Serial | [variables-kitt](day02/variables-kitt), [speed-up-celebrate](day02/speed-up-celebrate), [blink-counter-serial](day02/blink-counter-serial) |
| 3 | Operators, Ohm's law, int vs float division | [operators-ohms-law](day03/operators-ohms-law) |
| 4 | if/else, logic operators, analog input, buttons | [if-else-voltage-warning](day04/if-else-voltage-warning), [led-current-check](day04/led-current-check), [button-led](day04/button-led), [logic-leap-year](day04/logic-leap-year) |
| 5 | for and while loops, break, polling a button | [count-up](day05/count-up), [countdown](day05/countdown), [even-numbers](day05/even-numbers), [sum-1-to-100](day05/sum-1-to-100), [resistor-sweep](day05/resistor-sweep), [while-doubling](day05/while-doubling), [battery-hours](day05/battery-hours), [break-infinite-loop](day05/break-infinite-loop), [wait-for-button](day05/wait-for-button) |
| 6 | Reading user input over Serial; Ohm's law calculator; choosing LED resistors | [serial-blink-count](day06/serial-blink-count), [ohms-law-calculator](day06/ohms-law-calculator), [rgb-led-sequence](day06/rgb-led-sequence) |
| 7 | Review week 1; button edge detection and debounce | [rgb-color-cycler](day07/rgb-color-cycler) |
| 8 | Functions: parameters, return values, guard clauses, input validation; electrical calculators (power, LED resistor, % error) | [functions](day08/functions) |
| 8 | Arrays: LED pins in an array, LED modes with a button | [arrays](day08/arrays) |
| 9 | Button edge detection + debounce on ESP32 (one LED at a time with a button) | [button](day09/button) |
| 9 | Arrays: average, highest and lowest of 7 temperatures (handles ties and all-negative input) | [temperature](day09/temperature) |
| 10 | ESP32: setup() vs loop(), global vs local variables, double blink, doing something exactly N times with a bool flag | [loop-counter](day10/loop-counter), [double-blink](day10/double-blink), [blink-5-times-setup](day10/blink-5-times-setup), [blink-5-times-loop](day10/blink-5-times-loop) |
| 11 | millis(): timing without delay(), LEDs blinking at different rates with arrays, a button that never misses a press (delay vs millis, debounce with millis) | [print-time](day11/print-time), [blink-one-led](day11/blink-one-led), [blink-led-array](day11/blink-led-array), [button-delay](day11/button-delay), [button-millis](day11/button-millis) |

## Side projects

- [Ultrasonic distance LEDs](projects/ultrasonic-distance-leds): HC-SR04 sensor turns a red LED on when something is within 10 cm.
- [Ultrasonic distance bar](projects/ultrasonic-distance-bar): a button switches it on/off; blue, green and red LEDs light up like a parking sensor as something gets closer.
- [OLED distance display](projects/oled-distance-display): HC-SR04 + SSD1306 OLED.
- [ESP32 parking sensor](projects/esp32-parking-sensor): ESP32 + HC-SR04 (Echo through a 5V to 3.3V voltage divider) + 3 LEDs + OLED, ON/OFF button, 5-sample moving average that skips failed readings.

## Hardware I use

Arduino UNO, breadboard, red/green/blue 5 mm LEDs, resistors (E12), 10k potentiometer, tactile push button, HC-SR04 ultrasonic sensor, SSD1306 OLED, UNI-T UT890D+ multimeter, ESP32 DevKit.

## Things I learned the hard way

- `7 / 60` is `0` in C: integer division. Write `7.0 / 60`.
- Global counters keep their value between `loop()` runs, so reset them.
- A button needs **edge detection** (act only when it changes from released to pressed) and a short **debounce** delay.
- A floating input pin reads random values; use `INPUT_PULLUP`.
- LED brightness is not proportional to current; your eyes are a bad meter.
- A variable declared inside `loop()` is created again every pass, so it can't count. Counters live outside.
- A function and a variable can't share the same name.
- Looping over an array of N items is `i = 0; i < N`. With `<=` the loop reads one slot past the end and gets garbage, with no error.
- `delay()` makes the whole board deaf: a button pressed during a 1.3 s blink is simply missed. `millis()` timing (`now - last >= interval`) never waits.
- Code statements can't sit outside a function, and a `const` can't be changed later, so timestamps are never `const`.
