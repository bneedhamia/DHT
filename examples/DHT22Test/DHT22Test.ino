/*
 * Example use of the DHT22 (RHT03) Library
 * http://playground.arduino.cc/Main/DHTLib
 * Test Sketch by Bradford Needham: @bneedhamia, https://github.com/bneedhamia
 * In the spirit of the library, this example is placed in the Public Domain.
 *
 * RHT03 parts and datasheets are available from Sparkfun: https://www.sparkfun.com/products/10167
 *
 * Note: the library is modified from the original:
 * digitalRead() is used instead of portInputRegister() because
 * Arduino 101 doesn't support portInputRegister().
 * This change can be turned off by editing dht.cpp and changing HAS_PIR from 0 to 1
 * then restarting your Aduino IDE.
 *
 * Tested on Arduino Uno and Arduino 101.
 */

#include <dht.h>

/*
 * Pinout:
 *   DHT22 pin 1 --> power input, connected to Arduino 3.3V
 *   DHT22 pin 2 --> signal output to Arduino (connect to DHT22_DATA)
 *   DHT22 pin3 & 4 --> Arduino GND. Both 3 and 4 are grounded because
 *     some DHT22's expect pin 3 to be grounded, while others expect pin 4 to be grounded.
 *   
 *   BOARD_LED = the Arduino built-in LED.
 */
const int DHT22_DATA = 7;

const int BOARD_LED = 13;

const long MIN_READ_DELAY_MS  = 2500; // the sensor can't be read more often than "about 2 seconds"
long lastReadMs;  // time (ms) when we last read the sensor.

dht dht22;    // manages the DHT22 temperature/Humidity sensor

void setup() {
  Serial.begin(9600);
  pinMode(DHT22_DATA, INPUT);
  pinMode(BOARD_LED, OUTPUT);
  digitalWrite(BOARD_LED, LOW);
  
  lastReadMs = millis();
}

void loop() {
  long nowMs = millis();

  if (nowMs - lastReadMs < MIN_READ_DELAY_MS) {
    return;  // too early to read.
  }
  lastReadMs = nowMs;

  // Read the sensor data, lighting our LED during the read to let the user know we're reading.
  digitalWrite(BOARD_LED, HIGH);
  int result = dht22.read22(DHT22_DATA);
  digitalWrite(BOARD_LED, LOW);
  
  if (result != DHTLIB_OK) {
    if (result == DHTLIB_ERROR_TIMEOUT) {
      Serial.println("Timeout waiting for DHT22");
    } else if (result == DHTLIB_ERROR_CHECKSUM) {
      Serial.println("Garbled result from DHT22");
    } else {
      Serial.println("Unknown failure from DHT22");
    }
    return; // try again in a few seconds.
  }
  
  double humidityPC = dht22.humidity;
  double temperatureC = dht22.temperature;
  
  Serial.print("Relative Humidity (percent): ");
  Serial.println(humidityPC, 1);  // print to .1 percent

  Serial.print("Temperature (degrees Celsius): ");
  Serial.println(temperatureC, 1); // print to .1 degree

}
