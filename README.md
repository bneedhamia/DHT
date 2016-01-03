# DHT
# DHT
Modified version of Rob Tillaart's DHT22 Temperature and Humidity sensor Arduino library, with a new example Arduino Sketch.
Public Domain.

To use:
  1. Buy a DHT22 (RHT03) Humidity and Temperature sensor, for example [from Sparkfun](https://www.sparkfun.com/products/10167)
  1. Connect the DHT22 to your Arduino, using M/F jumper wires, for example [from Sparkfun](https://www.sparkfun.com/products/9139).  See the pinout in DHT22Test.ino
  1. Clone this project into your Arduino/libraries folder
  1. Start your Arduino IDE
  1. File / Examples / DHT / DHT22Test
  1. Connect your Arduino to your PC, set the processor type and port, and run the Sketch
  1. Open the Serial Monitor.  If all goes well, you should see the temperature and humidity, and the Arduino LED should flash about once every 2.5 seconds.

Note: this library is slightly different from Rob Tillaart's original:
This uses digitalRead() instead of portInputRegister() because the Arduino 101 doesn't seem to support portInputRegister().
This change can be disabled by editing dht.cpp and changing HAS_PIR from 0 to 1, then restarting your Arduino IDE.

Tested on Arduino Uno and Arduino 101.
