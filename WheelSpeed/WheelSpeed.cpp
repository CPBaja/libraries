/*
	WheelSpeed.cpp - Library for PhotoGate control.
	Created by Rahul Goyal and Tyler Davis, January 20, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#include "Arduino.h"
#include "WheelSpeed.h"

WheelSpeed::WheelSpeed(int pin, int resolution) {
	PIN = pin;
	RESOLUTION = resolution;
	pinMode(PIN, INPUT);
	prevTime = micros();
}

float WheelSpeed::getRps() { return rps; }
int WheelSpeed::getPin() { return PIN; }

void WheelSpeed::calcRps() {
    currTime = micros();
    rps = secToHz(currTime - prevTime);
    prevTime = currTime;
}

float WheelSpeed::secToHz(unsigned long timeDiff) {
	float secPerRotation = (timeDiff / 1000000.0) * RESOLUTION;
    return 1 / secPerRotation;
}