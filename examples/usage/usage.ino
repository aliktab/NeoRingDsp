/*
  Copyright (C) 2014 Alik <aliktab@gmail.com> All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "NeoRingDsp.h"

#define PIXEL_TYPE    WS2812B // for possible values see NeoPixel library: https://github.com/technobly/Particle-NeoPixel
#define PIXELS_COUNT  24      // number of pixels in the ring
#define CONTROL_PIN   D6      // perticle pin, connected to the first pixel

// Initialize objects from the lib
NeoRingDsp neoRingDsp(PIXELS_COUNT, CONTROL_PIN, PIXEL_TYPE);

void setup() {
  neoRingDsp.begin();
  neoRingDsp.set_work_mode(NeoRingDsp::nrd_clock); // use nrd_clock to show current time on Ring similar to regular clock
}

void loop() {
  neoRingDsp.process(); // get current values from sensors and show them on ring
}