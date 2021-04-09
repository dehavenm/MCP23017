# MCP23017

A C++ driver for the MCP23017 (I2C GPIO expander chip)

https://www.microchip.com/wwwproducts/en/MCP23017

Originally developed for Jetson Xavier using the smbus interface, it also works on systems with i2c-dev (via #define in src/MCP23017.cpp).

The code is mainly a port of the Adafruit MCP23017 Arduino library, with the I2C command code from the Jetsonhacks PCA9685 PWM driver:

https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library

https://github.com/jetsonhacks/JHPWMDriver
