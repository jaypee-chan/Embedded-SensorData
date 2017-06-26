/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/
/* class LED which contains 3 colors of led*/
#ifndef LED_H_
#define LED_H_

#include "mbed.h"

class LED {
public:
    LED(PinName R, PinName G, PinName B);
    ~LED() {};
    
    /* enum to see which LED to switch on and off. */
    enum eLED {RED = 0, GREEN = 1, BLUE = 2};
    /* switch on LED */
    void SwitchOn(eLED);
    /* switch Off selected led*/
    void SwitchOff(DigitalOut);
    /* switch off all led */
    void SwitchOffAll();
    
private:
    DigitalOut red; //D5
    DigitalOut green; //D8
    DigitalOut blue; //D9
};

#endif /* LED_H_ */