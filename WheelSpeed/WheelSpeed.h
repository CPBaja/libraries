/*
	WheelSpeed.h - Library header for measuring wheel speed.
	Created by Tyler Davis and Rahul Goyal, January 20, 2017.
	Released to Cal Poly Baja SAE. ;)
*/



#ifndef WheelSpeed_h
#define WheelSpeed_h

#include <Arduino.h>

class WheelSpeed {

	public:
		
		// Constructor
		WheelSpeed(byte triggers);

		// Methods
		void calcRPS();
		float getRPS();
		void setRPS(float rps);

	private:

		byte PIN;
		byte TRIGGERS;

		volatile unsigned long prevTime;
		volatile unsigned long currTime;

		volatile float RPS = 0;

		// // Helper method
		// volatile float usToRPS(unsigned long usDelta);
		
};

#endif