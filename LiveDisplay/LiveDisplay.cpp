/*
	LiveDisplay.cpp - Library to display live data.
	Created by Rahul Goyal and Tyler Davis, February 15, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#include <Arduino.h>
#include "LiveDisplay.h"

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
// #include <Fonts/FreeMonoBold18pt7b.h>
// #include <Fonts/FreeMonoBold24pt7b.h>

LiveDisplay carDisplay;

// Back right angle
const int baja_car[] PROGMEM = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, 0, 0, 2047, -1, -1, -1, -1, -4, 0, 0, 511, -1, -1, -1, -1, -7, -97, -4096, 511, -1, -1, -1, -1, -13, -97, -8192, 511, -1, -1, -1, -1, -13, -241, -8192, 511, -1, -1, -1, -1, -29, -461, -16384, 511, -1, -1, -1, -1, -57, -839, -16384, 255, -1, -1, -1, -1, -41, -580, -32768, 255, -1, -1, -1, -1, -73, -1601, 0, 255, -1, -1, -1, -1, -217, -3265, -32768, 255, -1, -1, -1, -1, -145, -2177, 0, 255, -1, -1, -1, -1, -401, -6273, 0, 127, -1, -1, -1, -1, -785, -12417, 0, 127, -1, -1, -1, -1, -561, -8578, 0, 127, -1, -1, -1, -1, -1057, -16642, 0, 127, -1, -1, -1, -1, -3105, 16124, 0, 63, -1, -1, -1, -1, -6178, 32508, 0, 63, -1, -1, -1, -1, -4194, -260, 0, 63, -1, -1, -1, -1, -12356, -772, 0, 319, -1, -1, -1, -1, -24679, -772, 0, 287, -1, -1, -1, -1, -16477, -1992, 0, 31, -1, -1, -1, -1, 16177, -8184, 0, 415, -1, -1, -1, -2, 32550, 544, 0, 415, -1, -1, -1, -4, 15, -31952, 0, 415, -1, -1, -1, -4, 3, -8168, 0, 415, -1, -1, -1, -8, 3, -2024, 0, 399, -1, -1, -1, -16, 0, -1040, 0, 911, -1, -1, -1, -32, 0, 112, 0, 871, -1, -1, -1, -8, 0, 0, 0, 227, -1, -1, -1, -7, -10240, 0, 0, 236, -3, -1, -1, -2023, 6144, 0, 0, 612, 32640, 32767, -1, -16383, -13312, 0, 0, 880, 13824, 8191, -1, 0, 27648, 0, 0, 1841, -32768, 4095, -1, 0, 27648, 0, 0, 1047, -16384, 2047, -4, 1, -7168, 0, 0, 3, -8192, 2047, -4, 0, -7168, 0, 0, 1, -4096, 1023, -8, 0, 0, 0, 0, 128, 0, 1023, -8, 0, 0, 0, 0, 0, 0, 1023, -16, 0, 0, 0, 0, 8215, -32768, 1023, -16, 0, 15360, 0, 0, 8199, -8192, 1023, -16, 0, 8192, 0, 0, 32767, -8192, 1023, -16, 0, 4095, -2048, 3, -1, -8192, 1023, -16, 0, 32767, -1024, 3, -1, -4096, 1023, -8, 0, 32767, -1024, 3, -1, -4096, 2047, -8, 0, -1, -1024, 7, -1, -4096, 2047, -8, 0, -1, -1024, 15, -1, -2048, 4095, -4, 1, -1, -512, 31, -1, -1024, 4095, -2, 3, -1, -512, 31, -1, -512, 8191, -1, 7, -1, -512, 63, -1, -256, 32767, -1, -16353, -1, -256, 63, -1, -29, -1, -1, -513, -1, -128, 127, -1, -1, -1, -1, -1, -1, -64, 255, -1, -1, -1, -1, -1, -1, -32, 1023, -1, -1, -1, -1, -1, -1, -4, 8191, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 64
#define INT_SIZE 16

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

LiveDisplay::LiveDisplay() {}

void LiveDisplay::begin() {

	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

	// Display Baja! Splash Screen
	// clear();
	// display.setFont(&FreeMonoBold18pt7b);
	// display.setTextSize(1);
	// display.setCursor(16, 42);
	// display.println("Baja!");
	// display.display();
	// delay(5000);

	// Display Baja car splash screen
	clear();
	int pix_num = 0;
	for (int idx = 0; idx < IMAGE_WIDTH * IMAGE_HEIGHT / INT_SIZE; idx++) {
		int mask = 0x8000;
		int pixel_group = pgm_read_byte_near(baja_car + idx); 
		while (mask) {
			if (pixel_group & mask) {
				display.drawPixel(pix_num % IMAGE_WIDTH, pix_num / IMAGE_WIDTH, WHITE);
			}
			pix_num++;
			mask >>= 1;
		}
	}
	display.display();
	delay(10000);

}



void LiveDisplay::clear() {
	display.clearDisplay();
	display.setTextColor(WHITE);
}



void LiveDisplay::title(String str) {
	
	// Reset
	// display.setFont();
	display.setTextSize(2);
	display.setCursor(0,0);

	// Print value
	display.println(str);

}



void LiveDisplay::write(float num, int chars) {

	// Reset
	// display.setFont(&FreeMonoBold24pt7b);
	display.setTextSize(1);
	display.setCursor(24, 54);
	
	// Convert float to string and truncate value
	String str = String(num).substring(0, chars);

	// Print and display value
	display.println(str);
	display.display();

}



void LiveDisplay::write(String str, int chars) {
	
	// Reset
	// display.setFont(&FreeMonoBold24pt7b);
	display.setTextSize(1);
	display.setCursor(24, 54);

	// Truncate value
	str = str.substring(0, chars);

	// Print and display value
	display.println(str);
	display.display();

}