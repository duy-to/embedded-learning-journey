# Ultrasonic distance bar

HC-SR04 sensor + three LEDs that work like a parking sensor, with a push button to switch the whole thing on and off.

| Distance | LEDs |
|---|---|
| 30 cm or more (or no echo) | off |
| under 30 cm | blue |
| under 15 cm | blue + green |
| under 5 cm | blue + green + red |

## What I practised

- **Edge detection** on the button: it toggles only when the button goes from released (1) to pressed (0), so holding it down doesn't flicker.
- A `bool isOn` flag flipped with `isOn = !isOn`.
- `pulseIn(echoPin, HIGH, 30000)` with a 30 ms timeout so the loop never freezes when nothing is in front of the sensor, and `duration > 0` to ignore "no echo".
- Nested `if`s to build the bar: each level turns the higher LEDs off first, then the closer levels turn them back on.

## Wiring

| Part | Arduino UNO pin |
|---|---|
| HC-SR04 VCC / GND | 5V / GND |
| HC-SR04 TRIG / ECHO | 7 / 6 |
| Red / green / blue LED (each with its own resistor) | 9 / 10 / 11 |
| Push button (other leg to GND, `INPUT_PULLUP`) | A5 |
