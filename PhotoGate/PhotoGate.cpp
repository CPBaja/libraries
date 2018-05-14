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
	pinMode(PIN, INPUT);

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



int PhotoGate::getHigh() {
	return _hi;
}



int PhotoGate::getLight() {
	return _light;
}



int PhotoGate::getLow() {
	return _lo;
}



int PhotoGate::getMid() {
	return _md;
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

	// Update mid (tune this)
	_md = (_lo * 0.5 + _hi * 0.5);

	// Check trigger
	if (_light < _md) {

		// Serial.println("Triggered!");

		if (_time == 0) {
			_time = micros();
			Serial.println("Time recorded!");
		}

	}

}