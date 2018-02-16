/*
	WheelSpeed.cpp - Library for measuring wheel speed.
	Created by Rahul Goyal and Tyler Davis, January 20, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#include "Arduino.h"
#include "WheelSpeed.h"



// Constructor
WheelSpeed::WheelSpeed(int pin, int triggers) {
	PIN = pin;
	TRIGGERS = triggers;

	// Set pin mode
	pinMode(PIN, INPUT);

	// Initialize prevTime
	prevTime = micros();
}



void WheelSpeed::calcRPS() {

	// Calculate and update RPS
	RPS = usToRPS(micros() - prevTime);

	// Update prevTime
	prevTime = currTime;
}



int WheelSpeed::getPin() {
	return PIN;
}



float WheelSpeed::getRPS() {
	return RPS;
}



void WheelSpeed::overrideRPS(float rps = 0) {
	RPS = rps;
}



// Helper method
float WheelSpeed::usToRPS(unsigned long usDelta) {
	float secDelta = usDelta / 100000.0;
	float period = secDelta * TRIGGERS;
	float frequency = 1 / period;
	return frequency;
}