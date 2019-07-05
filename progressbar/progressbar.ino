#include "SSD1306.h"
#include "images.h"

SSD1306  display(0x3C, D2, D3);

#define X_MIDDLE 64
#define Y_MIDDLE 32
#define X_LENGTH 128
#define Y_LENGTH 64

long now = 0;
int progress = 0;

void setup() {
  Serial.begin(115200);

  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);

  display.init();
  display.display();
  draw_logo_demo();
  display.display();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  delay(1000);
  display.clear();
  draw_full_logo_demo();
  display.display();
  delay(2000);
  display.clear();
}

void loop() {
  display.clear();
  now = millis();
  draw_progress_bar(progress);
  display.display();
}

void draw_logo_demo() {
    display.drawXbm(
    (X_LENGTH - if_logo_width) / 2, 
    (Y_LENGTH - if_logo_height) / 2, 
    if_logo_width, if_logo_height, if_logo_bits);
}

void draw_full_logo_demo() {
    display.drawXbm(
      (X_LENGTH - if_full_logo_width) / 2, 
      (Y_LENGTH - if_full_logo_height) / 2, 
      if_full_logo_width, if_full_logo_height, if_full_logo_bits);
}

// drawProgressBar(x, y, width, height, value);
void draw_progress_bar(int progress){
  progress = round_2_dp(now / 25 % 100);
  Serial.println(progress);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawProgressBar(X_MIDDLE / 2, Y_MIDDLE, X_LENGTH/2, Y_LENGTH/6, progress);
  display.drawString(64, 5, String(progress) + "%");
}

int round_2_dp(int number){
  return round(number);
}
  // int progress = (counter / 5) % 100;
  // // draw the progress bar
  // display.drawProgressBar(0, 32, 120, 10, progress);

  // // draw the percentage as String
  // display.setTextAlignment(TEXT_ALIGN_CENTER);
  // display.drawString(64, 15, String(progress) + "%");