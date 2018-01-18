#ifndef LIS3DSH_H
#define LIS3DSH_H

#if (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif
#include <SPI.h>

#define setbit(port, bit) (port) |= (1 << (bit))
#define clearbit(port, bit) (port) &= (0 << (bit))

#define CTRL_REG1     0x21
#define CTRL_REG2     0x22
#define CTRL_REG3     0x23
#define CTRL_REG4     0x20
#define CTRL_REG5 		0x24
#define CTRL_REG6 		0x25

#define INFO1       0x0D
#define INFO2       0x0E

#define STATUS 			0x27
#define WHO_AM_I  		0x0F
#define OUT_X_L 		0x28
#define OUT_X_H 		0x29
#define OUT_Y_L 		0x2A
#define OUT_Y_H 		0x2B
#define OUT_Z_L 		0x2C
#define OUT_Z_H 		0x2D
#define OUT_T       0x0C

class LIS3DSH{
	public:
		LIS3DSH();
		void startup();
		byte readRegister(byte Address);
		void writeRegister(byte Address, byte Value);
		int readAccelX();
		int readAccelY();
		int readAccelZ();
    int readTemp();
};

#endif
