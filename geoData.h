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

#include <TinyGPSPlus.h>

static const int RXPin = 22; 
static const int TXPin = 17;
static const uint32_t GPSBaud = 9600;

class GeoData
{
public:
  TinyGPSPlus gps;
  
  String displayTime();
  String displayDate();
  String displayGps();

  GeoData();
};
