#include <MaxMatrix.h>

int dataIn = 3;
int load = 4;
int clock = 5;
int maxInUse = 2; //number of adressed displays

MaxMatrix m(dataIn, load, clock, maxInUse);


void setup()
{
	m.init(); //use default values for now
}

void loop()
{
	m.sendCommand(1,1,0b01010101); //arguments: display, address, value; produces a nice on-off pattern on display 1
	m.sendCommand(1,3,0b01010101);
	m.sendCommand(1,5,0b01010101);
	m.sendCommand(1,7,0b01010101);
	m.sendCommand(1,2,0b10101010);
	m.sendCommand(1,4,0b10101010);
	m.sendCommand(1,6,0b10101010);
	m.sendCommand(1,8,0b10101010);
	
	m.sendCommand(2,1,0xFF); //display 2 completely lit
	m.sendCommand(2,2,0xFF);
	m.sendCommand(2,3,0xFF);
	m.sendCommand(2,4,0xFF);
	m.sendCommand(2,5,0xFF);
	m.sendCommand(2,6,0xFF);
	m.sendCommand(2,7,0xFF);
	m.sendCommand(2,8,0xFF);
	
	delay(1000);
	
	
	m.sendCommand(1,1,0b10101010); //alternate pattern on display 1
	m.sendCommand(1,3,0b10101010);
	m.sendCommand(1,5,0b10101010);
	m.sendCommand(1,7,0b10101010);
	m.sendCommand(1,2,0b01010101);
	m.sendCommand(1,4,0b01010101);
	m.sendCommand(1,6,0b01010101);
	m.sendCommand(1,8,0b01010101);
	
	m.sendCommand(2,1,0x00); // display 2 completely off
	m.sendCommand(2,2,0x00);
	m.sendCommand(2,3,0x00);
	m.sendCommand(2,4,0x00);
	m.sendCommand(2,5,0x00);
	m.sendCommand(2,6,0x00);
	m.sendCommand(2,7,0x00);
	m.sendCommand(2,8,0x00);
		
	delay(1000);
}

