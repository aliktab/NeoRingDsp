#pragma once

/*
  Neo Ring Display library, controls any neopixel ring and shows time, bars and other information on them

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
#include <neopixel.h> // https://github.com/technobly/Particle-NeoPixel/blob/master/README.md

#define MAIN_RING_PIXEL_TYPE    WS2812B
#define MAIN_RING_PIXELS_COUNT  24
#define MAIN_RING_CONTROL_PIN   D6

#define MAIN_RING_CLOCK_PRECISE 255

class NeoRingDsp
{
public:

  enum NeoRingDspMode
  {
    mrm_off   = 1,
    mrm_clock = 2
  };

  NeoRingDsp();

  void begin();

  void set_work_mode(const NeoRingDspMode _val);

  void set_clock_shift(const uint8_t _val);

  void set_brightness(const uint8_t _val);

  void process();

private:

  void update_time();

  void show_clock();

  NeoRingDspMode      m_work_mode;

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
