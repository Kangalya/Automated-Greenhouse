/* 
   Created by Kang'alia Isaac Nyamu
   P15/1325/2011
   The University of Nairobi
   School of Computing and Informatics
   Fourth Year BSc Computer Science Project
   The Automated Greenhouse Monitoring System (Temperature and Humidity Control)
*/

#include <Thc.h>
#include "DHT.h"
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


#define DHTPIN 2     	// what pin we're connected to

#define DHTTYPE DHT11   // DHT 11

//Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

Thc Thc(5, 9, 10, 11, 13); //This bracket will contain the pin numbers we are to use,It is meant to initialize them to output/input mode
//Thc Thc(Fan In,Fan Out, Heater,Humidifier,Error Pin)

void setup()
{
  Serial.begin(9600);
  dht.begin();
  Thc.Init();
}

void loop()
{
  delay(2000);

  float TEMP = dht.readTemperature();
  float HUM = dht.readHumidity();    
  Thc.GodsCommand(HUM,TEMP);
}
