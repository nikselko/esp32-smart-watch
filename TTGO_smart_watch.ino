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

#define BUTTON_BOOT_PIN  GPIO_NUM_0
#define BUTTON_EN_PIN  GPIO_NUM_4
#define INIT_STATE 0
#define GPS_STATE 1
#define HEART_STATE 2

#include <SoftwareSerial.h>

#include "TFTEngine.h"

TFTEngine m_TFT = TFTEngine();

SoftwareSerial ss(RXPin, TXPin);
byte m_state = INIT_STATE;

void setup()
{
  m_TFT.bio.particleSensor.begin(Wire, I2C_SPEED_FAST);  
  m_TFT.bio.particleSensor.setup(); //Configure sensor with default settings
  m_TFT.bio.particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  m_TFT.bio.particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED     
  ss.begin(GPSBaud);
  Serial.begin(GPSBaud);
  Serial.print(F("TinyGPSPlus library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
}

void loop()
{
  if(m_TFT.bio.particleSensor.getIR() > 45000)
    m_state = HEART_STATE;
  else
  {
    if (m_state == HEART_STATE)
      m_state = INIT_STATE;
      
    if(gpio_get_level(BUTTON_BOOT_PIN) == LOW)
    {
      if(m_state == GPS_STATE)
        m_state = INIT_STATE;
      else
      {
        if (m_state == INIT_STATE)
          m_state = GPS_STATE;
      }
    }
  }
  
  while (ss.available() > 0)
  {
    if (m_TFT.geo.gps.encode(ss.read()))
    {
      if(m_state == HEART_STATE)
        m_TFT.displayHeartPage();
      
      if(m_state == INIT_STATE)
        m_TFT.displayTimePage();    
              
      if(m_state == GPS_STATE)
        m_TFT.displayGpsPage();
    }
  }
}
