/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security*/
/* Internet of Things and Mobile Devices - CO838 University of Kent*/
#include "LCD.h"

/* Parameters for the C12832's lcd constructor. */
LCD::LCD(PinName mosi, PinName sck, PinName reset, PinName a0, PinName ncs) : c_lcd(mosi, sck, reset, a0, ncs){
    /* Pushing the main menu options */
    v_menu.push_back("Current temperature");
    v_menu.push_back("Compass");
    v_menu.push_back("Music");
}

/* Welcome message */
void LCD::Welcome() {
    /* Clear screen */
    /* Displaying the welcome animation */
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < i; ++j) {
            Print(" ");
        }
        Print("Welcome \n");
        wait(0.1);
        Clear();
    }
    wait(0.2);
    /* Signature of the app */
    Clear();
    Print("Project: Sensor Data \n");
    Print("Developed by:\n");
    Print("Jean-Paul Saysana.\n");
    wait(2);
    Clear();
}
/* Display the menu using an iterator */
/* The selected option will have an left arrow pointing on it. */
void LCD::PrintMenu(int p) {
    int i = 0;
    Clear();
    for (std::vector<std::string>::const_iterator it = v_menu.begin();
                                            it != v_menu.end();
                                            ++it) {
        std::string tmp_str = *it;
        if (i == p) {
            tmp_str += " <-";
        }
        Print(tmp_str + "\n");
        ++i;
    }
}

/* CLean and set the position at 0,0. */
void LCD::Clear() {
    c_lcd.cls();
    c_lcd.locate(0,0);
}

/* Print string */
void LCD::Print(std::string const &str) {
    c_lcd.printf(str.c_str());
}

/* Print delay */
void LCD::PrintDelay(float f) {
    c_lcd.printf("Get data every : %.2f s\r\n", f);
}

/* Print temperature */
void LCD::PrintTemperature(float temperature, char unit) {
    c_lcd.printf("Temperature is %.2f %c.\r\n", temperature, unit);
}

/* Print compass */
void LCD::PrintCompass(float angle, std::string const &str) {
    c_lcd.printf("Compass angle = %.2f \r\nDirection = %s \r\n", angle, str.c_str());
}

void LCD::PrintQuit() {
    Clear();
    c_lcd.printf("See you soon ! \r\n");
    wait(1);
    Clear();
}