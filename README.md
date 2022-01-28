# Furnace Tracker

![screenshot](papers/screenshot1.png)

this is a work-in-progress chiptune tracker compatible with DefleMask modules (.dmf).

[downloads](#downloads) | [discussion](#discussion) | [help](#help) | [developer info](#developer-info)

## features

- supports the following systems:
  - Sega Genesis
  - Sega Master System
  - Game Boy
  - PC Engine
  - NES
  - Commodore 64
  - Yamaha YM2151 (plus PCM)
  - Neo Geo
  - AY-3-8910 (ZX Spectrum, Atari ST, etc.)
  - Microchip AY8930
  - Philips SAA1099
  - Amiga
  - TIA (Atari 2600/7800)
- multiple sound chips in a single song!
- clean-room design (zero reverse-engineered code and zero decompilation; using official DMF specs, guesswork and ABX tests only)
- bug/quirk implementation for increased playback accuracy
- VGM and audio file export
- accurate emulation cores whether possible (Nuked, MAME, SameBoy, Mednafen PCE, puNES, reSID, Stella and ymfm)
- additional features on top:
  - FM macros!
  - arbitrary pitch samples
  - sample loop points
  - SSG envelopes in Neo Geo
  - full duty/cutoff range in C64
  - ability to change tempo mid-song with `Cxxx` effect (`xxx` between `000` and `3ff`)
- open-source under GPLv2.

## downloads

check out the [Releases](https://github.com/tildearrow/furnace/releases) page. available for Windows, macOS and Linux (AppImage).

## discussion

see the [Discussions](https://github.com/tildearrow/furnace/discussions) section, or (preferably) the [official Discord server](https://discord.gg/EfrwT2wq7z).

## help

check out the [documentation](papers/doc/README.md). it's mostly incomplete, but has details on effects.

# developer info

## dependencies

- CMake
- SDL2
- zlib
- JACK (optional)

SDL2 and zlib are included as submodules.

## compilation

your typical CMake project. clone (including submodules) and:

### Windows using MSVC

as of now tildearrow uses MinGW for Windows builds, but thanks to OPNA2608 this works again!

from the developer tools command prompt:

```
mkdir build
cd build
cmake ..
msbuild ALL_BUILD.vcxproj
```

### macOS and Linux

```
mkdir build
cd build
cmake ..
make
```

## usage

```
./furnace
```

this opens the program.

```
./furnace -console <file>
```

this will play a compatible file.

```
./furnace -console -view commands <file>
```

this will play a compatible file and enable the commands view.

# notes

> how do I use Neo Geo SSG envelopes?

the following effects are provided:

- `22xy`: set envelope mode.
  - `x` sets the envelope shape, which may be one of the following:
    - `0: \___` decay
    - `4: /___` attack once
    - `8: \\\\` saw
    - `9: \___` decay
    - `A: \/\/` inverse obelisco
    - `B: \¯¯¯` decay once
    - `C: ////` inverse saw
    - `D: /¯¯¯` attack
    - `E: /\/\` obelisco
    - `F: /___` attack once
  - if `y` is 1 then the envelope will affect this channel.
- `23xx`: set envelope period low byte.
- `24xx`: set envelope period high byte.
- `25xx`: slide envelope period up.
- `26xx`: slide envelope period down.

a lower envelope period will make the envelope run faster.

> how do I use C64 absolute filter/duty?

on Instrument Editor in the C64 tab there are two options to toggle these.
also provided are two effects:

- `3xxx`: set fine duty.
- `4xxx`: set fine cutoff. `xxx` range is 000-7ff.

> my song sounds very odd at a certain point

file a bug report. use the Issues page.

it's probably another playback inaccuracy.

> my song sounds correct, but it doesn't in DefleMask

file a bug report **here**. it still is a playback inaccuracy.

> my C64 song sounds terrible after saving as .dmf!

that's a limitation of the DefleMask format. save in Furnace song format instead (.fur).

> how do I solo channels?

right click on the channel name.
