/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/
/* Class SensorData which is the main class of this project*/

#ifndef SENSORDATA_H_
#define SENSORDATA_H_

#include "mbed.h"

#include "LCD.h"
#include "TemperatureSensor.h"
#include "Speaker.h"
#include "Compass.h"
#include "LED.h"

class SensorData {
public:
    SensorData();
    ~SensorData() {};
    
    void Start();

    enum ePage { TEMPERATURE = 0, COMPASS = 1, MUSIC = 2, ENTER_TEMP = 3, 
                                                          ENTER_COMPASS = 4 };
    
    
private:
    void MainLoop();
    void MenuSelection();

    void InitCommand();
    void ChangePosition();
    void Up();
    void Down();
    void Enter();
    void Pause();
    void Back();
    
    void SwitchPause();

    /* LCD object */
    LCD lcd;

    /* Temperature sensor object */
    TemperatureSensor ts;
    /* Print temperature in the LCD screen */
    void DisplayTemperature();
    /* Delay to get data */
    float delay;
    

    /*  Speaker */
    Speaker speaker;

    /*  Compass */
    Compass compass;
    void DisplayCompass();

    /*  LED      */
    LED led;
    void ChangeLED();

    /*  Menu    */
    int pos;
    ePage epage;
    
    /* quit variable, if quit == 3, quit the program. */
    int quit;
    
    /* Pause variable */
    bool pause_sensor;
};

#endif /* SENSORDATA_H_ */