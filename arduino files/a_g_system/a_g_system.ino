/* Arduino Code Created by Kang'alia Isaac Nyamu
   P15/1325/2011
   The University of Nairobi
   School of Computing and Informatics
   Fourth Year BSc Computer Science Project
   The Automated Greenhouse Monitoring System (Temperature and Humidity Control)
*/
#include <idDHT11.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
                      
#define I2C_ADDR  0x27 //Define the I2C Address where the PCF8574A is

float temp;
int tempPin = 0;

// The DHT11 sensor
int idDHT11pin = 2; // Digital pin for communications with the DHT11 sensor
int idDHT11intNumber = 0;

// The actuators
int fanIn      = 11; // Input fan connected to pwm pin 11
int humfan     = 10; // Fan for the humidifier
int fanOut     = 9; // Exhaust fan connected to pwm pin 10
int heater     = 6; // The heater connected to pwm pin 9
int humidifier = 5; // The humidifier connected to pwm pin 6

// Declarations
void dht11_wrapper(); // the wrapper must be declared before the lib initialization

#define BACKLIGHT_PIN  3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

// Instantiate the Libs
idDHT11 DHT11(idDHT11pin, idDHT11intNumber, dht11_wrapper);
LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

void setup()
{
  Serial.begin(9600); // Specify the speed at which the serial communication will be carried
  lcd.begin(16,2);  //state the type of LCD in use
  
  temp = analogRead(tempPin);
  temp = (((temp * 0.48828125) - 32) * 5)/9;

  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();

  // Display welcome message
  lcd.setCursor(0,0); //first line
  lcd.print("AUTO GREENHSE: ");
  lcd.setCursor(0,1);  // go to the second line
  lcd.print("TEMP. & HUM CTRL");
  delay(2000);
  lcd.clear();
  delay(2000);
  
  // The Actuators
  pinMode(fanIn, OUTPUT);
  pinMode(fanOut, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(humidifier, OUTPUT);
  pinMode(humfan, OUTPUT);
}

/* This wrapper is responsible for calling the DHT11 Library
   It must be defined in the following way in order for it to work
*/
void dht11_wrapper()
{
  DHT11.isrCallback();
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("READ SENSOR....");
  lcd.setCursor(0,1);
  lcd.print("STATUS:");
  
  int result = DHT11.acquireAndWait();
  switch (result)
  {
  case IDDHTLIB_OK:
    lcd.print("OK");
    delay(3000);
    lcd.clear();
    delay(2000);
    break;
  default: 
    lcd.print("!!!");
    delay(3000);
    lcd.clear();
    delay(2000); 
    break;
  }  
  
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("TEMP:");
  lcd.print(DHT11.getCelsius(),2);
  lcd.print("oC");
  lcd.setCursor(3,1);
  lcd.print("HUM:");
  lcd.print(DHT11.getHumidity(),2);
  lcd.print(" %");
  delay(4000);
  
  //The Actuators
  if (DHT11.getCelsius() >= 31.00){
    digitalWrite(fanIn, HIGH);
    digitalWrite(heater, LOW);
  }
  else{
    digitalWrite(fanIn, LOW);
    digitalWrite(heater, HIGH);
  }
  
  if(temp >= 31.00){
    digitalWrite(humfan, HIGH);
    digitalWrite(humidifier, LOW);
  }
  else if(temp < 31.00){
    if (temp > 25){
      digitalWrite(humfan, HIGH);
      digitalWrite(humidifier, LOW);
    }
    else{
      digitalWrite(humfan, LOW);
      digitalWrite(heater, LOW);
    }
  }
  digitalWrite(fanOut, HIGH);
  delay(10000);
  digitalWrite(fanOut, LOW);
  delay(10000);
  
  if (DHT11.getHumidity() >= 45.00){
    digitalWrite(fanIn, HIGH);
    digitalWrite(humfan, LOW);
    digitalWrite(humidifier, LOW);
  }
  else{
    digitalWrite(fanIn, LOW);
    digitalWrite(humfan, HIGH);
    digitalWrite(humidifier, HIGH);
  }
  if(DHT11.getDewPoint() <= 10.00){
    digitalWrite(humidifier, HIGH);
    digitalWrite(humfan, HIGH);
    digitalWrite(fanIn, HIGH);
  }
  else{
    digitalWrite(humidifier, LOW);
    digitalWrite(humfan, LOW);
    digitalWrite(fanIn, HIGH);
  }
}

