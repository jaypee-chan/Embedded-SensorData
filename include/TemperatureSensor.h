/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/
/*
    Class of the temperature sensor using the LM75B lib.
    It can read read ambiant temperature in Celsius or Fahrenheit.
*/

#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_


#include "mbed.h"
#include "LM75B/LM75B.h"

class TemperatureSensor {
public:
    TemperatureSensor();
    ~TemperatureSensor() {};
    
    /* Read the ambiant temperature */
    float GetTemperature() const;

    /* Temperature different mode */
    enum eTemp { CELSIUS, FAHRENHEIT };
    
    /* Get Temperature mode, either Celsius or Fahrenheit */
    eTemp GetMode() const;

    /* Set the mode in Celsius */
    void SetCelsius();
    /* Check if it's Celsius mode */
    bool IsCelsius();
    /* Set the mode in Fahrenheit */
    void SetFahrenheit();
    /* Check if it's Fahrenheit mode */
    bool IsFahrenheit();
    
    /* Switch between Celsius or Fahrenheit */
    void SwitchMode();

private:
    /* Mode of the temperature */
    eTemp temp_mode;
};

#endif /* TEMPERATURESENSOR_H_ */