# include <arduino.h>

class Stepper {
  protected:
    const int step_pin;
    const int dir_pin;
    const int en_pin;
    const int microstep;
    const int rev_res;
    const int mm_rev;
    double pulse_delay;
    double mm_s_speed;
  public:
    long stop_time;
    Stepper(int _step_pin, int _dir_pin, int _en_pin, int _microstep, int _mm_rev);
    void begin();
    void tango();
    void move_backwards(int mm);
    void charge();
    void set_pulse_delay();
    void stop();
};