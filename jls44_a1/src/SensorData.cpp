/* Developed by Jean-Paul Saysana - jls44 - MSc Student in Computer Security */
/* Internet of Things and Mobile Devices - CO838 University of Kent         */
/* Class SensorData which is the main Object of this project            */
/* It contains every objects and sensor of this project and combine it together*/

#include "SensorData.h"

/* Instantiate UP, DOWN, BACK(SW2), ENTER(SW3) buttons. */
InterruptIn up(A2);
InterruptIn down(A3);
InterruptIn enter(D4);
InterruptIn pause(SW2);
InterruptIn back(SW3);

/* Instantiate the potentiometer and the serial host to communicate with a computer. */
AnalogIn pot (A1);
Serial host(USBTX, USBRX);

/* Initialize the object lcd, speaker, compass and led */
SensorData::SensorData() : lcd(D11, D13, D12, D7, D10), speaker(D6),
                            compass(FXOS8700CQ_SLAVE_ADDR1), led(D5, D8, D9) {
    /* Setting every value to default, the position of the selector at 0 */
    pos = 0;
    /* Point temperature */
    epage = TEMPERATURE;
    /* setting the wait time to 0.7s by default */
    delay = 0.7;
    /* if quit == 3, end the program */
    quit = 0;
    /* pause variable set to false */
    pause_sensor = false;
}

/* Init the interruption commmand */
void SensorData::InitCommand() {
    up.rise(callback(this, &SensorData::Up));
    down.rise(callback(this, &SensorData::Down));
    enter.rise(callback(this, &SensorData::Enter));
    pause.rise(callback(this, &SensorData::Pause));
    back.rise(callback(this, &SensorData::Back));
}

/* Method that start the SensorData  */
void SensorData::Start() {
    /* Display the welcome animation when user start the mbed card. */
    lcd.Welcome();
    /* Initialize the buttons(interruptions) */
    InitCommand();
    /* Display the menu selection */
    MenuSelection();
    /* Loop indefinetly until user quit the program. */
    while(quit < 3) {
        /* Main loop checking the position of the user */
        MainLoop();
        /* Waiting delay time for user display */
        wait(delay);
    }
    lcd.PrintQuit();
}

/* Change LED color depending on the degree of the potentiometer */
void SensorData::ChangeLED() {
    if ((float)pot < 0.20f) {
        return led.SwitchOffAll();
    }
    else if ((float)pot > 0.80f) {
        return led.SwitchOn(LED::BLUE);
    }
    else if ((float)pot > 0.60f) {
        return led.SwitchOn(LED::GREEN);
    }
    else if ((float)pot > 0.40f) {
        return led.SwitchOn(LED::RED);
    }
}

/* Main loop that check the page of the player */
void SensorData::MainLoop() {
    switch (epage) {
/* if the player clicked on "Current temperature", it displays the temperature */
        case ENTER_TEMP:
            if (!pause_sensor) {
                DisplayTemperature();
            }
            break;
/* if the player clicked on "Compass", it displays the compass */
        case ENTER_COMPASS:
            if (!pause_sensor) {
                DisplayCompass();
            }
            break;
        default:
            break;
    }
    /* Checking  */
    ChangeLED();
}

/* Display the temperature in the LCD screen */
void SensorData::DisplayTemperature() {
    lcd.Clear();
    /* Get the temperature unit. If it's in fahrenheit, unit character is 'F'
        Otherwise, it's set to 'C'. */
    char t_unit = (ts.IsFahrenheit() == true ? 'F' : 'C');
    /* Print in the LCD screen. */
    lcd.PrintDelay(delay);
    lcd.PrintTemperature(ts.GetTemperature(), t_unit);
    /* Report temperature over USB Serial link*/
    host.printf("Temperature is %.2f %c \r\n", ts.GetTemperature(), t_unit);
}

/* Display compass */
void SensorData::DisplayCompass() {
    lcd.Clear();
    /* Get compass angle */
    float angle = compass.GetCompass();
    /* If the angle is below or between certains values. */
    /* the dir variable will store the direction. */
    std::string dir = "";
    if (angle > 45 && angle <= 135) {       dir = "East"; }
    else if (angle > 135 && angle <= 225) { dir = "South"; }
    else if (angle > 225 && angle <= 315) { dir = "West"; }
    else {                                  dir = "North"; }
    lcd.PrintDelay(delay);
    lcd.PrintCompass(angle, dir);
    host.printf("Compass angle = %.2f - Direction = %s \r\n", compass.GetCompass(), dir.c_str());
}

/* Interruption with enter button */
void SensorData::Enter() {
    // set quit variable at 0
    quit = 0;
    /* play sound, enter to the page, switch mode for the temperature. */
    speaker.Fire();
    switch (epage) {
        case TEMPERATURE:
            epage = ENTER_TEMP;
            break;
        case COMPASS:
            epage = ENTER_COMPASS;
            break;
        case MUSIC:
            speaker.PlayMusic();
            break;
        case ENTER_TEMP:
            ts.SwitchMode();
            break;
        case ENTER_COMPASS:
            break;
        default:
            break;
    }
}

void SensorData::SwitchPause() {
    pause_sensor = (pause_sensor == false ? true : false);
}

/* Press back, show back menu selection */
void SensorData::Pause() {
    speaker.Fire();
    switch (epage) {
        case ENTER_COMPASS:
            SwitchPause();
            break;
        case ENTER_TEMP:
            SwitchPause();
            break;            
        default:
            break;
    }
}

/* Press back, show back menu selection */
void SensorData::Back() {
    pause_sensor = false;
    speaker.Fire();
    switch (epage) {
        case ENTER_COMPASS:
            epage = COMPASS;
            break;
        case ENTER_TEMP:
            epage = TEMPERATURE;
            break;            
        default:
            ++quit;
            break;
    }
    MenuSelection();
}

/* Press up button, change delay if entered somewhere else change selector position */
void SensorData::Up() {
    // set variable quit at 0
    quit = 0;
    switch (epage) {
        case ENTER_TEMP:
            if (delay < 2) {
                delay += 0.1f;
            }
            break;
        case ENTER_COMPASS:
            if (delay < 2) {
                delay += 0.1f;
            }
            break;
        default:
            if (pos > 0) {
                --pos;
                ChangePosition();
            }
        break;
    }
}

/* press down and change position*/
void SensorData::Down() {
    // set variable quit at 0
    quit = 0;
    switch (epage) {
        case ENTER_TEMP:
            if (delay > 0.4f) {
                delay -= 0.1f;
            }
            break;
        case ENTER_COMPASS:
            if (delay > 0.4f) {
                delay -= 0.1f;
            }
            break;
        default:
            if (pos < MUSIC) {
                ++pos;
                ChangePosition();
            }
            break;
    }
}

/* change epage position */
void SensorData::ChangePosition() {
    switch (pos) {
        case TEMPERATURE:
            epage = TEMPERATURE;
            break;
        case COMPASS:
            epage = COMPASS;
            break;
        case MUSIC:
            epage = MUSIC;
            break;
        default:
            break;
    }
    MenuSelection();
    speaker.Move();
}

/* Print menu selection */
void SensorData::MenuSelection() {
    wait(0.1);
    lcd.Clear();
    lcd.PrintMenu(pos);
}
