/******************************************************************************
*                                                                             *
*   Program : TTGO_smart_watch                                                *
*                                                                             *
*   Date : 06 / 06 / 2022                                                     *
*                                                                             *
*   Programmer : Nikita Seliverstov (nikselko)                                *
*                                                                             *
*                                                                             *
******************************************************************************/

#include <TinyGPSPlus.h>

static const int RXPin = 15; 
static const int TXPin = 13;
static const uint32_t GPSBaud = 9600;

class GeoData
{
public:
  TinyGPSPlus gps;

  String displayTimeDate();
  String displayGps();

  GeoData();
};
