/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security    */
/* Internet of Things and Mobile Devices - CO838 University of Kent             */
/* Class speaker to play sound */
/* The PlayNote method was inspired by the speaker_demo_PWM */
/* https://developer.mbed.org/users/4180_1/code/speaker_demo_PWM/ */

#ifndef SPEAKER_H_
#define SPEAKER_H_

#include "mbed.h"

class Speaker {
public:
    Speaker(PinName p);
    ~Speaker() {};

/* Play note of a piano by taking its frequency, duration */
    void PlayNote(float frequency, float duration);
/* Play Spirited away's music  */
    void PlayMusic();
    /* Play fire sound when player press on enter or back btn */
    void Fire();
/* Play move sound when player move */
    void Move();

private:
    PwmOut pin;

};
#endif /* SPEAKER_H_ */