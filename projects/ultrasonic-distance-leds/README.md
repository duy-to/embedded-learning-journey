# Ultrasonic distance LEDs

HC-SR04 ultrasonic sensor + two LEDs. If something is closer than 10 cm, the red LED turns on; otherwise the green LED is on.

## Wiring

| Part | Arduino UNO pin |
|---|---|
| HC-SR04 VCC / GND | 5V / GND |
| HC-SR04 TRIG | 7 |
| HC-SR04 ECHO | 11 |
| Red LED (+ 220 Ω) | 9 |
| Green LED (+ 220 Ω) | 10 |

## How it works

1. A 10 µs HIGH pulse on TRIG makes the sensor send an ultrasonic burst.
2. ECHO stays HIGH for as long as the sound takes to go out and come back. `pulseIn()` measures that time in microseconds.
3. Sound travels about 0.034 cm/µs, and the trip is there and back, so `distance = time × 0.034 / 2`.
