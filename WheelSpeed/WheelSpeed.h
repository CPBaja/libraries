/*
	PhotoGate.h - Library header for PhotoGate control.
	Created by Tyler Davis and Rahul Goyal, August 19, 2017.
	Released to Cal Poly Baja SAE. ;)
*/



#ifndef WheelSpeed_h
#define WheelSpeed_h

#include "Arduino.h"



class WheelSpeed {

	public:
		// Constructor
		WheelSpeed(int pin, int resolution);
		
		float getSpeed();
		float secToHz(unsigned long timeDiff);

	private:
		int PIN;
		int RESOLUTION;

		const static boolean METAL = LOW;
		const static boolean AIR = HIGH;

		unsigned long prevTime;
		unsigned long currTime;

		float rps = 0.0;

		boolean wasOnAir = true;
		boolean wasOnMetal = false;

};

#endif