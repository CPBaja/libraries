/*
	WheelSpeed.h - Library header for measuring wheel speed.
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

		// Methods
		void calcRPS();
		int getPin();
		float getRPS();
		void overrideRPS(float rps = 0);

	private:

		int PIN;
		int TRIGGERS;		

		unsigned long prevTime;
		unsigned long currTime;

		float RPS = 0.0;

		// Helper method
		float usToHz(unsigned long usDelta);
		
};

#endif