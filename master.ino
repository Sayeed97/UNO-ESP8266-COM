//Arduino Sketch for NodeMCU (Master I2C Device)
#include <Wire.h>

#define SDA 4
#define SCL 5

void setup() {
 Serial.begin(9600); /* begin serial for debug */
 Wire.begin(SDA, SCL); /* join i2c bus with SDA=D1 (GPIO 5) and SCL=D2 (GPIO 4) of NodeMCU */
}

void loop() {
  Wire.beginTransmission(8); /* begin with device address 8 */
  Wire.write("Hello\n");  /* sends hello string */
  Wire.endTransmission();    /* stop transmitting */

  Wire.requestFrom(8, 3);
  Serial.print("Device Name: ");
  while(Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
  delay(1000);
}