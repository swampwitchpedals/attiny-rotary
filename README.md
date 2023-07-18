# ATTiny Rotary

This is an open-source project designed to fill a need that
has been missed in small-scale pedal building: a reliable rotary.

**DISCLAIMER**
All files and documents are provided as-is. I cannot afford to support 
questions on PCB manufacturing, assembly, or Arduino programming. There
are lots of resources out there to answer these questions.

## Why
The traditional 1p10t rotary is huge, has a ton of solder points, 
has a limited lifespan, and is generally awkward on a PCB. This solution
aims to use the Vimex position sensor, which has the same footprint
as a standard 16mm potentiometer, in conjunction with an ATtiny and
some CD4051 switches to make an easy [1-N]p8t rotary module.


## What
PCBs are all available in the `kiad/` directory. Arduino sketches for each
sized position-sensor (5, 6 and 8) are available in the `arduino/` directory.

*Module* refers to the PCB (`kicad/rotary-multiplexor/`) and to the completed unit with parts soldered.
*Programming Shield* refers to the Atmega shield provided in the `kicad/arduino-mega-progamming-shield/` directory.

## How
1. Solder your Attiny to the Module. 
2. Plug the Module in the Programming Shield.
3. Select your position-sensor-size sketch and program the Attiny.
4. Solder the power regulator and filter caps onto the Module.
5. Attach Module to your effect PCB, with the mux-select lines tied to each 4051 you wish to control, and the position sensor pins 3 and 2 wired to pins 1 and 2 of the Module.
