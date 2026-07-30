/*
  NEMA 17 Stepper Motor — Continuous Rotation
  Drives the Geneva mechanism's driver wheel

  HARDWARE NEEDED:
  - Arduino Uno/Nano/Mega (or compatible)
  - A4988 or DRV8825 stepper driver module
  - NEMA 17 stepper motor (bipolar, 4-wire — e.g. 17HS19-2004S1)
  - External power supply, 12-24V
    (DO NOT power the motor from the Arduino's 5V — it can't supply enough current)

  WIRING (A4988 / DRV8825 driver board):
    Driver VDD              -> Arduino 5V
    Driver GND (logic side) -> Arduino GND
    Driver STEP             -> Arduino pin 3
    Driver DIR              -> Arduino pin 4
    Driver VMOT             -> External power supply (+)
    Driver GND (motor side) -> External power supply (-), common with Arduino GND
    Driver 1A / 1B          -> Motor coil A (2 of the 4 motor wires)
    Driver 2A / 2B          -> Motor coil B (the other 2 motor wires)

  IMPORTANT - SET THE CURRENT LIMIT BEFORE RUNNING AT SPEED:
  This motor is rated for 2.0A. Most drivers ship set too high or unset.
  With the Arduino powered OFF, measure the driver's Vref at its small
  onboard potentiometer with a multimeter, and adjust it to match 2.0A
  using your specific driver's Vref formula (check its datasheet -
  the formula differs between A4988 and DRV8825).
  Running without setting this risks overheating the driver or motor.
*/

const int stepPin = 3;
const int dirPin  = 4;

const int stepsPerRevolution = 200;   // 1.8 deg step angle -> 200 full steps per revolution

int stepDelayMicros = 1000;           // Lower = faster rotation. Start high, decrease gradually.

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, HIGH);         // HIGH = one direction, LOW = reverse
}

void loop() {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelayMicros);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelayMicros);
}
