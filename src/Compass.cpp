/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/

#include "Compass.h"

/* I2c bus */
I2C i2c(PTE25, PTE24);

/* To retrieve the axis6 from eCompass libray's header, to get the compass angle */
extern axis6_t axis6;

/* Parameters for the constructor of magnetometer and accelerometer*/
Compass::Compass(uint8_t addr) : mag(i2c, addr), acc(i2c, addr) {
    /* enabling accelerometer and magnetometer*/
    acc.enable();
    mag.enable();
}

/* Return the angle of the compass */
float Compass::GetAngle() const {
    return axis6.yaw;
}

float Compass::GetCompass() {
    /* Get the axis in raw values of the accelerometer and magnetometer. */
    acc.getAxis(acc_raw);
    mag.getAxis(mag_raw);
    /* Run the eCompass */
    run(acc_raw, mag_raw);
    /* After running it, we can return the angle.  */
    return GetAngle();
}