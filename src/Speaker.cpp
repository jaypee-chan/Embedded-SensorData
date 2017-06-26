/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/
/* Class speaker to play sound */

#include "Speaker.h"


Speaker::Speaker(PinName p) : pin (p) {
}

/* Play note of a piano by taking its frequency, duration and volume, */
void Speaker::PlayNote(float frequency, float duration) {
    pin.period(1.0f/frequency);
    pin = 1/2.0f;
    wait(duration);
    pin = 0.0;
}

/* Play fire sound when player press on enter or back btn */
void Speaker::Fire() {
    PlayNote(554.365, 0.1);
}

/* Play move sound when player move */
void Speaker::Move() {
    PlayNote(830.609, 0.1);
}

/* Play Spirited away's music  */
void Speaker::PlayMusic() {
    float frequency[14]= { 349.228231433004, 391.995435981749, 440,349.228231433004,
    523.251130601197, 440, 391.995435981749, 523.251130601197, 391.995435981749,
    349.228231433004, 293.664767917408, 440, 349.228231433004, 329.62755691287};

    for (int i = 0; i < 14; ++i) {
        PlayNote(frequency[i], 0.3);
    }
}