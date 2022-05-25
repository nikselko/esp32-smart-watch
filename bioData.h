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

#include <Wire.h>
#include <SimpleTimer.h>
#include "MAX30105.h"

class BioData
{
public:
  MAX30105 particleSensor;
  SimpleTimer timer;

  String displayHeart();

  BioData();
};
