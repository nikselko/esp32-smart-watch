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

#include "TFTEngine.h"

TFTEngine::TFTEngine() { tft.begin(); };

void TFTEngine::displayTimePage()
{ 
  String tmp_str = geo.displayTimeDate();
  String tmp_time = String(tmp_str.substring(0, tmp_str.indexOf('%')));
  String tmp_date = String(tmp_str.substring(tmp_str.indexOf('%') + 1, tmp_str.length()));

  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);
  tft.setCursor (102, 60);
  tft.setTextFont(4);
  tft.setTextColor(TFT_BLUE, TFT_YELLOW);
  tft.print("TIME");  
  tft.setCursor (162, 60);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.print("GPS");
    
  tft.setCursor(40, 92);
  tft.setTextFont(7);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.print(tmp_time);
  
  tft.setCursor(100, 145);
  tft.setTextFont(4);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.print(tmp_date);

  tft.setCursor(110, 170);
  tft.setTextFont(2);
  tft.setTextColor(TFT_YELLOW, TFT_BLUE);
  tft.print("nikselko github");
};

void TFTEngine::displayGpsPage()
{
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);
  tft.setCursor (102, 60);
  tft.setTextFont(4);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.print("TIME");
  tft.setCursor (162, 60);
  tft.setTextColor(TFT_BLUE, TFT_YELLOW);
  tft.print("GPS");
   
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.setRotation(1);
  tft.setCursor(40, 92); 
  tft.setTextFont(7);
  tft.print(geo.displayGps());

  tft.setCursor(77, 147);
  tft.setTextFont(4);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.print("(lat)");
  tft.setCursor(187, 147);
  tft.print("(lng)");

  tft.setCursor(110, 170);
  tft.setTextFont(2);
  tft.setTextColor(TFT_YELLOW, TFT_BLUE);
  tft.print("nikselko github");
};

void TFTEngine::displayHeartPage()
{
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);
  tft.drawBitmap(140, 60, logo_bmp, 32, 32, TFT_YELLOW);

  tft.setCursor(92, 132);
  tft.setTextFont(4);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.print("BPM  / SpO2");

  tft.setCursor(110, 170);
  tft.setTextFont(2);
  tft.setTextColor(TFT_YELLOW, TFT_BLUE);
  tft.print("nikselko github");
  
  tft.setCursor(115, 106);
  tft.setTextFont(4);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.print(bio.displayHeart());
  delay(600);
};
