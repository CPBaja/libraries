/*
	LiveDisplay.cpp - Library to display live data.
	Created by Rahul Goyal and Tyler Davis, February 15, 2017.
	Released to Cal Poly Baja SAE. ;)
*/



#ifndef LiveDisplay_h
#define LiveDisplay_h

#include "Arduino.h"

class LiveDisplay {

	public:
		// Constructor
		LiveDisplay(int chars);

		// Methods
		void begin();
		void write(float num);
		void write(String str);

	private:
		int CHARS;

		// Helper method
		void reset();

};

#endif