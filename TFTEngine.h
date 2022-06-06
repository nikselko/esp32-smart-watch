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

#include "bmp.h"
#include "geoData.h"
#include "bioData.h"
#include "User_Setup.h"
#include <TFT_eSPI.h>
#include <SPI.h>

struct TFTEngine
{
public:
  TFT_eSPI tft = TFT_eSPI();
  GeoData geo = GeoData();
  BioData bio = BioData();
  
  void displayTimePage();
  void displayGpsPage();
  void displayHeartPage();
  int tmp_today;
  
  TFTEngine();
};
