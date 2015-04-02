#include "crop.h"
#include <idDHT11.h>
#include <Wire.h>

#define TIMEOUT  5000

BEANS bean;
MAIZE maiz;

// Initializations

int BEANS::set_beans_s1 (double germ_temp, double germ_hum, int fanIn1, int fanOut1, int fanHum1, int heater1, int humidifier1){
	germ_temp = _b_temp_s1;
	germ_hum = _b_hum_s1;
	fanIn1 = _fanIn_1;
	fanOut1 = _fanOut_1;
	fanHum1 = _fanHum_1;
	heater1 = _heater_1;
	humidifier1 = _humidifier_1;

	opt_temp1 = 33.25;
	opt_hum1 = 35.55;

	bean.get_beans_s1 (_b_temp_s1, _b_hum_s1, opt_temp1, opt_hum1, _fanIn_1, _fanOut_1, _fanHum_1, _heater_1, _humidifier_1);
}

int BEANS::set_beans_s2 (double seedling_temp, double seedling_hum, int fanIn2, int fanOut2, int fanHum2, int heater2, int humidifier2){
	seedling_temp = _b_temp_s2;
	seedling_hum = _b_hum_s2;
	fanIn2 = _fanIn_2;
	fanOut2 = _fanOut_2;
	fanHum2 = _fanHum_2;
	heater2 = _heater_2;
	humidifier2 = _humidifier_2;

	opt_temp2 = 27.52;
	opt_hum2 = 40.00;

	bean.get_beans_s2 (_b_temp_s2, _b_hum_s2, opt_temp2, opt_hum2, _fanIn_2, _fanOut_2, _fanHum_2, _heater_2, _humidifier_2);
}

int MAIZE::set_maize_s1 (double germ_temp, double germ_hum, int fanIn1, int fanOut1, int fanHum1, int heater1, int humidifier1){
	germ_temp = _m_temp_s1;
	germ_hum = _m_hum_s1;
	fanIn1 = _fanIn_1;
	fanOut1 = _fanOut_1;
	fanHum1 = _fanHum_1;
	heater1 = _heater_1;
	humidifier1 = _humidifier_1;

	opt_temp1 = 40.00;
	opt_hum1 = 55.00;

	maiz.get_maize_s1 (_m_temp_s1, _m_hum_s1, opt_temp1, opt_hum1, _fanIn_1, _fanOut_1, _fanHum_1, _heater_1, _humidifier_1);
}

int MAIZE::set_maize_s2 (double seedling_temp, double seedling_hum, int fanIn2, int fanOut2, int fanHum2, int heater2, int humidifier2){
	seedling_temp = _m_temp_s2;
	seedling_hum = _m_hum_s2;
	fanIn2 = _fanIn_2;
	fanOut2 = _fanOut_2;
	fanHum2 = _fanHum_2;
	heater2 = _heater_2;
	humidifier2 = _humidifier_2;

	opt_temp2 = 31.00;
	opt_hum2 = 45.00;

	maiz.get_maize_s2 (_m_temp_s2, _m_hum_s2, opt_temp2, opt_hum2, _fanIn_2, _fanOut_2, _fanHum_2, _heater_2, _humidifier_2);
}

void BEANS::get_beans_s2 (double seedling_temp, double seedling_hum, double opt_temp2, double opt_hum2, int fanIn2, int fanOut2, int fanHum2, int heater2, int humidifier2) {
	if (seedling_temp > opt_temp2){
		digitalWrite(fanIn2, HIGH);
		digitalWrite(fanOut2, HIGH);
	}
	else if (seedling_temp < opt_temp2){

	}

	if (seedling_hum >= opt_hum2){

	}
	else if (seedling_hum < opt_hum2) {

	}
}

void BEANS::get_beans_s1 (double germ_temp, double germ_hum, double opt_temp1, double opt_hum1, int fanIn1, int fanOut1, int fanHum1, int heater1, int humidifier1) {}
void MAIZE::get_maize_s1 (double germ_temp, double germ_hum, double opt_temp1, double opt_hum1, int fanIn1, int fanOut1, int fanHum1, int heater1, int humidifier1) {}
void MAIZE::get_maize_s2 (double seedling_temp, double seedling_hum, double opt_temp2, double opt_hum2, int fanIn2, int fanOut2, int fanHum2, int heater2, int humidifier2) {}