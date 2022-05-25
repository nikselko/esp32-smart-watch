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

#include "bioData.h"

BioData::BioData()
{
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST))
    Serial.println("MAX30102 was not found. Please check wiring/power/solder jumper at MH-ET LIVE MAX30102 board. ");
};

String BioData::displayHeart()
{
#define INTERVAL_MESSAGE2 60000  
#define TIMETOBOOT 3000 // wait for this time(msec) to output SpO2
#define SCALE 88.0      //adjust to display heart beat and SpO2 in the same scale
#define SAMPLING 5      //if you want to see heart beat more precisely , set SAMPLING to 1
#define FINGER_ON 3000  // if red signal is lower than this , it indicates your finger is not on the sensor
#define MINIMUM_SPO2 0.0

  unsigned long time_2 = 0;
  int period = 2000;
  unsigned long time_now = 0;
  double avered = 0;
  double aveir = 0;
  double sumirrms = 0;
  double sumredrms = 0;
  int i = 0;
  int Num = 100; //calculate SpO2 by this sampling interval
  
  int oxygen;
  double ESpO2 = 95.0;    //initial value of estimated SpO2
  double FSpO2 = 0.7;     //filter factor for estimated SpO2
  double frate = 0.95;    //low pass filter for IR/red LED value to eliminate AC component

  
  const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
  byte rates[RATE_SIZE];    //Array of heart rates
  byte rateSpot = 0;
  long lastBeat = 0; //Time at which the last beat occurred
  float beatsPerMinute;
  int beatAvg;
  
  byte ledBrightness = 255; // 0x7F Options: 0=Off to 255=50mA
  byte sampleAverage = 4;   //Options: 1, 2, 4, 8, 16, 32
  byte ledMode = 2;         //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
  int sampleRate = 400;     //1000 is best but needs processing power//Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
  int pulseWidth = 411;     //Options: 69, 118, 215, 411
  int adcRange = 16384;     //Options: 2048, 4096, 8192, 16384
  
  uint32_t ir, red, green;
  double fred, fir;
  double SpO2 = 0; //raw SpO2 before low pass filtered
  String to_return;
  
  if (!particleSensor.getIR())
    to_return = String("Bpm / SpO2");
  else
  {
  #ifdef USEFIFO
    particleSensor.check(); //Check the sensor, read up to 3 samples
  
    while (particleSensor.available())
    {
  #ifdef MAX30105
      red = particleSensor.getFIFORed();
      ir = particleSensor.getFIFOIR();
      
  #else
      red = particleSensor.getFIFOIR();
      ir = particleSensor.getFIFORed();
      
  #endif
      i++;
      fred = (double)red;
      fir = (double)ir;
      avered = avered * frate + (double)red * (1.0 - frate);
      aveir = aveir * frate + (double)ir * (1.0 - frate);
      sumredrms += (fred - avered) * (fred - avered);
      sumirrms += (fir - aveir) * (fir - aveir);             
      
      if ((i % SAMPLING) == 0)
      {
        if (millis() > TIMETOBOOT)
        {
          if (ir < FINGER_ON)
            ESpO2 = MINIMUM_SPO2;
          if (ESpO2 <= -1)
            ESpO2 = 0;
          if (ESpO2 > 100)
            ESpO2 = 100;
  
          oxygen = ESpO2;
        }
      }
      if ((i % Num) == 0)
      {
        double R = (sqrt(sumredrms) / avered) / (sqrt(sumirrms) / aveir);
        SpO2 = -23.3 * (R - 0.4) + 100;
        ESpO2 = FSpO2 * ESpO2 + (1.0 - FSpO2) * SpO2; 
        sumredrms = 0.0;
        sumirrms = 0.0;
        i = 0;
        break;
      }
      particleSensor.nextSample();
    }
    to_return = String(String(beatAvg) + " / " + String(oxygen));
  #endif
  }
};
