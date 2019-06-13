# include "ir.h"

Break_beam_sensor::Break_beam_sensor(int _signal_pin, int _enable_pin) : 
  Sensor(_signal_pin, _enable_pin) {};

Sensor::Sensor(int _signal_pin, int _enable_pin=-1) : 
  signal_pin(_signal_pin),
  enable_pin(_enable_pin),
  is_enabled(false),
  is_triggered(false){}

void Sensor::begin() {
  pinMode(enable_pin, OUTPUT);
  pinMode(signal_pin, INPUT_PULLUP);
  this -> enable();
}

void Sensor::update() {
  is_triggered = (digitalRead(signal_pin)) ? false : true;
}

void Sensor::enable() {
  digitalWrite(enable_pin, HIGH);
}

void Sensor::disable() {
  digitalWrite(enable_pin, LOW);
}