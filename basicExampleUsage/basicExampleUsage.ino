/* MaxMatrix2
 * Version 0.1 OCT 2013
 * Copyright 2013 Nikolai Neff
 * based upon MaxMatrix by Oscar Kin-Chung Au	
 * 
 *
 * This file is part of MaxMatrix2
 * 
 * MaxMatrix2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * MaxMatrix2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with MaxMatrix2.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <MaxMatrix2.h>

int dataIn = 3;
int load = 4;
int clock = 5;
int maxInUse = 2; //number of adressed displays

MaxMatrix2 m(dataIn, load, clock, maxInUse);


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

