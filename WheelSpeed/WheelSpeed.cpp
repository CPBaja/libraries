/*
	WheelSpeed.cpp - Library for PhotoGate control.
	Created by Rahul Goyal and Tyler Davis, January 20, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#include "Arduino.h"
#include "WheelSpeed.h"

WheelSpeed::WheelSpeed(int pin, int triggers) {
	PIN = pin;
	TRIGGERS = triggers;
	pinMode(PIN, INPUT);
	prevTime = micros();
}

float WheelSpeed::getRPS() { return RPS; }
void WheelSpeed::overrideRPS(float artificalRPS = 0) { RPS = artificalRPS; }
int WheelSpeed::getPin() { return PIN; }

void WheelSpeed::calcRPS() {
    currTime = micros();
    RPS = secToHz(currTime - prevTime);
    prevTime = currTime;
}

float WheelSpeed::secToHz(unsigned long timeDiff) {
	float secPerRotation = (timeDiff / 1000000.0) * TRIGGERS;
    return 1 / secPerRotation;
}