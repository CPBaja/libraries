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
		void init(int pin);

		// Reset calibration
		void resetCal();

		// Reset time
		void resetRun();

		// Shows stats/status
		unsigned long getTime();

		// Update high, low, mid (and trigger)
		void updateAll();

	private:
		// Constructor parameters
		int PIN;

		// updateAll variables
		int _light;
		int _hi, _md, _lo;
		unsigned long _time;

};

#endif