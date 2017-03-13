# NeoRingDsp

*Particle library implements circular display based on any neopixel ring, shows time, bars and other information*

Particle library allows to show different information on the any Neo Pixel Ring.
Based on the neopixel library: https://github.com/technobly/Particle-NeoPixel

Allow to display:
  1. 24 hours ring clock.
  2. 12 hours ring clock (is planned).
  3. Circular bars to show levels (is planned).

## Usage

Connect any NeoPixel Ring hardware, add the NeoRingDsp library to your project and follow this simple example:

```
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
```

See the [examples](examples) folder for more details.

## Contributing

Here's how you can make changes to this library and eventually contribute those changes back.

To get started, [clone the library from GitHub to your local machine](https://help.github.com/articles/cloning-a-repository/).

Change the name of the library in `library.properties` to something different. You can add your name at then end.

Modify the sources in <src> and <examples> with the new behavior.

To compile an example, use `particle compile examples/usage` command in [Particle CLI](https://docs.particle.io/guide/tools-and-features/cli#update-your-device-remotely) or use our [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#compiling-code).

After your changes are done you can upload them with `particle library upload` or `Upload` command in the IDE. This will create a private (only visible by you) library that you can use in other projects. Do `particle library add NeoRingDsp_myname` to add the library to a project on your machine or add the NeoRingDsp_myname library to a project on the Web IDE or Desktop IDE.

At this point, you can create a [GitHub pull request](https://help.github.com/articles/about-pull-requests/) with your changes to the original library.

If you wish to make your library public, use `particle library publish` or `Publish` command.

## LICENSE
Copyright (C) 2014 Alik <aliktab@gmail.com> All rights reserved.

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
