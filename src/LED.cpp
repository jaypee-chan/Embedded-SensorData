/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/

#include "LED.h"

LED::LED(PinName R, PinName G, PinName B) : red(R), green(G), blue(B) {
}

/* switch on selected color of led and turn off the rest. */
void LED::SwitchOn(eLED color) {
    switch (color) {
      case RED:
        red = 1;
        SwitchOff(blue);
        SwitchOff(green);
        break;
      case BLUE:
        blue = 1;
        SwitchOff(red);
        SwitchOff(green);
        break;
      case GREEN:
        green = 1;
        SwitchOff(blue);
        SwitchOff(red);
        break;
    };
}

/* switch off selected led */
void LED::SwitchOff(DigitalOut p) {
    p = 0;
}

/* switch off every led (white) */
void LED::SwitchOffAll() {
    red = 0;
    green =0;
    blue = 0;
}
