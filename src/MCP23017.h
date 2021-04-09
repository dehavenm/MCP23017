#pragma once

#include <cstddef>
#include <cstdint>

class MCP23017
{
public:
    typedef enum {
        CHANGE = 0,
        FALLING = 1,
        RISING = 2,
    } InterruptMode;
    typedef enum {
        LOW = 0,
        HIGH = 1,
    } Level;
    typedef enum {
        INPUT = 0,
        OUTPUT = 1,
    } Direction;

    enum { DEFAULT_ADDRESS = 0x20 };
    unsigned char kI2CBus ;         // I2C bus of the MCP23017
    int kI2CFileDescriptor ;        // File Descriptor to the MCP23017
    int kI2CAddress ;               // Address of MCP23017; defaults to 0x20
    int error ;
    MCP23017(int bus=1, int address=DEFAULT_ADDRESS);
    ~MCP23017() ;
    bool openI2C() ;
    void closeI2C();

    void pinMode(uint8_t p, Direction d);
    void digitalWrite(uint8_t p, uint8_t d);
    void pullUp(uint8_t p, Level d);
    bool digitalRead(uint8_t p);

    void writeGPIOAB(uint16_t);
    uint16_t readGPIOAB();
    uint8_t readGPIO(uint8_t b);

    void setupInterrupts(bool mirroring, bool open, Level polarity);
    void setupInterruptPin(uint8_t p, InterruptMode mode);
    uint8_t getLastInterruptPin();
    uint8_t getLastInterruptPinValue();

private:
    uint8_t bitForPin(uint8_t pin);
    uint8_t regForPin(uint8_t pin, uint8_t portAaddr, uint8_t portBaddr);

    uint8_t readRegister(uint8_t addr);
    uint8_t writeRegister(uint8_t addr, uint8_t value);
    uint8_t readByte();
    uint8_t writeByte(uint8_t value);

  /**
   * Utility private method to update a register associated with a pin (whether port A/B)
   * reads its value, updates the particular bit, and writes its value.
   */
    void updateRegisterBit(uint8_t p, uint8_t pValue, uint8_t portAaddr, uint8_t portBaddr);

    bool bitRead(uint8_t num, uint8_t index);
    void bitWrite(uint8_t &var, uint8_t index, uint8_t bit);
};
