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
  
#define INTERVAL_MESSAGE2 60000  
#define TIMETOBOOT 3000
#define SCALE 88.0
#define SAMPLING 5
#define FINGER_ON 80000
#define MINIMUM_SPO2 0.0

#include <Wire.h>
#include <SimpleTimer.h>

#include "MAX30105.h"
#include "heartRate.h"

const byte RATE_SIZE = 4;
 
class BioData
{
public:
  MAX30105 particleSensor;
  SimpleTimer timer;

  byte rates[RATE_SIZE];
  String displayHeart();
  
  BioData();
};
