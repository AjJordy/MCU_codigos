
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerWifi.h>

#define USERNAME "ajjordy"
#define DEVICE_ID "esp8266"
#define DEVICE_CREDENTIAL "i60hWHfkDbo!"

#define SSID "CEI"
#define SSID_PASSWORD "#CEI-ufg16%"

ThingerWifi thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  // resource input example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << [](pson& in){ digitalWrite(13, in ? HIGH : LOW); };

//  // resource output example (i.e. reading a sensor value)
//  thing["millis"] >> [](pson& out){ out = millis(); };
//
//  // resource input/output example (i.e. passing input values and do some calculations)
//  thing["in_out"] = [](pson& in, pson& out){
//      out["sum"] = (long)in["value1"] + (long)in["value2"];
//      out["mult"] = (long)in["value1"] * (long)in["value2"];
//  };
}

void loop() {
  thing.handle();
}
