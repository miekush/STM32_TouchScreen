//Basic test using the 4" ILI9486 TFT Display and Resistive Touchscreen
//When pressed, the touch x-y coordinates and pressure are displayed on the display

//author: Mike Kushnerik / MKE https://github.com/mkengineering
//date: 11-17-2020

#include <STM32_ILI9486_8_bit.h> //display library
#include <STM32_TouchScreen.h> //ts library

STM32_ILI9486_8_bit tft;

//pin assignments for touch screen pins

#define XM PA5 //must be an analog pin
#define YP PA6 //must be an analog pin
#define XP PA7 //can be an analog or digital pin
#define YM PB0 //can be an analog or digital pin

TouchScreen ts = TouchScreen(XP, YP, XM, YM);

void setup(void)
{
  analogReadResolution(12); //for ts analog inputs
  
  tft.begin();
  
  ts.rangeSet(320, 480);
  
  tft.fillScreen(BLACK);

  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  
  tft.setCursor(10, 0);
  tft.print("X: ");

  tft.setCursor(10, 20);
  tft.print("Y: ");

  tft.setCursor(10, 40);
  tft.print("Pressure: ");
}

void loop()
{
  TSPoint p;
  
  if ( ts.getPoint(&p) ) {
    
    tft.setTextColor(WHITE);
    tft.fillRect(40, 0, 50, 40, BLACK); //erase previous points
    
    tft.setCursor(40, 0);
    tft.print(p.x);

    tft.setCursor(40, 20);
    tft.print(p.y);

    tft.setTextColor(WHITE, BLACK);
    tft.setCursor(120, 40);
    tft.print(p.z);
    
  }
}