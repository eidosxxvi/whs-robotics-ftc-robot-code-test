#pragma config(Sensor, S4,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-irseeker-v2-SMUX-test1.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * hitechnic-irseeker-v2.h provides an API for the HiTechnic IR Seeker V2.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Driver renamed to HTIRS2
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER.

 * Xander Soldaat (xander_at_botbench.com)
 * Dick Swan
 * 06 April 2010
 * version 0.2
 */

#include "hitechnic-sensormux.h"
#include "hitechnic-irseeker-v2.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor HTIRS2 = msensor_S4_1;

// global variables
string sTextLines[8];

// function prototypes
void displayText(int nLineNumber, const string cChar, int nValueDC, int nValueAC);
void displayInstructions();

// main task
task main ()
{
  int _dirDC = 0;
  int _dirAC = 0;
	int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;
	int acS1, acS2, acS3, acS4, acS5 = 0;
	string tmpString;

  // show the user what to do
  displayInstructions();

  eraseDisplay();
  for (int i = 0; i < 8; ++i)
    sTextLines[i] = "";

  // display the current DSP mode
  // When connected to a SMUX, the IR Seeker V2 can only be
  // used in 1200Hz mode.
  nxtDisplayTextLine(0, "      DC  1200");

  // The sensor is connected to the first port
  // of the SMUX which is connected to the NXT port S1.
  // To access that sensor, we must use msensor_S1_1.  If the sensor
  // were connected to 3rd port of the SMUX connected to the NXT port S4,
  // we would use msensor_S4_3

  while (true)
  {
    // Read the current non modulated signal direction
    _dirDC = HTIRS2readDCDir(HTIRS2);
    if (_dirDC < 0)
      break; // I2C read error occurred

    // read the current modulated signal direction
    _dirAC = HTIRS2readACDir(HTIRS2);
    if (_dirAC < 0)
      break; // I2C read error occurred

    // Read the individual signal strengths of the internal sensors
    // Do this for both unmodulated (DC) and modulated signals (AC)
    if (!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5))
      break; // I2C read error occurred
    if (!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5 ))
      break; // I2C read error occurred

      displayText(1, "D", _dirDC, _dirAC);
      displayText(2, "0", dcS1, acS1);
      displayText(3, "1", dcS2, acS2);
      displayText(4, "2", dcS3, acS3);
      displayText(5, "3", dcS4, acS4);
      displayText(6, "4", dcS5, acS5);
    if (HTSMUXreadPowerStatus(HTSMUX))
      nxtDisplayTextLine(7, "Batt: bad");
    else
      nxtDisplayTextLine(7, "Batt: good");
  }
}

// Display the instructions to the user
void displayInstructions()
{
  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "IRSeekr2");
  nxtDisplayCenteredTextLine(3, "SMUX Test");
  nxtDisplayCenteredTextLine(5, "Connect SMUX to");
  nxtDisplayCenteredTextLine(6, "S1 and sensor to");
  nxtDisplayCenteredTextLine(7, "SMUX Port 1");
  wait1Msec(2000);
}

// Minimize LCD screen flicker by only updating LCD when data has changed
void displayText(int nLineNumber, const string cChar, int nValueDC, int nValueAC)
{
  string sTemp;

  StringFormat(sTemp, "%4d  %4d", nValueDC, nValueAC);
  // Check if the new line is the same as the previous one
  // Only update screen if it's different.
  if (sTemp != sTextLines[nLineNumber])
  {
    string sTemp2;

    sTextLines[nLineNumber] = sTemp;
    StringFormat(sTemp2, "%s:  %s", cChar, sTemp);
    nxtDisplayTextLine(nLineNumber, sTemp2);
  }
}

/*
 * $Id: hitechnic-irseeker-v2-SMUX-test1.c 133 2013-03-10 15:15:38Z xander $
 */
