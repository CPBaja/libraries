/*
	LiveDisplay.cpp - Library to display live data.
	Created by Rahul Goyal and Tyler Davis, February 15, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#include <Arduino.h>
#include <LiveDisplay.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static unsigned char PROGMEM const logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif



// Constructor
LiveDisplay::LiveDisplay(int chars) {

	CHARS = chars;

}



void LiveDisplay::begin() {

	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	write("Baja!");
	delay(2500);



	// Display Baja car splash screen
	// ...

}



void LiveDisplay::write(float num) {

	// Reset
	reset();
	
	// Convert float to string and truncate value
	String str = String(num).substring(0, CHARS);

	// Display value
	display.println(str);
	display.display();

}



void LiveDisplay::write(String str) {
	
	// Reset
	reset();

	// Truncate value
	str = str.substring(0, CHARS);

	// Display value
	display.println(str);
	display.display();

}



// Helper method
void LiveDisplay::reset() {
	display.clearDisplay();
	display.setTextSize(7);
	display.setTextColor(WHITE);
	display.setCursor(0, 16);
}
