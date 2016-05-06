/*
  tmp36gz.h - Library for TMP 36GZ.
  Created by SloCompTech, August 3, 2015.
  Released into the public domain.
*/
#ifndef TMP36GZ_h
#define TMP36GZ_h

#include "Arduino.h"

class tmp36gz
{
  public:
    tmp36gz(int pin);
    tmp36gz(int pin,float voltage);
    void update();
    float getTempC();
    float getTempF();
  private:
    int _pin;
    float _temp_c;
    float _temp_f;
    float _voltage;
};

#endif