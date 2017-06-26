/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/
/* Class Compass */
/* Inherit from the library eCompass class. It just has functions to get the compass' angle. */
/* The eCompass library was developed by Jim Carver and can be found in: */
/* https://developer.mbed.org/users/JimCarver/code/eCompass_Lib/        */

#ifndef COMPASS_H_
#define COMPASS_H_

#include "FXOS8700Q.h"
#include "eCompass_Lib.h"

/* Inherit the public eCompass class, to get the method to get the Angle. */
class Compass : public eCompass {
public:
    /* Get the address for the FXOS8700Q sensor */
    Compass(uint8_t addr);
    /* Destructor */
    ~Compass() {};
    
    /* Get compass angle */
    float GetAngle() const;
    /* Get Axis and return compass angle  */
    float GetCompass();
    

private:
    /* Magnetometer sensor */
    FXOS8700QMagnetometer mag;
    /* Accelerometer sensor */
    FXOS8700QAccelerometer acc;
    /* motion data counts that will containt the raw values of the accelerometer and magnetometer */
    motion_data_counts_t acc_raw, mag_raw;
};

#endif /* COMPASS_H_ */