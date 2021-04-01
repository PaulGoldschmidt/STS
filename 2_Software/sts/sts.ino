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

// DHT stuff
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

bool dhtworking = true;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Callibri15);
  oled.displayRemap(true);
  oled.clear();
  oled.println("Stating STS (2/3).");
  oled.println("Sens con: WAIT");
  sensors.begin();
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0); 
  oled.clear();
  if (temperature == -127) {
    oled.println("Stating STS (2/3).");
    oled.println("Sens con: FAILED");
    while(1);
  }
  else {
    oled.println("Stating STS (2/3).");
    oled.println("Sens con: SUCCESS");
  }
  oled.clear();
  oled.println("Stating STS (3/3).");
  oled.println("Sens con: SUCCESS");
  oled.println("DHT con: WAIT");
  dht.begin();
  float h = dht.readHumidity();
  oled.clear();
  if (isnan(h)) {
    oled.println("Stating STS (3/3).");
    oled.println("Sens con: SUCCESS");
    oled.println("DHT con: FAILED");
    dhtworking = false;
    delay(10000); // Its possible to use the sensor without a working dht sensor
  }
  else {
    oled.println("Stating STS (3/3).");
    oled.println("Sens con: SUCCESS");
    oled.println("DHT con: SUCCESS");  
  }
  delay(1000);
  oled.clear();
  oled.println("Initalisation successful.");
  oled.println("");
  oled.println("          Starting STS     ");
  oled.println("      V 1.0 (April 2021)   ");
  delay(2500);
}

void loop() {
  // put your main code here, to run repeatedly:

}
