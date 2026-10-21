# STM32C5 Bare-Metal Blinky No Driver (Lesson 01)

All code written by Equip Embedded in this repository is licensed under the MIT License.

STM32CubeIDE-generated files (startup code, linker scripts, HAL drivers) and any third-party or vendor-supplied components — including but not limited to files from STMicroelectronics and ARM — remain under their respective licenses and copyright notices.

## Overview

This repository contains **bare-metal STM32C5 code** for blinking an LED on a custom STM32C562 breakout board.

All programming is done **directly via registers**, without HAL or external libraries.

## Features

* Register-level GPIO control
* No HAL, no libraries
* Example using PA2 (adjust to your board's LED pin)

## Code Overview

* Enable GPIOA clock via `RCC_AHB2ENR`
* Configure PA2 as output via `GPIOA_MODER`
* Set/reset PA2 via `GPIOA_BSRR`

## Board

* STM32C562 (ARM Cortex-M33) on a custom breakout board
* STLINK-V3MINIE debugger

## Disclaimer

This code is provided for educational purposes only.

It demonstrates direct register-level programming of the STM32 microcontroller without using the STM32 HAL. While every effort has been made to keep the code simple and easy to understand, it may contain bugs, omissions, or simplifications.

Always consult the reference manual, datasheet, and relevant hardware documentation for your specific setup before using this code in your own projects.

This project is not intended for production, commercial, or safety-critical applications.

This code is provided "as is" without warranty of any kind. Equip Embedded assumes no responsibility or liability for any hardware damage, data loss, or other issues resulting from the use or misuse of this code.