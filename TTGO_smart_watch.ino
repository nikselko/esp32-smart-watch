/******************************************************************************
*                                                                             *
*   Program : TTGO_smart_watch                                                *
*                                                                             *
*   Date : 25 / 05 / 2022                                                     *
*                                                                             *
*   Programmer : Nikita Seliverstov (nikselko)                                *
*                                                                             *
*                                                                             *
******************************************************************************/

#include <SoftwareSerial.h>
#include "TFTEngine.h"

TFTEngine m_TFT = TFTEngine();
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  ss.begin(GPSBaud);
  Serial.begin(GPSBaud);
  Serial.print(F("TinyGPSPlus library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
}

void loop()
{
  while (ss.available() > 0)
    if (m_TFT.geo.gps.encode(ss.read()))
      m_TFT.displayInfo();
}
