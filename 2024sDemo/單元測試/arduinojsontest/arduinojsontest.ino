#include <ArduinoJson.h>

void setup() {
  
      Serial.begin(9600);
      while (!Serial) continue;
      StaticJsonDocument<200> doc;

char json[] =
      "{\
        \"sensor\":\"gps\"              \
        ,\"time\":1351824120,           \
        \"data\":[48.756080,2.302038]   \
        }";
char json2[]="{\
           \"led\":\"on\",\
          \"motor\":\"on\",\
          \"atomizer\":\"on\",\
          \"lcd\":\"hello jimmy\"\
         }";

      DeserializationError error = deserializeJson(doc, json2);

      Serial.print("json2= ");
      Serial.println(json2);

  if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;

}
      const char* led = doc["led"];
      const char*motor = doc["motor"];
      const char* atomizer = doc["atomizer"];
      const char* lcd = doc["lcd"];

      Serial.println(led);
      Serial.println(motor);
      Serial.println(atomizer);
      Serial.println(lcd);
}

void loop() {
  

}
