/*
  FILE:           crop.cpp
  DEVELOPED BY:   Kang'alia Isaac Nyamu
                  The University of Nairobi
                  School of Computng and Informatics
                  P15/1325/2011
  PURPOSE:        To gather information about the crop in the greenhouse and to send values to the actuator.cpp
  LICENCE:        GPL v3 (http://www.gnu.org/licenses/gpl.html)
  PROJECT:        IV YR PROJECT: The Automated Greenhouse (Temperature and Humidity Control)
*/

#include "crop.h"

int option = 0;               // Represents the choice of crop
int junk = 0;                 // Will be used when clearing the keyboard buffer
int choice = 0;               // Represents the stage of growth the selected crop will be at

BEANS beans;
MAIZE maize;

int selectcrop(){
Serial.begin(9600);  // Specify the speed at which the serial communication will be carried

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
  if (option == 1 && choice == 1)
  	beans.get_germination();
  else if (option == 1 && choice == 2)
  	beans.get_seedling();
  else if (option == 2 && choice == 1)
  	maize.get_germination();
  else if (option == 2 && choice == 2)
  	maize.get_seedling();
}

int BEANS::get_germination() {
	float temp, hum, humtemp;
	temp = 33;
	hum = 27;
	humtemp = 60;
	Serial.print("optimum germination temperature for beans is: ");
	Serial.print(temp);
	Serial.println(" *C.");
	Serial.print("optimum germination Humidity for beans is: ");
	Serial.print(hum);
	Serial.println(" %.");

	beans.set_germination(temp, hum, humtemp);
}
int BEANS::get_seedling() {
	float temp, hum, humtemp;
	temp = 40;
	hum = 35;
	humtemp = 60;
	Serial.print("optimum seedling temperature for beans is: ");
	Serial.print(temp);
	Serial.println(" *C.");
	Serial.print("optimum seedling Humidity for beans is: ");
	Serial.print(hum);
	Serial.println(" %.");

	beans.set_seedling(temp, hum, humtemp);
}
int MAIZE::get_germination() {
	float temp, hum, humtemp;
	temp = 38;
	hum = 32;
	humtemp = 60;
	Serial.print("optimum germination temperature for maize is: ");
	Serial.print(temp);
	Serial.println(" *C.");
	Serial.print("optimum germination Humidity for maize is: ");
	Serial.print(hum);
	Serial.println(" %.");

	maize.set_germination(temp, hum, humtemp);
}
int MAIZE::get_seedling() {
	float temp, hum, humtemp;
	temp = 45;
	hum = 40;
	humtemp = 60;
	Serial.print("optimum seedling temperature for maize is: ");
	Serial.print(temp);
	Serial.println(" *C.");
	Serial.print("optimum seedling Humidity for maize is: ");
	Serial.print(hum);
	Serial.println(" %.");

	maize.set_seedling(temp, hum, humtemp);
}