/*
	PhotoGate.h - Library header for PhotoGate control.
	Created by Tyler Davis and Rahul Goyal, January 20, 2017.
	Released to Cal Poly Baja SAE. ;)
*/



#ifndef WheelSpeed_h
#define WheelSpeed_h

#include "Arduino.h"



class WheelSpeed {

	public:
		// Constructor
		WheelSpeed(int pin, int resolution);
		
		float getRps();
		int getPin();
		void calcRps();
		float secToHz(unsigned long timeDiff);

	private:

		int PIN;
		int RESOLUTION;		

		unsigned long prevTime;
		unsigned long currTime;

		float rps = 0.0;
		
};

#endif