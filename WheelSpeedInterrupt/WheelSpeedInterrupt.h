/*
	PhotoGate.h - Library header for PhotoGate control.
	Created by Tyler Davis and Rahul Goyal, January 20, 2017.
	Released to Cal Poly Baja SAE. ;)
*/



#ifndef WheelSpeedInterrupt_h
#define WheelSpeedInterrupt_h

#include "Arduino.h"



class WheelSpeed {

	public:
		// Constructor
		WheelSpeed(int pin, int resolution);
		
		int getRps();
		int getPin();
		void calcRps();
		float secToHz(unsigned long timeDiff);

	private:

		int PIN;
		int RESOLUTION;		
		int INTERRUPT_VECTOR;

		unsigned long prevTime;
		unsigned long currTime;

		float rps = 0.0;
		
};

#endif