/* MaxMatrix2
 * Version 0.1 OCT 2013
 * Copyright 2013 Nikolai Neff
 * based upon MaxMatrix by Oscar Kin-Chung Au	
 * 
 * Tested with Arduino 1.0.5 and 1.5.4 on Arduino Uno Rev3
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

byte dataIn = 3;
byte load = 4;
byte clock = 5;
byte maxInUse = 2; //number of adressed displays

MaxMatrix2 m(dataIn, load, clock, maxInUse);


void setup()
{
	delay(100);
	Serial.begin(9600);
	// Serial.println("Init");
	m.init(0x07, 0x00, false); //scanlimit, decodeMode, displayTest
	// Serial.println("Intensity1");
	m.setIntensity(0,0);
	// Serial.println("Intensity2");
	m.setIntensity(1,0);
}

void loop()
{
	byte CH_A[] = {B01111110, B00010001, B00010001, B01111110, 0, 0, 0, 0}; // CH_A stores the sprite 'A'
	byte CH_B[] = {B01111111, B01001001, B01001001, B00110110, 0, 0, 0, 0}; // CH_B stores the sprite 'B'
	m.sendArray(0, CH_A);
	m.sendArray(1, CH_B);
	
	delay(1000);
	
	for (byte i=0; i<8; i++) //Line flashing across the Matrix on Display 0
	{
		m.sendCommand(0,i+1,0xFF);
		if(i>0)
		{
			m.sendCommand(0,i,0x00);
		}
		delay (30);
	}		
		
	// delay(1000);
		
}