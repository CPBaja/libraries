/*
	PhotoGate.cpp - Library for PhotoGate control.
	Created by Rahul Goyal, August 19, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#include "Arduino.h"
#include "PhotoGate.h"



PhotoGate::PhotoGate() {}



void PhotoGate::init(int pin) {
	// Pin
	PIN = pin;
	pinMode(PIN, OUTPUT);

	resetCal();
	resetRun();
}


void PhotoGate::resetCal() {
	// Reset high and low
	_hi = 0;
	_lo = 1023;
}



void PhotoGate::resetRun() {
	// Reset time
	_time = 0;
}



unsigned long PhotoGate::getTime() {
	return _time;
}



void PhotoGate::updateAll() {
	// Read light
	_light = analogRead(PIN);

	// Update high
	if (_light > _hi) {
		_hi = _light;
		Serial.println("Calibrating high...");
	}

	// Update low
	if (_light < _lo) {
		_lo = _light;
		Serial.println("Calibrating low...");
	}

	// Update mid
	_md = AVG(_lo, _hi);

	// Check trigger
	if (_light < _md) {

		Serial.println("Triggered!");
		
		if (_time == 0) {
			_time = micros();
			Serial.println("Time recorded!");
		}
	}
}