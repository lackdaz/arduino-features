# include "stepper.h"

# define DEFAULT_STEPS 200
# define DEFAULT_MICROSTEP 16 // 1/x
# define DEFAULT_MM_REV 40 // PULLEY_PITCH * PULLEY_TEETH
# define MOTOR_SPEED 200 // mm/s

Stepper::Stepper(
  int _step_pin, 
  int _dir_pin,
  int _en_pin,
  int _microstep,
  int _mm_rev) : 
    step_pin(_step_pin),
    dir_pin(_dir_pin),
    en_pin(_en_pin),
    rev_res(_microstep * DEFAULT_STEPS),
    mm_rev(_mm_rev),
    mm_s_speed(MOTOR_SPEED),
    pulse_delay(-1),
    stop_time(0) 
    {}

void Stepper::begin() {
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(en_pin, OUTPUT);
  digitalWrite(en_pin, LOW);
  set_pulse_delay();
}

void Stepper::tango() {
  digitalWrite(dir_pin, HIGH);
  for (int i = 0; i < 3200; i++) {
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(pulse_delay);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(pulse_delay);
  }
  delay(50);

  digitalWrite(dir_pin, LOW);
  for (int i = 0; i < 3200; i++) {
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(pulse_delay);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(pulse_delay);
  }
  delay(50);
}

/*
  delay = 1000000 / fz
  1 second = 1 000 000 microseconds
 */

void Stepper::set_pulse_delay() {
  double ustep_mm, hz;
  ustep_mm = (double)rev_res / mm_rev;
  hz = (ustep_mm * mm_s_speed);
  pulse_delay = 1000000 / hz;
}

void Stepper::move_backwards(int mm) {
  double usteps;
  double ustep_mm;
  ustep_mm = (double)rev_res / mm_rev;
  usteps = ustep_mm * mm;

  digitalWrite(dir_pin, HIGH);
  for (int i = 0; i < usteps; i++) {
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(pulse_delay);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(pulse_delay);
  }
}

void Stepper::stop() {
  digitalWrite(en_pin, HIGH);
  Serial.println("Stepper Stopped");
}

void Stepper::charge() {
  digitalWrite(dir_pin, LOW);
  digitalWrite(step_pin, HIGH);
  delayMicroseconds(pulse_delay);
  digitalWrite(step_pin, LOW);
  delayMicroseconds(pulse_delay);
}

void Stepper::test() {
  for (int i=0; i < (DEFAULT_MICROSTEP * 200);i++) {
    digitalWrite(dir_pin, HIGH);
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(pulse_delay);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(pulse_delay);
  }
  for (int i=0; i < (DEFAULT_MICROSTEP * 200);i++) {
    digitalWrite(dir_pin, LOW);
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(pulse_delay);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(pulse_delay);
  }  
}
