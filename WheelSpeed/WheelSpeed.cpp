/*
	WheelSpeed.cpp - Library for measuring wheel speed.
	Created by Rahul Goyal and Tyler Davis, January 20, 2018.
	Released to Cal Poly Baja SAE. ;)
*/

#include <Arduino.h>
#include "WheelSpeed.h"

#define TIMEOUT 1000000

// Constructor
WheelSpeed::WheelSpeed(byte triggers) {

	TRIGGERS = triggers;

	// Initialize prevTime
	prevTime = micros();
	
}



void WheelSpeed::calcRPS() {

	// Calculate and update RPS
	currTime = micros();
	RPS = (1000000.0 / (currTime - prevTime)) / TRIGGERS;
	// RPS = usToRPS(currTime - prevTime);

	// Update prevTime
	prevTime = currTime;

}



float WheelSpeed::getRPS() {
	if (micros() - prevTime >= TIMEOUT) {
		RPS = 0;
	}
	return RPS;
}



void WheelSpeed::setRPS(float rps) {
	RPS = rps;
}



// // Helper method
// float WheelSpeed::usToRPS(unsigned long usDelta) {
// 	// float secDelta = usDelta / 1000000.0;
// 	// float period = secDelta * TRIGGERS;
// 	// float frequency = 1 / period;
// 	// return frequency;
// 	return (1000000.0 / usDelta) / TRIGGERS;
// }