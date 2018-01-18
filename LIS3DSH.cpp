#include "LIS3DSH.h"

LIS3DSH::LIS3DSH(){
	SPI.begin();

  // Set PORTB bit 1 as the CS
  setbit(DDRB,1);
  clearbit(PORTB,1);
}

void LIS3DSH::startup(){
  // activate accelerometer at 100Hz
  writeRegister(CTRL_REG4,0x67); // X, Y, Z enabled, ODR = 100 Hz
  writeRegister(CTRL_REG3,0xC8); // DRY active high on INT1 pin
}

byte LIS3DSH::readRegister(byte Address){
  byte result = 0;
  clearbit(PORTB, PB1);
  SPI.transfer(0x80 | Address);
  result = SPI.transfer(0x00);
  setbit(PORTB, PB1);
  return(result);
}

void LIS3DSH::writeRegister(byte Address, byte Value){
  clearbit(PORTB, PB1);
  SPI.transfer(0x00 | Address);
  SPI.transfer(Value);
  setbit(PORTB, PB1);
}

int LIS3DSH::readAccelX(){
  byte acc_x_L;
  byte acc_x_H;
  acc_x_H = readRegister(OUT_X_H);
  acc_x_L = readRegister(OUT_X_L);
  return (acc_x_H << 8) | acc_x_L;
}

int LIS3DSH::readAccelY(){
  byte acc_y_L;
  byte acc_y_H;
  acc_y_H = readRegister(OUT_Y_H);
  acc_y_L = readRegister(OUT_Y_L);
  return (acc_y_H << 8) | acc_y_L;
}

int LIS3DSH::readAccelZ(){
  byte acc_z_L;
  byte acc_z_H;
  acc_z_H = readRegister(OUT_Z_H);
  acc_z_L = readRegister(OUT_Z_L);
  return (acc_z_H << 8) | acc_z_L;
}

int LIS3DSH::readTemp(){
  return readRegister(OUT_T);
}
