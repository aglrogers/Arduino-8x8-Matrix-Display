/*
 * Small program to test an 8x8 matrix display with a MAXIM 7219 driver chip.
 * Cycles through four preset image patterns on a loop.
 */

// Library for MAX7219 display drivers
#include "LedControl.h"

// set up display
LedControl mymatrix = LedControl(11, 13, 10, 1);

// Delay between images
int delay_interval = 1000;


void setup()
{
  // Turn on the display
  mymatrix.shutdown(0, false);

  // Set brightness to low value
  mymatrix.setIntensity(0, 1);

  // Clear the display
  mymatrix.clearDisplay(0);
}

// Byte array - square pattern
byte p_squares[8] = {B11111111,
                     B10000001,
                     B10111101,
                     B10100101,
                     B10100101,
                     B10111101,
                     B10000001,
                     B11111111
                    };

// Byte array - dotted pattern
byte p_dots[8] = {B10101010,
                  B01010101,
                  B10101010,
                  B01010101,
                  B10101010,
                  B01010101,
                  B10101010,
                  B01010101
                 };

// Byte array - diagonal line pattern
byte p_diagonals[8] = {B10010010,
                       B00100100,
                       B01001001,
                       B10010010,
                       B00100100,
                       B01001001,
                       B10010010,
                       B00100100
                      };

// Byte array - snaky line pattern
byte p_snake[8] = {B00000001,
                   B11111111,
                   B10000000,
                   B11111111,
                   B00000001,
                   B11111111,
                   B10000000,
                   B11111111
                  };

// Function for writing a byte array to the display
void WriteImage(byte img[])
{
  // Set each row of the display to each row of the byte array
  mymatrix.setRow(0, 0, img[0]);
  mymatrix.setRow(0, 1, img[1]);
  mymatrix.setRow(0, 2, img[2]);
  mymatrix.setRow(0, 3, img[3]);
  mymatrix.setRow(0, 4, img[4]);
  mymatrix.setRow(0, 5, img[5]);
  mymatrix.setRow(0, 6, img[6]);
  mymatrix.setRow(0, 7, img[7]);
}

void loop()
{
  // Cycle through the images on a loop forever
  
  WriteImage(p_squares);
  delay(delay_interval);

  WriteImage(p_dots);
  delay(delay_interval);

  WriteImage(p_diagonals);
  delay(delay_interval);

  WriteImage(p_snake);
  delay(delay_interval);
}
