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
	TRIGGERS = triggers;

	// Initialize prevTime
	prevTime = micros();
}

void WheelSpeed::calc() {
	// Calculate and update speed
	currTime = micros();
	// Rotations per Second (RPS)
	_speed = (float)1000000 / ((currTime - prevTime) * TRIGGERS);
	// // Rotations per Minute (RPM)
	// _speed = (float)60000000 / ((currTime - prevTime) * TRIGGERS);

	// Update prevTime
	prevTime = currTime;
}

float WheelSpeed::get() {
	if (micros() - prevTime >= TIMEOUT) {
		return 0;
	}
	return _speed;
}