/*
  FILE:           idDHT11.h
  DEVELOPED BY:   Kang'alia Isaac Nyamu
                  The University of Nairobi
                  School of Computng and Informatics
                  P15/1325/2011
  PURPOSE:        This file implements a basic interrupt-driven DHT11 library.
  LICENCE:        GPL v3 (http://www.gnu.org/licenses/gpl.html)
  PROJECT:        IV YR PROJECT: The Automated Greenhouse (Temperature and Humidity Control)
*/

#ifndef idDHT11_H__
#define idDHT11_H__

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define IDDHT11LIB_VERSION "0.1"

// state codes
#define IDDHTLIB_OK			0
#define IDDHTLIB_ACQUIRING		1
#define IDDHTLIB_ACQUIRED		2
#define IDDHTLIB_RESPONSE_OK		3

// error codes
#define IDDHTLIB_ERROR_CHECKSUM		-1
#define IDDHTLIB_ERROR_ISR_TIMEOUT	-2
#define IDDHTLIB_ERROR_RESPONSE_TIMEOUT	-3
#define IDDHTLIB_ERROR_DATA_TIMEOUT	-4
#define IDDHTLIB_ERROR_ACQUIRING	-5
#define IDDHTLIB_ERROR_DELTA		-6
#define IDDHTLIB_ERROR_NOTSTARTED	-7

#define IDDHT11_CHECK_STATE		if(state == STOPPED)													\
									return status;													\
								else if(state != ACQUIRED)				\
									return IDDHTLIB_ERROR_ACQUIRING;
									
class idDHT11
{
public:
	idDHT11(int pin, int intNumber,void (*isrCallback_wrapper)());
    void init(int pin, int intNumber,void (*isrCallback_wrapper)());
	void isrCallback();
	int acquire();
	int acquireAndWait();
	float getCelsius();
	float getFahrenheit();
	float getKelvin();
	double getDewPoint();
	double getDewPointSlow();
	float getHumidity();
	bool acquiring();
	int getStatus();
	
private:
	
	void (*isrCallback_wrapper)(void);
	
	enum states{RESPONSE=0,DATA=1,ACQUIRED=2,STOPPED=3,ACQUIRING=4};
	volatile states state;
	volatile int status;
	volatile byte bits[5];
	volatile byte cnt;
	volatile byte idx;
	volatile int us;
	int intNumber;
	int pin;
	volatile float hum;
	volatile float temp;
};
#endif // idDHT11_H__
