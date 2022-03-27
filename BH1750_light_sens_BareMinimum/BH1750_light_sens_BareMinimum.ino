# DOES NOT WORK

//for help look at: https://github.com/Starmbi/hp_BH1750/wiki
#include <Arduino.h>
#define PIN_I2C_POWER 7
#include <hp_BH1750.h>  //  include the library
hp_BH1750 BH1750;       //  create the sensor



void setup()
{

  
  Serial.begin(9600);
  Serial.print("hello\n");

    // put your setup code here, to run once:
  // turn on the I2C power by setting pin to opposite of 'rest state'
  pinMode(PIN_I2C_POWER, INPUT);
  delay(1);
  bool polarity = digitalRead(PIN_I2C_POWER);
  pinMode(PIN_I2C_POWER, OUTPUT);
  digitalWrite(PIN_I2C_POWER, !polarity);

  
  bool avail = BH1750.begin(BH1750_TO_GROUND);// init the sensor with address pin connetcted to ground
                                              // result (bool) wil be be "false" if no sensor found
}

void loop()
{
  // put your main code here, to run repeatedly:
  BH1750.start();   //starts a measurement
  float lux=BH1750.getLux();  //  waits until a conversion finished
  Serial.println(lux);       
}
