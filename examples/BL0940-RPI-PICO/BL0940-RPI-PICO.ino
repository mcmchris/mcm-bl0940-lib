/*
 * Install the Raspberry Pi Pico DSP
 * Put this URL on preferences: https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
 * Go to the Boards Manager and search for: Raspberry Pi Pico
 * Install the DSP from: Earle F. Philhower
 */

#include "MCM_BL0940.h"

BL0940 bl0940;

void setup() {
  // For the USB, just use Serial as normal:
  Serial.begin(115200);

  // Configure Serial2 on pins TX=GP8 and RX=GP9
  Serial2.begin(4800);

  bl0940.Reset();
  bl0940.setFrequency(60);    //50[Hz]
  bl0940.setUpdateRate(800);  //400[ms]

}

void loop() {
  float voltage;
  bl0940.getVoltage(&voltage);
  Serial.print(voltage,2);
  Serial.println(" V");

  float current;
  bl0940.getCurrent(&current);
  Serial.print(current,2);
  Serial.println(" A");

  float activePower;
  bl0940.getActivePower(&activePower);
  Serial.print(activePower,2);
  Serial.println(" W");

  float activeEnergy;
  bl0940.getActiveEnergy(&activeEnergy);
  Serial.print(activeEnergy,2);
  Serial.println(" kWh");

  float powerFactor;
  bl0940.getPowerFactor(&powerFactor);
  Serial.print(powerFactor);
  Serial.println(" %");

  float temperature;
  bl0940.getTemperature(&temperature);
  Serial.print(temperature,2);
  Serial.println(" deg C");

  Serial.println("");
  delay(1000);
}
