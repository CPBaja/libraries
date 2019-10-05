/*
 *	EngineSpeed.h - Library header for measuring engine speed.
 *	Created by Rahul Goyal, July 1, 2019.
 *  Released to Cal Poly Baja SAE. ;)
 */

#ifndef EngineSpeed_h
#define EngineSpeed_h

#include <Arduino.h>

class EngineSpeed {

	public:
		// Constructor
		EngineSpeed(byte triggers);

		// Methods
		void calc();
		float get();

	private:
		byte triggers;
		byte pos = 0;

		volatile float speed = 0;

		volatile unsigned long prevTime[100];
		volatile unsigned long currTime;
};

#endif