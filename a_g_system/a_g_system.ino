/* Arduino Code Created by Kang'alia Isaac Nyamu
   P15/1325/2011
   The University of Nairobi
   School of Computing and Informatics
   Fourth Year BSc Computer Science Project
   The Automated Greenhouse Monitoring System (Temperature and Humidity Control)
*/
#include <crop.h>        

int selectcrop();
int actuators();
int reader();
int activate();
int show();

void setup()
{
  selectcrop();
  actuators();
  activate();
}

void loop()
{
   reader();
   show();
}

