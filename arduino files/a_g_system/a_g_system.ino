/* Arduino Code Created by Kang'alia Isaac Nyamu
   P15/1325/2011
   The University of Nairobi
   School of Computing and Informatics
   Fourth Year BSc Computer Science Project
   The Automated Greenhouse Monitoring System (Temperature and Humidity Control)
*/
#include <crop.h>
#include <idDHT11.h>
#include <Wire.h>

#define TIMEOUT  5000;

// The DHT11 sensor
int idDHT11pin = 2; // Digital pin for communications with the DHT11 sensor
int idDHT11intNumber = 0;

// Declarations
void dht11_wrapper(); // the wrapper must be declared before the lib initialization

// Instantiate the Libs
idDHT11 DHT11(idDHT11pin, idDHT11intNumber, dht11_wrapper);

// The actuators
int fanIn      = 11;    // Input fan connected to pwm pin 11
int humfan     = 10;    // Fan for the humidifier
int fanOut     = 9;     // Exhaust fan connected to pwm pin 10
int heater     = 6;     // The heater connected to pwm pin 9
int humidifier = 5;     // The humidifier connected to pwm pin 6

int option = 0;
int junk = 0;
int choice = 0;

// Crop objects
BEANS beans;
MAIZE maize;

void setup()
{
  Serial.begin(9600); // Specify the speed at which the serial communication will be carried
  
  // The Actuators
  pinMode(fanIn, OUTPUT);
  pinMode(fanOut, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(humidifier, OUTPUT);
  pinMode(humfan, OUTPUT);
  
  Serial.println("Select the crop in the greenhouse from the following list");
  Serial.println("1. \tBeans");
  Serial.println("2. \tMaize\n");
  while (Serial.available() == 0);{
    option = Serial.parseInt();
    while (option < 1 || option > 2){
      Serial.println("You have made an invalid selection!");
      Serial.println("Please select a valid option from the following list:");
      Serial.println("1. \tBeans");
      Serial.println("2. \tMaize\n"); 
      option = Serial.parseInt();     
    }
    Serial.print("Option = ");
    Serial.println(option, DEC);
    while (Serial.available() > 0) {
      // Clear the keyboard buffer
      junk = Serial.read() - '0';
    }
  }
  
  if (option == 1) {
    Serial.println("At what stage of growth are the beans?");
    Serial.println("1. \tGermination Stage");
    Serial.println("2. \tSeedling Stage");
    while (Serial.available() == 0);{
      choice = Serial.parseInt();
      while (choice < 1 || choice > 2){
        Serial.println("You have made an invalid selection!");
        Serial.println("Please select a valid option from the following list:");
        Serial.println("1. \tGermination Stage");
        Serial.println("2. \tSeedling Stage");
        choice = Serial.parseInt();
      }
      Serial.print("Choice = ");
      Serial.println(choice, DEC);
      while (Serial.available() > 0){
        // Clear keyboard buffer
        junk = Serial.read() - '0';
      }
    }
  }
  
    else if (option == 2) {
    Serial.println("At what stage of growth are the maize?");
    Serial.println("1. \tGermination Stage");
    Serial.println("2. \tSeedling Stage");
    while (Serial.available() == 0);{
      choice = Serial.parseInt();
      while (choice < 1 || choice > 2){
        Serial.println("You have made an invalid selection!");
        Serial.println("Please select a valid option from the following list:");
        Serial.println("1. \tGermination Stage");
        Serial.println("2. \tSeedling Stage");
        choice = Serial.parseInt();
      }
      Serial.print("Choice = ");
      Serial.println(choice, DEC);
      while (Serial.available() > 0){
        // Clear keyboard buffer
        junk = Serial.read() - '0';
      }
    }
  }  
}
void dht11_wrapper()
{
  DHT11.isrCallback();
}
void loop()
{
  Serial.print("READ SENSOR....");
  Serial.print("STATUS:");
  
  int result = DHT11.acquireAndWait();
  switch (result)
  {
  case IDDHTLIB_OK:
    Serial.print("OK");
    break;
  default: 
    Serial.print("!!!"); 
    break;
  }   
  Serial.print("TEMP:");
  Serial.print(DHT11.getCelsius(),2);
  Serial.print("oC");
  Serial.print("HUM:");
  Serial.print(DHT11.getHumidity(),2);
  Serial.print(" %");
  
  if (option == 1 && choice == 1)
    beans.set_beans_s1 (DHT11.getCelsius(), DHT11.getHumidity(), fanIn, fanOut, humfan, heater, humidifier);
  else if (option == 1 && choice == 2)
    beans.set_beans_s2 (DHT11.getCelsius(), DHT11.getHumidity(), fanIn, fanOut, humfan, heater, humidifier);
  else if (option == 2 && choice == 1)
    maize.set_maize_s1 (DHT11.getCelsius(), DHT11.getHumidity(), fanIn, fanOut, humfan, heater, humidifier);
  else if (option == 2 && choice == 2)
    maize.set_maize_s2 (DHT11.getCelsius(), DHT11.getHumidity(), fanIn, fanOut, humfan, heater, humidifier);
}

