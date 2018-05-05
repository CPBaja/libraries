/*
	PhotoGate.h - Library header for PhotoGate control.
	Created by Rahul Goyal, August 19, 2017.
	Released to Cal Poly Baja SAE. ;)
*/



#ifndef PhotoGate_h
#define PhotoGate_h

#include "Arduino.h"

class PhotoGate {

	public:
		// Constructor
		PhotoGate(int pin, int calibButton, int resetButton);
		
		// Reset calibration
		void resetCal();

		// Reset time
		void resetRun();

		// Shows stats/status
		long showStats();

		// Update high, low, mid (and trigger)
		void updateAll();

	private:
		int _pin;
		int _calibButton, _resetButton;

		// updateAll variables
		int _hi, _md, _lo;
		int _light;
		long _time;

};

#endif