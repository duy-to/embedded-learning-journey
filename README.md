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
| 12 | ESP32 ADC with analogRead(): potentiometer to percent, LED bar graph, averaging 10 readings, printing only on a 2% change, knob controls blink speed | [led-bar](day12/led-bar), [smooth-blink](day12/smooth-blink) |
| 13 | PWM with analogWrite(): 5 brightness levels, a breathing LED with millis, a knob that dims an LED (constrain), and a 3-LED bar that fades in section by section, gamma correction (squaring) so brightness looks even to the eye | [brightness-levels](day13/brightness-levels), [breathing-led](day13/breathing-led), [pot-brightness](day13/pot-brightness), [fading-led-bar](day13/fading-led-bar), [gamma-brightness](day13/gamma-brightness) |
| 14 | Bits and hex: printing numbers in BIN/HEX, a 4-LED binary counter (bitRead and count & (1 << i)), a 4-LED fading bar using >> 2 instead of percent, one byte holding 4 LED states toggled with XOR and a debounced button (millis), and a bit-shift LED chaser | [number-formats](day14/number-formats), [binary-counter](day14/binary-counter), [shift-brightness-bar](day14/shift-brightness-bar), [led-mask](day14/led-mask), [bit-chaser](day14/bit-chaser) |
| 17–18 | Pointers: printing variable addresses (& and *), addresses inside an array 4 bytes apart and the garbage one slot past the end, swapping two variables through pointers vs. by copy, and a readKnob() function that "returns" two values (raw ADC and brightness) through pointers | [pointer-basics](day17/pointer-basics), [array-addresses](day17/array-addresses), [swap-values](day17/swap-values), [read-knob](day17/read-knob) |

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
- A pointer holds an address, not a value: `p` is the address, `*p` is what lives there. A function given a copy (`int x`) can never change the caller's variable; given the address (`int* x`, called with `&value`) it can, which is how one function hands back two results.
- Looping over an array of N items is `i = 0; i < N`. With `<=` the loop reads one slot past the end and gets garbage, with no error.
- `delay()` makes the whole board deaf: a button pressed during a 1.3 s blink is simply missed. `millis()` timing (`now - last >= interval`) never waits.
- Code statements can't sit outside a function, and a `const` can't be changed later, so timestamps are never `const`.
- The ESP32 ADC is 12-bit (0–4095) but not linear: it reads nothing below about 0.14 V and saturates near 3.13 V. `analogReadMilliVolts()` is calibrated and within ~1% in the middle. Use ADC1 pins (32–39); ADC2 stops working when Wi-Fi is on.
- A float is almost never exactly equal to a number, so compare with `>=`, not `==`.
- `constrain(x, low, high)` and `a - b` give back a new value; written alone on a line, the result is thrown away. Write `x = constrain(x, low, high);`.
- `x >> n` divides by 2^n and `x << n` multiplies, on whole numbers only (no `float`). `1 << i` is a mask with one bit set; `&` reads that bit, `^` flips it. A number starting with 0 is octal in C: write binary as `0b0101`.
