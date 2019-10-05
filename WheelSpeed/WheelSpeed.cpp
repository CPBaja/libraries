/*
 * WheelSpeed.cpp - Library for measuring wheel speed.
 * Created by Rahul Goyal, July 1 2019.
 * Released to Cal Poly Baja SAE. ;)
 */

#include <Arduino.h>
#include "WheelSpeed.h"

const unsigned long TIMEOUT = 1000000;

// Constructor
WheelSpeed::WheelSpeed(byte triggers) {
	// Initialize variables
	this->triggers = triggers;
	prevTime = micros();
}

void WheelSpeed::calc() {
	// Calculate and update speed
	currTime = micros();
	speed = (float)1000000 / ((currTime - prevTime) * triggers);	// Rotations per Second (RPS)
	// speed = (float)60000000 / ((currTime - prevTime) * triggers);	// Rotations per Minute (RPM)

	// Update prevTime
	prevTime = currTime;
}

float WheelSpeed::get() {
	if (micros() - prevTime >= TIMEOUT) {
		return 0;
	}
	return speed;
}