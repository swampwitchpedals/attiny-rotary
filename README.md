# ATTiny Rotary

This is an open-source project designed to fill a need that
has been missed in small-scale pedal building: a reliable rotary.

## Why
The traditional rotary is huge, has a ton of solder points, 
has a limited lifespan, and is generally awkward on a PCB. This solution
aims to use the Vimex position sensor, which has the same footprint
as a standard 16mm potentiometer, in conjunction with an ATtiny and
some CD4051 switches to make an easy [1-N]p8t rotary module.


## What
PCBs are all available in the `kicad/` directory. Arduino sketches for each
sized position-sensor (5, 6 and 8) are available in the `arduino/` directory.

*Module* refers to the PCB (`kicad/rotary-multiplexor/`) and to the completed unit with parts soldered.
*Programming Shield* refers to the Atmega shield provided in the `kicad/arduino-mega-progamming-shield/` directory.

## How
1. Solder your Attiny to the Module. 
2. Solder the power regulator and filter caps onto the Module.
3. Plug the Module in the Programming Shield.
4. Program the Atmega with the ArduinoAsISP sketch.
5. Select the Attiny board of your choice, clock speed, and set the programmer to ArduinoAsISP (NOT Arduino As ISP).
6. Select your position-sensor-size sketch and program the Attiny using the "Upload via programmer" option.
7. Attach Module to your effect PCB, with the mux-select lines (pins 7, 6 and 5) tied to each 4051 you wish to control, and the position sensor pins 3 and 2 wired to pins 2 and 3 of the Module.

## License
**DISCLAIMER**
All files and documents are provided as-is. I cannot afford to support 
questions on PCB manufacturing, assembly, or Arduino programming. There
are lots of resources out there to answer these questions.

Copyright 2023 Swamp Witch Pedals

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
