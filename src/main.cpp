#include <Arduino.h>

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop()
{
  float iVal;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  float valToVoltage = iVal * 3.3 / 1024;

  float voltageToTemperature = 50 * valToVoltage / 3.3;
  String judgement;
  if (voltageToTemperature < 10)
  {
    judgement = " Cold!";
  }
  else if (voltageToTemperature >= 10 && voltageToTemperature < 15)
  {
    judgement = " Cool";
  }
  else if (voltageToTemperature >= 15 && voltageToTemperature < 25)
  {
    judgement = " Perfect";
  }
  else if (voltageToTemperature >= 25 && voltageToTemperature < 30)
  {
    judgement = " Warm";
  }
  else if (voltageToTemperature >= 30 && voltageToTemperature < 35)
  {
    judgement = " Hot";
  }
  else if (voltageToTemperature >= 35)
  {
    judgement = " Too Hot!";
  }
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temperature input of " + voltageToTemperature + " deg. C, " + "which is " + judgement);

  delay(500);
}