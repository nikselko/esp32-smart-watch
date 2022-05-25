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

#include "geoData.h"

GeoData::GeoData()
{
  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println("No GPS detected");  
}

String GeoData::displayTime() 
{
  String to_return = String(String(gps.time.hour()) + ':' + String(gps.time.minute()) + ':' + String(gps.time.second()));
  return to_return;
};

String GeoData::displayDate() 
{
  String to_return = String(String(gps.date.day()) + '/' + String(gps.date.month()) + '/' + String(gps.date.year()));
  return to_return;
};

String GeoData::displayGps() 
{
  String to_return = String(String(gps.location.lat()) + " | " + String(gps.location.lng()));
  return to_return;
};
