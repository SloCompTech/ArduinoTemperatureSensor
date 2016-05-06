/*
  tmp36gz.cpp - Library for TMP 36GZ.
  Created by SloCompTech, August 3, 2015.
  Released into the public domain.
*/
#include "Arduino.h"
#include "tmp36gz.h"
tmp36gz::tmp36gz(int pin)
{
	_pin = pin;
	_voltage = 5.0;
	_temp_c = 0;
	_temp_f = 0;
}
tmp36gz::tmp36gz(int pin,float voltage)
{
	_pin = pin;
	_voltage = voltage;
	_temp_c = 0;
	_temp_f = 0;
}
void tmp36gz::update()
{
	float tmpTemp=0;
	int samples = 10;
	for(int i=0;i<samples;i++)
		//samples[i] = (4.4 * analogRead(_pin) * 26) / 1024.0;
		tmpTemp += (((analogRead(_pin)*_voltage)/1024.0) - 0.5) * 100.0;
	float tempC = tmpTemp / samples;
	float tempF = (tempC * 9.0 / 5.0) + 32;
	_temp_c = tempC;
	_temp_f = tempF;
}
float tmp36gz::getTempC()
{
	return _temp_c;
}
float tmp36gz::getTempF()
{
	return _temp_f;
}