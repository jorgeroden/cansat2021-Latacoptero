#include <Wire.h>
#include "Adafruit_VEML6075.h"

Adafruit_VEML6075 uv = Adafruit_VEML6075();

void initUV() {
 
  Serial.println("VEML6075 Full Test");
  if (! uv.begin()) {
    Serial.println("Failed to communicate with VEML6075 sensor, check wiring?");
  }
  Serial.println("Found VEML6075 sensor");

}

String getUV() {

  return String(uv.readUVA()) + "," + String(uv.readUVB()) + "," + String(uv.readUVI());
}
