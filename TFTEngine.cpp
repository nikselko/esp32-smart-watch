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

#include "TFTEngine.h"

TFTEngine::TFTEngine()
{
  tft.begin();
  tft.setTextColor(TFT_GREEN);
};

void TFTEngine::displayInfo()
{
  tft.fillScreen(TFT_BLACK);
  tft.setCursor (71, 65);
  tft.setTextFont(4);
  tft.setTextColor(TFT_BLUE, TFT_YELLOW);
  tft.print("nikselko");
  
  tft.setCursor(68, 115);
  tft.setTextFont(4);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  
  if (geo.gps.time.isValid())
    tft.print(geo.displayTime());
  else
    tft.print("INVALID");

  tft.setCursor(60, 143);
  tft.setTextFont(4);
  
  if (geo.gps.date.isValid())
    tft.print(geo.displayDate());
  else
    tft.print("INVALID");
  
  tft.setCursor(62, 170); 
  tft.setTextFont(2);
  
  if (geo.gps.location.isValid())
    tft.print("GPS: " + geo.displayGps());
  else
    tft.print("INVALID");
  tft.drawBitmap(60, 210, logo_bmp, 32, 32, TFT_YELLOW);
  tft.setCursor(105, 220);
  tft.setTextFont(2);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  //tft.print(bio.displayHeart());
  tft.print("Bpm / SpO2");
  
  
  
};
