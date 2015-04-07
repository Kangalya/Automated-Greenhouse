/*
  FILE:           actuators.cpp
  DEVELOPED BY:   Kang'alia Isaac Nyamu
                  The University of Nairobi
                  School of Computng and Informatics
                  P15/1325/2011
  PURPOSE:        To display information on both the LCD and the serial monitor and to control the actuators
  LICENCE:        GPL v3 (http://www.gnu.org/licenses/gpl.html)
  PROJECT:        IV YR PROJECT: The Automated Greenhouse (Temperature and Humidity Control)
*/

#include "crop.h"
#include <idDHT11.h>            // To read from the DHT11 sensor
// #include <Wire.h>               // To enable comunication with the actuators
// #include <LCD.h>                // The LCD library
// #include <LiquidCrystal_I2C.h>  // The liquid crystal library based on the I2C adapter

// The DHT11 sensor
int idDHT11pin = 2;             // Digital pin for communications with the DHT11 sensor
int idDHT11intNumber = 0;

// Declarations
void dht11_wrapper();         // the wrapper must be declared before the lib initialization

// Instantiate the Libs
idDHT11 DHT11(idDHT11pin, idDHT11intNumber, dht11_wrapper);

// The LM35 sensor attached to the "humidifier"
float temp;
int tempPin = 0;              // The analog pin the LM35 will be connected

// #define I2C_ADDR  0x27          //Define the I2C Address where the PCF8574A is

// // The LCD pins
// #define BACKLIGHT_PIN  3        // For the backlight
// #define En_pin  2
// #define Rw_pin  1
// #define Rs_pin  0
// #define D4_pin  4
// #define D5_pin  5
// #define D6_pin  6
// #define D7_pin  7

// LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

// The actuators
int fanIn      = 11;          // Input fan connected to pwm pin 11
int humfan     = 10;          // Fan for the humidifier
int fanOut     = 9;           // Exhaust fan connected to pwm pin 10
int heater     = 6;           // The heater connected to pwm pin 9
int humidifier = 5;           // The humidifier connected to pwm pin 6

