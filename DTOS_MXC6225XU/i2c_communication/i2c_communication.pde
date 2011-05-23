#include <Wire.h>

// TWI (I2C) sketch to communicate with the LIS3LV02DQ accelerometer
// Using the Wire library (created by Nicholas Zambetti)
// http://wiring.org.co/reference/libraries/Wire/index.html
// On the Arduino board, Analog In 4 is SDA, Analog In 5 is SCL
// These correspond to pin 27 (PC4/ADC4/SDA) and pin 28 (PC5/ADC5/SCL) on the Atmega8
// The Wire class handles the TWI transactions, abstracting the nitty-gritty to make
// prototyping easy.

#define DTOS_ADDRESS 21 // supposed to be 23?? 0010111b 
#define XOUT_REGISTER 0 // 8-bit x-axis acceleration output
#define YOUT_REGISTER 1 // 8-bit y-axis acceleration output
#define STATUS_REGISTER 2 // orientation and shake status
#define DETECTION_REGISTER 4 // Power down, orientation and shake detection parameters
#define CHIP_ID_REGISTER 8 // Chip ID of MXC6227AU
#define CHIP_ID 39 // 00100111

void setup()
{
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(9600);

  CLKPR = (1<<CLKPCE);
  CLKPR = 0;
  
  Wire.begin(); 
}

void loop()
{   

  byte z_val_l, z_val_h, x_val_l, x_val_h, y_val_l, y_val_h;
  int z_val, x_val, y_val;
  byte chip_id;
  byte chip_id2;
  
  Wire.beginTransmission(DTOS_ADDRESS);
  Wire.send(CHIP_ID_REGISTER);
  Wire.endTransmission();
  
  Wire.requestFrom(DTOS_ADDRESS, 2);
  chip_id = Wire.receive();
  chip_id2 = Wire.receive();
  
  Serial.print("chip_id: ");
  Serial.println(chip_id, DEC);
  Serial.print("chip_id 2: ");
  Serial.println(chip_id2, DEC);  
  delay(1000);
}

