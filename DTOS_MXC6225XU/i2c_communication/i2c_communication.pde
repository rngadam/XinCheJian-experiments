#include <Wire.h>

// TWI (I2C) sketch to communicate with the LIS3LV02DQ accelerometer
// Using the Wire library (created by Nicholas Zambetti)
// http://wiring.org.co/reference/libraries/Wire/index.html
// On the Arduino board, Analog In 4 is SDA, Analog In 5 is SCL
// These correspond to pin 27 (PC4/ADC4/SDA) and pin 28 (PC5/ADC5/SCL) on the Atmega8
// The Wire class handles the TWI transactions, abstracting the nitty-gritty to make
// prototyping easy.

#define DTOS_ADDRESS 21 // supposed to be 0x2A = 42, but scanner actually finds 21...
#define XOUT_REGISTER 0 // 8-bit x-axis acceleration output
#define YOUT_REGISTER 1 // 8-bit y-axis acceleration output
#define STATUS_REGISTER 2 // orientation and shake status
#define DETECTION_REGISTER 4 // Power down, orientation and shake detection parameters
//#define CHIP_ID_REGISTER 8 // Chip ID of MXC6227AU
//#define CHIP_ID 39 // 00100111

void setup()
{
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(9600);

  CLKPR = (1<<CLKPCE);
  CLKPR = 0;

  Wire.begin(); 
}

int convert_2complement(byte value) {
  if(value & 128) {
    return -(value & 127);
  } else {
    return value & 127;
  }
}

byte readRegister(byte reg) {
  byte byte1, byte2;
  Wire.beginTransmission(DTOS_ADDRESS);
  Wire.send(reg);
  Wire.endTransmission();

  Wire.requestFrom(DTOS_ADDRESS, 2);
  while(!Wire.available()) {
    Serial.print(".");
    delay(1000);
  }
  byte1 = Wire.receive();
  byte2 = Wire.receive();
  return byte1; 
}

byte orientation, prev_orientation, shake, prev_shake, x_acc, y_acc, prev_x_acc, prev_y_acc;

void loop()
{   
  /*Serial.print("XOUT acceleration: ");
   Serial.println(readRegister(XOUT_REGISTER), DEC);
   Serial.print("YOUT acceleration: ");
   Serial.println(readRegister(YOUT_REGISTER), DEC);
   Serial.print("STATUS: ");*/
  byte state = readRegister(STATUS_REGISTER);
  //Serial.println(state, DEC);

  // OR[1:0] = 00 – device is vertical in upright orientation; 01 – device is rotated 90 degrees clockwise; 10– 
  // device is vertical in inverted orientation; 11 – device is rotated 90 degrees counterclockwise. The bits 
  // OR[1:0] are indicative of “long-term” orientation. The orientation is determined by measuring the signs of   
  orientation = state & 3;
  if(orientation != prev_orientation) {
    switch(orientation) {
    case 0:
      Serial.println("vertical in upright orientation");
      break;
    case 1:
      Serial.println("rotated 90 degrees clockwise");
      break;
    case 2:  
      Serial.println("vertical in inverted orientation");
      break;
    case 3:
      Serial.println("rotated 90 degrees counterclockwise");
      break;
    }
  }

  // little class on binary...

  // 0 & 0 = 0
  // 0 & 1 = 0
  // 1 & 0 = 0
  // 1 & 1 = 1

  // 10101010
  //  ^^
  // 01100000 &
  // 00100000  

  // SH[1:0] indicate whether a shake event has taken place, and if so, its direction. Shake can only be 
  // detected in a direction perpendicular to the vertical orientation of the device. When an acceleration 
  // perpendicular to the device orientation (ax for OR[1:0] = 01 or 11; ay for OR[1:0] = 00 or 10) is sensed that 
  // has a magnitude greater than the value set by bits SHTH[1:0] in the DETECTION register, then shake detec-
  // tion begins. For a shake event to be written to SH[1:0], the perpendicular acceleration must again exceed 
  // the magnitude set by SHTH[1:0] but with the opposite sign (if bit SHM = 0 in the DETECTION register), or 
  // just reverse its sign (if bit SHM = 1 in the DETECTION register). The above mentioned second accelera-
  // tion events must occur within a certain amount of time, set by SHC[1:0] in the DETECTION register, of the 
  // original breaking of the threshold.  
  shake = state & 96; // D6, D5, 2^6 + 2^5 = 32 + 64 = 96
  if(shake != prev_shake) {
    switch(shake) {
    case 32:
      Serial.println("shake left");
      break;
    case 64:
      Serial.println("shake right");
      break;
    }
  }

  prev_orientation = orientation;
  prev_shake = shake;
  
 x_acc = readRegister(XOUT_REGISTER);
 y_acc = readRegister(YOUT_REGISTER);
 if(abs(x_acc - prev_x_acc) > 2) {
   Serial.print("X:");
   Serial.println(convert_2complement(x_acc), DEC);
 }
 if(abs(y_acc - prev_y_acc) > 2) {
   Serial.print("Y:");
   Serial.println(convert_2complement(y_acc), DEC);   
 }
 prev_x_acc = x_acc;
 prev_y_acc = y_acc;
}




