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

#include "bmp.h"
#include "geoData.h"
#include "bioData.h"
#include "User_Setup.h"
#include <TFT_eSPI.h>

struct TFTEngine
{
  TFT_eSPI tft = TFT_eSPI();
  GeoData geo = GeoData();
  BioData bio = BioData();
public:
  void displayInfo();
  TFTEngine();
};
