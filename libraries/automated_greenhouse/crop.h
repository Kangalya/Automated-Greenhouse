/*
  FILE:           crop.h
  DEVELOPED BY:   Kang'alia Isaac Nyamu
                  The University of Nairobi
                  School of Computng and Informatics
                  P15/1325/2011
  PURPOSE:        To store classes and values that will be used to identify the crop, its stage of growth and automate control
  LICENCE:        GPL v3 (http://www.gnu.org/licenses/gpl.html)
  PROJECT:        IV YR PROJECT: The Automated Greenhouse (Temperature and Humidity Control)
*/

#ifndef CROP_H_INCLUDED
#define CROP_H_INCLUDED

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class BEANS {
public:
    BEANS () {}    
    int set_seedling (float opt_t, float opt_h, float opt_th);
    int get_seedling ();
    int set_germination (float opt_t, float opt_h, float opt_th);
    int get_germination ();

private:
    float opt_t;
    float opt_h;
    float opt_th;
};

class MAIZE {
public:
    MAIZE () {}
    int set_germination (float opt_t, float opt_h, float opt_th);
    int get_germination ();
    int set_seedling (float opt_t, float opt_h, float opt_th);
    int get_seedling ();

private:
    float opt_t;
    float opt_h;
    float opt_th;
};

#endif // CROP_H_INCLUDED
