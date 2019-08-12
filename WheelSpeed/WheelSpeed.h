/*
 *	WheelSpeed.h - Library header for measuring wheel speed.
 *	Created by Rahul Goyal, July 1, 2019.
 *  Released to Cal Poly Baja SAE. ;)
 */

#ifndef WheelSpeed_h
#define WheelSpeed_h

#include <Arduino.h>

class WheelSpeed {

	public:
		// Constructor
		WheelSpeed(byte triggers);

		// Methods
		void calc();
		float get();

	private:
		byte TRIGGERS;

		volatile unsigned long prevTime;
		volatile unsigned long currTime;

		volatile float _speed = 0;

};

#endif