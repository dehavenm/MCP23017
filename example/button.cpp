#include "MCP23017.h"
#include <time.h>
#include <iostream>

using namespace std;

//constants set to emulate Arduino pin parameters
constexpr MCP23017::Level HIGH = MCP23017::HIGH;
constexpr MCP23017::Level LOW = MCP23017::LOW;

constexpr MCP23017::Direction INPUT = MCP23017::INPUT;
constexpr MCP23017::Direction OUTPUT = MCP23017::OUTPUT;

constexpr MCP23017::InterruptMode CHANGE = MCP23017::CHANGE;
constexpr MCP23017::InterruptMode FALLING = MCP23017::FALLING;
constexpr MCP23017::InterruptMode RISING = MCP23017::RISING;

// Basic pin reading and pullup test for the MCP23017 I/O expander
// public domain!

// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection)
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low)

// Input #0 is on pin 21 so connect a button or switch from there to ground


int main() {

  MCP23017 mcp(8, MCP23017::DEFAULT_ADDRESS);      // use default address 0x20

  if(!mcp.openI2C())
  {
    cerr << "Error opening device\n";
    return 1;
  }


  mcp.pinMode(0, INPUT);

  mcp.pullUp(0, HIGH);  // turn on a 100K pullup internally

  mcp.pinMode(1, OUTPUT);  // use the p13 LED as debugging

  while(true){
    // The LED will 'echo' the button
    mcp.digitalWrite(1, mcp.digitalRead(0));

  }


  return 0;
}
