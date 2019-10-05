/*
 * EngineSpeed.cpp - Library for measuring engine speed.
 * Created by Rahul Goyal, July 1 2019.
 * Released to Cal Poly Baja SAE. ;)
 */

#include <Arduino.h>
#include "EngineSpeed.h"

const unsigned long TIMEOUT = 1000000;

// Constructor
EngineSpeed::EngineSpeed(byte triggers) {
	// Initialize variables
	this->triggers = triggers;
	for (int i = 0; i < triggers; i++) {
		times[i] = micros();
	}
}

void EngineSpeed::calc() {
	// Calculate and update speed
	currTime = micros()
	// speed = (float)1000000 / ((currTime - prevTime[pos]) * triggers);	// Rotations per Second (RPS)
	speed = (float)60000000 / ((currTime - prevTime[pos]) * triggers);	// Rotations per Minute (RPM)

	// Update prevTime
	prevTime[pos] = currTime;
	pos++;
	if pos >= triggers {
		pos = 0;
	}
}

float EngineSpeed::get() {
	if (micros() - prevTime >= TIMEOUT) {
		return 0;
	}
	return speed;
}