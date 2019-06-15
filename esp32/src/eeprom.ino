# include <EEPROM.h>

String msg = "Hello World";

struct { 
  uint val = 0;
  char str[20] = "";
} data;

void setup() {
  Serial.begin(115200);
  uint addr = 0;
  pinMode(5, OUTPUT);
  EEPROM.begin(512);
  EEPROM.get(addr, data);
  Serial.println("Old values are: "+String(data.val)+","+String(data.str));
  data.val += 5;
  if ( strcmp(data.str,"hello") == 0 )
    strncpy(data.str, "jerry",20);
  else 
    strncpy(data.str, "hello",20);  
  EEPROM.put(addr,data);
  EEPROM.commit();
  data.val = 0; 
  strncpy(data.str,"",20);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}