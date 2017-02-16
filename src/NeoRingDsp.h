#pragma once

/*
  Copyright (c) 2017 Purple Wolf Ltd. All rights reserved.

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

// this will load the definition for common Particle variable types
#include <Particle.h>

// neopixels control library
#include <neopixel.h> // https://github.com/technobly/Particle-NeoPixel

#define MAIN_RING_CLOCK_PRECISE 255

class NeoRingDsp
{
public:

  enum NeoRingDspMode
  {
    nrd_off   = 1,
    nrd_clock = 2
  };

  // Constructor: number of LEDs, pin number, LED type
  NeoRingDsp(uint16_t _px_cnt, uint8_t _pin, uint8_t _type);

  void begin(); 

  void set_work_mode(const NeoRingDspMode _val);

  void set_clock_shift(const uint8_t _val);

  void set_brightness(const uint8_t _val);

  void process();

private:

  void update_time();

  void show_clock();

  NeoRingDspMode    m_work_mode;

  uint8_t           m_pixel_count;

  uint8_t           m_clock_shift;

  uint8_t           m_mem_seconds;
  uint32_t          m_mem_millis;

  uint32_t          m_cur_hours;
  uint32_t          m_cur_minutes;
  uint32_t          m_cur_seconds;
  uint32_t          m_cur_millis;

  uint8_t           m_brightness;

  Adafruit_NeoPixel m_neo_pixel;
};
