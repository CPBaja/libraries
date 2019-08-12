/*
    PhotoGate.h - Library for measuring wheel speed.
    Created by Tyler Davis and Rahul Goyal, January 20, 2018.
    Released to Cal Poly Baja SAE. ;)
*/



#include "Arduino.h"
#include "WheelSpeed.h"



WheelSpeed::WheelSpeed(int pin, int resolution) {
	PIN = pin;
    pinMode(PIN, INPUT);
	RESOLUTION = resolution;
}



float WheelSpeed::getSpeed() {

    boolean signalReading = digitalRead(PIN);

    if (signalReading == AIR && wasOnMetal) {
        wasOnAir = true;
        wasOnMetal = false;
    }

    if (signalReading == METAL && wasOnAir) {

        unsigned long currTime = micros();
        rps = secToHz(currTime - prevTime);
        prevTime = currTime;
        
        wasOnMetal = true;
        wasOnAir = false;
    } 

    // Timeout
    if (micros() - prevTime > 1000000) {
        rps = 0.0;
    }

    return rps;
}

float WheelSpeed::secToHz(unsigned long timeDiff) {
	float secPerRotation = (timeDiff / 1000000.0) * RESOLUTION;
    return 1 / secPerRotation;
}