int actuators() {
	// The Actuators
  pinMode(fanIn, OUTPUT);
  pinMode(fanOut, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(humidifier, OUTPUT);
  pinMode(humfan, OUTPUT);

  temp = analogRead(tempPin);
  temp = (((temp * 0.48828125) - 32) * 5)/9;
}

void dht11_wrapper()
{
  DHT11.isrCallback();
}

int reader() {
	Serial.println("READ SENSOR....");  
	Serial.print("STATUS: ");
	
	int result = DHT11.acquireAndWait();
	switch (result){
    case IDDHTLIB_OK:
	  Serial.println("OK");
    break;
  
    default: 
    Serial.println("!!!");
    break;
  }   
  
  Serial.print("\tTEMP: ");
  Serial.print(DHT11.getCelsius(),2);
  Serial.print(" oC");
  Serial.print("\tHUM: ");
  Serial.print(DHT11.getHumidity(),2);
  Serial.println(" %");
  delay(2000);

  Serial.print("The current humidifier temp reading is: ");
  Serial.print(temp);
  Serial.println(" *C.");
  delay(2000);
}

// int activate() {
//   Serial.println("The LCD has been activated for display.");
//   lcd.begin(16, 2);
//   lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
//   lcd.setBacklight(HIGH);
//   lcd.home();

//   // Display welcome message
//   lcd.setCursor(0,0); //first line
//   lcd.print("AUTO GREENHSE: ");
//   lcd.setCursor(0,1);  // go to the second line
//   lcd.print("TEMP. & HUM CTRL");
//   delay(2000);
//   lcd.clear();
//   delay(2000);
// }

// int show() {
//   lcd.clear();
//   lcd.setCursor(0,0);
//   lcd.print("READ SENSOR....");
//   lcd.setCursor(0,1);
//   lcd.print("STATUS: ");

//   int result = DHT11.acquireAndWait();
//   switch (result){
//     case IDDHTLIB_OK:
//     lcd.print("OK");
//     delay(3000);
//     lcd.clear();
//     delay(2000);
//     break;
  
//     default: 
//     Serial.println("!!!"); 
//     lcd.print("!!!");
//     delay(3000);
//     lcd.clear();
//     delay(2000); 
//     break;
//   }
  
//   lcd.clear();
//   lcd.setCursor(2,0);
//   lcd.print("TEMP:");
//   lcd.print(DHT11.getCelsius(),2);
//   lcd.print("oC");
//   lcd.setCursor(3,1);
//   lcd.print("HUM:");
//   lcd.print(DHT11.getHumidity(),2);
//   lcd.print(" %");
//   delay(4000);
// }

int BEANS::set_seedling (float opt_t, float opt_h, float opt_th){
  Serial.print("optimum seedling temperature for beans is: ");
  Serial.print(opt_t);
  Serial.println(" *C.");
  Serial.print("optimum seedling Humidity for beans is: ");
  Serial.print(opt_h);
  Serial.println(" %.");
  Serial.print("optimum temperature for the humidifier should be: ");
  Serial.print(opt_th);
  Serial.println(" *C");

  if (DHT11.getCelsius() > opt_t) {
    Serial.println("Current temp reading is higher than optimum temp for beans seedlings.");
    Serial.println("Turning on Input and Exhaust fans...");
    digitalWrite(fanIn, HIGH);
    digitalWrite(fanOut, HIGH);
  }
  if (DHT11.getCelsius() <= opt_t) {
    Serial.println("Current temp reading is lower than optimum temp for beans seedlings.");
    Serial.println("Turning down Input and Exhaust fans...");
    digitalWrite(fanIn, HIGH);
    digitalWrite(fanOut, HIGH);
  }
  // if (DHT11.getHumidity() > opt_h) {}
  // if (DHT11.getHumidity() <= opt_h) {}
  // if (temp > opt_th) {}
  // if (temp < opt_th) {}
  // if (temp = opt_th) {}
}
int MAIZE::set_seedling (float opt_t, float opt_h, float opt_th){
  Serial.print("optimum seedling temperature for maize is: ");
  Serial.print(opt_t);
  Serial.println(" *C.");
  Serial.print("optimum seedling Humidity for maize is: ");
  Serial.print(opt_h);
  Serial.println(" %.");
  Serial.print("optimum temperature for the humidifier should be: ");
  Serial.print(opt_th);
  Serial.println(" *C");

  // if (DHT11.getCelsius() > opt_t) {}
  // if (DHT11.getCelsius() < opt_t) {}
  // if (DHT11.getCelsius() == opt_t) {}
  // if (DHT11.getHumidity() > opt_h) {}
  // if (DHT11.getHumidity() < opt_h) {}
  // if (DHT11.getHumidity() == opt_h) {}
  // if (temp > opt_th) {}
  // if (temp < opt_th) {}
  // if (temp = opt_th) {}
}
int BEANS::set_germination (float opt_t, float opt_h, float opt_th){
  Serial.print("optimum germination temperature for beans is: ");
  Serial.print(opt_t);
  Serial.println(" *C.");
  Serial.print("optimum germination Humidity for beans is: ");
  Serial.print(opt_h);
  Serial.println(" %.");
  Serial.print("optimum temperature for the humidifier should be: ");
  Serial.print(opt_th);
  Serial.println(" *C");

  // if (DHT11.getCelsius() > opt_t) {}
  // if (DHT11.getCelsius() < opt_t) {}
  // if (DHT11.getCelsius() == opt_t) {}
  // if (DHT11.getHumidity() > opt_h) {}
  // if (DHT11.getHumidity() < opt_h) {}
  // if (DHT11.getHumidity() == opt_h) {}
  // if (temp > opt_th) {}
  // if (temp < opt_th) {}
  // if (temp = opt_th) {}
}
int MAIZE::set_germination (float opt_t, float opt_h, float opt_th){
  Serial.print("optimum germination temperature for maize is: ");
  Serial.print(opt_t);
  Serial.println(" *C.");
  Serial.print("optimum germination Humidity for maize is: ");
  Serial.print(opt_h);
  Serial.println(" %.");
  Serial.print("optimum temperature for the humidifier should be: ");
  Serial.print(opt_th);
  Serial.println(" *C");
  
  // if (DHT11.getCelsius() > opt_t) {}
  // if (DHT11.getCelsius() < opt_t) {}
  // if (DHT11.getCelsius() == opt_t) {}
  // if (DHT11.getHumidity() > opt_h) {}
  // if (DHT11.getHumidity() < opt_h) {}
  // if (DHT11.getHumidity() == opt_h) {}
  // if (temp > opt_th) {}
  // if (temp < opt_th) {}
  // if (temp = opt_th) {}
}