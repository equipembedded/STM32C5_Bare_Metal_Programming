# STM32C5 Bare-Metal GPIO Driver (Lesson 02)

All code written by Equip Embedded in this repository is licensed under the MIT License.

STM32CubeIDE-generated files (startup code, linker scripts, HAL drivers) and any third-party or vendor-supplied components — including but not limited to files from STMicroelectronics and ARM — remain under their respective licenses and copyright notices.

## Overview

This lesson builds a **GPIO driver from scratch** for the STM32C5 — no HAL, no libraries, just registers.

If you've used `HAL_GPIO_Init()` before and never quite understood what it does, this is the part HAL hides from you. Every line in `GPIO_Init()` and `GPIO_WritePin()` writes directly to a hardware register, so you can read the driver top to bottom and see exactly how a pin gets configured and driven.

The driver is written to be understood: comments explain *why* each register write happens, not just *what* it does.

## Features

* Register-level GPIO configuration and output control
* No HAL, no libraries
* `GPIO_Init()` — configures mode, output type, output speed, and pull-up/pull-down
* `GPIO_WritePin()` — drives a pin high or low using `BSRR`
* Clear-then-set bit-masking pattern, explained once and reused throughout

## Files

| File | Purpose |
|------|---------|
| `gpio.h` | Public interface: pin macros, configuration enums, function prototypes |
| `gpio.c` | Implementation: direct register writes for `GPIO_Init()` and `GPIO_WritePin()` |

## Code Overview

`GPIO_Init()` configures a single pin by writing to four registers:

* `MODER` — mode (input / output / alternate / analog), 2 bits per pin
* `OTYPER` — output type (push-pull / open-drain), 1 bit per pin
* `OSPEEDR` — output speed (low / medium / high / very high), 2 bits per pin
* `PUPDR` — pull-up / pull-down (none / up / down), 2 bits per pin

`GPIO_WritePin()` uses `BSRR` to set or reset a pin:

* Lower half (bits 0–15) sets the pin high
* Upper half (bits 16–31) resets the pin low

`BSRR` is used instead of `ODR` because it is atomic — the set/reset happens in a single hardware operation and cannot be interrupted halfway through by an interrupt.

## Board

* STM32C562 (ARM Cortex-M33) on a custom breakout board
* STLINK-V3MINIE debugger

## Prerequisites

* Familiarity with C and basic bitwise operations (`&`, `|`, `~`, `<<`)
* The STM32C5 reference manual handy for register definitions
* No prior bare-metal experience required — the comments walk through each register write

## Disclaimer

This code is provided for educational purposes only.

It demonstrates direct register-level programming of the STM32 microcontroller without using the STM32 HAL. While every effort has been made to keep the code simple and easy to understand, it may contain bugs, omissions, or simplifications.

Always consult the reference manual, datasheet, and relevant hardware documentation for your specific setup before using this code in your own projects.

This project is not intended for production, commercial, or safety-critical applications.

This code is provided "as is" without warranty of any kind. Equip Embedded assumes no responsibility or liability for any hardware damage, data loss, or other issues resulting from the use or misuse of this code.