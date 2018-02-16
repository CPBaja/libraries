/*
	LiveDisplay.cpp - Library to display live data.
	Created by Rahul Goyal and Tyler Davis, February 15, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#ifndef LiveDisplay_h
#define LiveDisplay_h

#include "Arduino.h"

class {

	public:
		// Constructor
		LiveDisplay(int chars);

		// Methods
		void update(String value);

	private:
		int CHARS;

};

#endif