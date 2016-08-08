/*
ashleysColorTest - Test code for my 2016 Burning Man outfit.
Copyright (C) 2016 Ashley Riley and Joel Luellwitz

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel stud = Adafruit_NeoPixel(22, 3, NEO_GRB + NEO_KHZ800); 
Adafruit_NeoPixel vent= Adafruit_NeoPixel(22, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel shoulder = Adafruit_NeoPixel(22, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel grid = Adafruit_NeoPixel(22, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Serial.println("Give me a minute.");

  stud.begin();
  vent.begin();  
  shoulder.begin();
  grid.begin();
}

void loop() {
  
  unsigned long currentFrameTime = millis();
  unsigned long loopCount = 0;

  // the following should manipulate neopixel 0,1,2,3 for the strip of 22
  while (currentFrameTime < 60000) {

    uint8_t color = random(0, 255);
    
    for (uint16_t index = 0; index < 22; index++) {
      stud.setPixelColor(index, color, 0, 0);
      vent.setPixelColor(index, 0, color, 0);
      shoulder.setPixelColor(index, 0, 0, color);
      grid.setPixelColor(index, color, color, color);
    }
    
    stud.show();
    vent.show();
    shoulder.show();
    grid.show();
    
    loopCount++;

    currentFrameTime = millis();
  }
  
  Serial.print("loopCount: ");
  Serial.println(loopCount);
  Serial.println("Done.");
  
  while (true) {};
}
