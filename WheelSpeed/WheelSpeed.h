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
		
		float getRPS();
		void overrideRPS(float artificalRPS = 0);
		int getPin();
		void calcRPS();

	private:

		float secToHz(unsigned long timeDiff);


		int PIN;
		int TRIGGERS;		

		unsigned long prevTime;
		unsigned long currTime;

		float RPS = 0.0;
		
};

#endif