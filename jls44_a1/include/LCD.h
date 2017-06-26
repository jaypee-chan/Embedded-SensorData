/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/
/* Class LCD which contains C12832 sensor*/

#ifndef LCD_H_
#define LCD_H_

#include <iostream>
#include "C12832/C12832.h"

#include <vector>
#include <iterator>

class LCD {
public:
    LCD(PinName mosi, PinName sck, PinName reset, PinName a0, PinName ncs);
    ~LCD() {}

    /* Welcome message when you launch the mbed */
    void Welcome();
    /* Clear LCD screen */
    void Clear();
    /* Print string in the LCD screen */
    void Print(std::string const &);
    /* Print the speed for getting data from the mbed */
    void PrintDelay(float);
    /* Print temperature */
    void PrintTemperature(float, char);
    /* Print compass */
    void PrintCompass(float, std::string const &);
    /* Print the main menu */
    void PrintMenu(int p);
    /* Print quit */
    void PrintQuit();

private:
    /* LCD screen */
    C12832 c_lcd;
    /* vector which contains the options to choose for the main menu*/
    std::vector<std::string> v_menu;
};

#endif /* LCD_H_ */