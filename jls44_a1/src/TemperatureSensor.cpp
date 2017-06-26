#include "TemperatureSensor.h"

/* Instanciate the global object of LM75B which can read the temperature */
LM75B g_lm75b(D14, D15);

TemperatureSensor::TemperatureSensor() : temp_mode(CELSIUS) {
}

/* Get the ambiant temperature */
float TemperatureSensor::GetTemperature() const {
    /* Read temperature */
    float temperature = g_lm75b.read();
    /* If the temperature sensor is set in Fahrenheit */
    if (temp_mode == FAHRENHEIT) {
        /* Convert the Celsius in Fahrenheit. */
        temperature = temperature * (9.0/5.0) + 32.0;
    }
    /* Return temperature */
    return temperature;
}

/* Switch temperature mode */
void TemperatureSensor::SwitchMode() {
    switch (temp_mode) {
        /* In the case it's set in celsius mode, set it in fahrenheit */
        case CELSIUS:
            SetFahrenheit();
            break;
        /* In the case it's set in fahrenheit mode, set it in celsius */
        case FAHRENHEIT:
            SetCelsius();
            break;
        default:
            SetCelsius();
            break;
    }
}

/* Set temperature sensor in celsius */
void TemperatureSensor::SetCelsius() {
    temp_mode = CELSIUS;
}

/* return true if the temperature sensor is set in celsius  */
bool TemperatureSensor::IsCelsius() {
    return (temp_mode == CELSIUS ? true : false);
}

/* Set temperature sensor in fahrenheit */
void TemperatureSensor::SetFahrenheit() {
    temp_mode = FAHRENHEIT;
}

/* return true if the temperature sensor is set in fahrenheit  */
bool TemperatureSensor::IsFahrenheit() {
    return (temp_mode == FAHRENHEIT ? true : false);
}

/* get the temperature sensor mode  */
TemperatureSensor::eTemp TemperatureSensor::GetMode() const {
    return temp_mode;
}
