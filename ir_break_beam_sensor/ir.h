# include <arduino.h>

class Sensor {
  protected:
    int signal_pin;
    int enable_pin;
  public:
    Sensor(int signal_pin, int enable_pin);
    int is_triggered;
    bool is_enabled;
    void begin();
    void update();
    void enable();
    void disable();
};

class Break_beam_sensor : public Sensor {
  public:
    Break_beam_sensor(int signal_pin, int enable_pin);

};

