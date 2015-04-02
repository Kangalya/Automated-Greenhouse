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
    void get_beans_s2 (
        double seedling_temp, 
        double seedling_hum, 
        double opt_temp2, 
        double opt_hum2, 
        int fanIn2, 
        int fanOut2, 
        int fanHum2, 
        int heater2, 
        int humidifier2);
    void get_beans_s1 (
        double germ_temp, 
        double germ_hum, 
        double opt_temp1, 
        double opt_hum1, 
        int fanIn1, 
        int fanOut1, 
        int fanHum1, 
        int heater1, 
        int humidifier1);
    int set_beans_s2 (
        double seedling_temp, 
        double seedling_hum, 
        int fanIn2, 
        int fanOut2, 
        int fanHum2, 
        int heater2, 
        int humidifier2);
    int set_beans_s1 (
        double germ_temp, 
        double germ_hum, 
        int fanIn1, 
        int fanOut1, 
        int fanHum1, 
        int heater1, 
        int humidifier1);

private:
    double _b_temp_s1;
    double _b_temp_s2;
    double _b_hum_s1; 
    double _b_hum_s2;
    double opt_temp1;
    double opt_temp2;
    double opt_hum1;
    double opt_hum2;
    int _fanIn_1;
    int _fanOut_1;
    int _fanHum_1;
    int _heater_1;
    int _humidifier_1;
    int _fanIn_2;
    int _fanOut_2;
    int _fanHum_2;
    int _heater_2;
    int _humidifier_2;
};

class MAIZE {
public:
    MAIZE () {}
    void get_maize_s1 (
        double germ_temp, 
        double germ_hum, 
        double opt_temp1, 
        double opt_hum1, 
        int fanIn1, 
        int fanOut1, 
        int fanHum1, 
        int heater1, 
        int humidifier1);
    void get_maize_s2 (
        double seedling_temp, 
        double seedling_hum, 
        double opt_temp2, 
        double opt_hum2, 
        int fanIn2, 
        int fanOut2, 
        int fanHum2, 
        int heater2, 
        int humidifier2);
    int set_maize_s1 (
        double germ_temp, 
        double germ_hum, 
        int fanIn1, 
        int fanOut1, 
        int fanHum1, 
        int heater1, 
        int humidifier1);
    int set_maize_s2 (
        double seedling_temp, 
        double seedling_hum, 
        int fanIn2, 
        int fanOut2, 
        int fanHum2, 
        int heater2, 
        int humidifier2);

private:
    double _m_temp_s1;
    double _m_temp_s2;
    double _m_hum_s1; 
    double _m_hum_s2;
    double opt_temp1;
    double opt_temp2;
    double opt_hum1;
    double opt_hum2; 
    int _fanIn_1;
    int _fanOut_1;
    int _fanHum_1;
    int _heater_1;
    int _humidifier_1;
    int _fanIn_2;
    int _fanOut_2;
    int _fanHum_2;
    int _heater_2;
    int _humidifier_2;
};

#endif // CROP_H_INCLUDED
