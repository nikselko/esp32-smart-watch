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

#include "geoData.h"

GeoData::GeoData()
{
  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println("No GPS detected");  
}

String GeoData::displayTimeDate() 
{
  String m_hour, m_minute, m_second;
  
  if (gps.time.hour() < 10)
    m_hour = String('0' + String(gps.time.hour()));
  else
    m_hour = String(gps.time.hour());
    
  if (gps.time.minute() < 10)
    m_minute = String('0' + String(gps.time.minute()));
  else
    m_minute = String(gps.time.minute());
    
  if (gps.time.second() < 10)
    m_second = String('0' + String(gps.time.second()));
  else
    m_second = String(gps.time.second());
    
  String to_return = String(m_hour + ':' + m_minute + ':' + m_second + '%' + String(gps.date.day()) + " / " + String(gps.date.month()) + " / " + String(gps.date.year()));
  return to_return;
};

String GeoData::displayGps() 
{
  String to_return = String(String(gps.location.lat(), 1) + " : " + String(gps.location.lng(),1));
  return to_return;
};
