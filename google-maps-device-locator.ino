#include <google-maps-device-locator.h>

GoogleMapsDeviceLocator locator;

void setup() {
  Serial.begin(9600);
  // Scan for visible networks and publish to the cloud every 30 seconds
  // Pass the returned location to be handled by the locationCallback() method
  locator.withSubscribe(locationCallback).withLocatePeriodic(30);
}

void locationCallback(float lat, float lon, float accuracy) {
  // Handle the returned location data for the device. This method is passed three arguments:
  // - Latitude
  // - Longitude
  // - Accuracy of estimated location (in meters)
  String dataJson = String("{")
        + "\"lat\":" + String::format("%f", lat)
        + ",\"lng\":" + String::format("%f", lon)
        + ",\"unc\":" + String::format("%f", accuracy)
        + ",\"url\":" + String::format("\"https://www.google.com/maps/place/%f,%f\"", lat, lon)
        + "}";

  Particle.publish("current_location", dataJson, 60, PRIVATE);
}

void loop() {
  locator.loop();
}