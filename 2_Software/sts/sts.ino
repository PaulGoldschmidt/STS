//OLED Stuff
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;

// Dellas Temp. Sensor Stuff (DS18B20)
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 6
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Callibri15);
  oled.displayRemap(true);
  oled.clear();
  oled.println("Stating STS (2/3).");
  oled.println("Sens con:");
  sensors.begin();
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0); 
  oled.clear();
  if (temperature == -127) {
    oled.println("Stating STS (2/3).");
    oled.println("Sens con: FAILED");
  }
  else {
    oled.println("Stating STS (2/3).");
    oled.println("Sens con: SUCCESS");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
