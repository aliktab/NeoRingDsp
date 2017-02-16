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

#include "NeoRingDsp.h"

NeoRingDsp::NeoRingDsp(uint16_t _px_cnt, uint8_t _pin, uint8_t _type) :
  m_neo_pixel(_px_cnt, _pin, _type)
{
  m_work_mode   = nrd_off;

  m_pixel_count = _px_cnt;

  m_clock_shift = 0;

  m_mem_seconds = 0;
  m_mem_millis  = 0;

  m_cur_hours   = 0;
  m_cur_minutes = 0;
  m_cur_seconds = 0;
  m_cur_millis  = 0;

  m_brightness  = 30;
}

void NeoRingDsp::begin()
{
  m_neo_pixel.begin();
}

void NeoRingDsp::set_work_mode(const NeoRingDspMode _val)
{
  m_work_mode = _val;
}

void NeoRingDsp::set_clock_shift(const uint8_t _val)
{
  m_clock_shift = _val;
}

void NeoRingDsp::set_brightness(uint8_t _val)
{
  m_brightness = _val;
}

void NeoRingDsp::process()
{
  update_time();

  m_neo_pixel.setBrightness(m_brightness);

  switch (m_work_mode)
  {
    case nrd_clock:
      show_clock();
      break;

    case nrd_off:
    default:
      m_neo_pixel.clear();
      m_neo_pixel.show();
      break;
  }
}

void NeoRingDsp::update_time()
{
  m_cur_hours   = Time.hour();
  m_cur_minutes = Time.minute();
  m_cur_seconds = Time.second();

  if (m_cur_seconds != m_mem_seconds)
  {
    m_mem_seconds = m_cur_seconds;
    m_mem_millis  = millis();
  }

  m_cur_millis  = millis() - m_mem_millis;
}

void NeoRingDsp::show_clock()
{
  uint32_t val[] =
  {
    (m_cur_seconds * 1000 + m_cur_millis)
                   * m_pixel_count * MAIN_RING_CLOCK_PRECISE / 60,
     m_cur_minutes * m_pixel_count * MAIN_RING_CLOCK_PRECISE / 60,
     m_cur_hours   * m_pixel_count * MAIN_RING_CLOCK_PRECISE / 24
  };
  val[0]  = val[0] / 1000;
  val[1] += val[0] / 60;
  val[2] += val[1] / 24;

  uint8_t pix[3][m_pixel_count];
  memset(pix, 0, sizeof(pix));

  for (int i = 0; i < 3; i++)
  {
    uint16_t cur = val[i] / MAIN_RING_CLOCK_PRECISE;
    uint16_t lvl = val[i] - cur * MAIN_RING_CLOCK_PRECISE;
    cur = (cur + m_clock_shift) % m_pixel_count;
    uint16_t nxt = (cur + 1) % m_pixel_count;

    pix[i][cur] += MAIN_RING_CLOCK_PRECISE - lvl;
    pix[i][nxt] += lvl;
  }

  for (int i = 0; i < m_pixel_count; i++)
    m_neo_pixel.setColor(i, pix[0][i], pix[1][i], pix[2][i]);

  m_neo_pixel.show();
}
