/*
	WheelSpeed.cpp - Library for measuring wheel speed.
	Created by Rahul Goyal and Tyler Davis, January 20, 2018.
	Released to Cal Poly Baja SAE. ;)
*/

#include "Arduino.h"
#include "WheelSpeed.h"



// Constructor
WheelSpeed::WheelSpeed(int triggers) {

	TRIGGERS = triggers;

	// Initialize prevTime
	prevTime = micros();
	
}



void WheelSpeed::calcRPS() {

	// Calculate and update RPS
	currTime = micros();
	RPS = usToRPS(currTime - prevTime);

	// Update prevTime
	prevTime = currTime;

}



float WheelSpeed::getRPS() {
	return RPS;
}



void WheelSpeed::overrideRPS(float rps = 0) {
	RPS = rps;
}



// Helper method
float WheelSpeed::usToRPS(unsigned long usDelta) {
	float secDelta = usDelta / 1000000.0;
	float period = secDelta * TRIGGERS;
	float frequency = 1 / period;
	return frequency;
}