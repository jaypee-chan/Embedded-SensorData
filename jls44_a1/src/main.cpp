/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security */
/* Internet of Things and Mobile Devices - CO838 University of Kent         */
/* First assignement - Sensor Data of the module                            */
/* This software can:                                                       */
/* - Display the current temperature in celsius, fahrenheit                 */
/* - Display The compass angle to locate the user                           */
/* - A speaker to play Music                                                */
/* - A potentiometer to change the LED color                                */
/* - An useful menu to diplay or listen what ever you want                  */
/* It also has some sound when moving the selector                          */
/* You can quit the program by pressing the Back(SW3) button 3 times        */

#include "mbed.h"
#include "SensorData.h"

int main() {
    /* Instantiate the object Sensor Data*/
    SensorData sd;

    /* Starting the sensor data. */
    sd.Start();
    return (0);
}