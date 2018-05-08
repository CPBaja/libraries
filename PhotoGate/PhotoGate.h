/*
	PhotoGate.h - Library header for PhotoGate control.
	Created by Rahul Goyal, August 19, 2017.
	Released to Cal Poly Baja SAE. ;)
*/



#ifndef PhotoGate_h
#define PhotoGate_h

#include "Arduino.h"

#define RESETBUTTON 9

// (Tune This)
#define AVG(_X,_Y) (((_X) + (_Y)) / 2)

class PhotoGate {

	public:
		// Constructors
		PhotoGate();
		void init(int pin, int calibButton);

		// Reset calibration
		void resetCal();

		// Reset time
		void resetRun();

		// Shows stats/status
		unsigned long getTime();

		// Update high, low, mid (and trigger)
		void updateAll();

	private:
		int _pin;
		int _calibButton;

		// updateAll variables
		int _hi, _md, _lo;
		int _light;
		unsigned long _time;

};

#endif