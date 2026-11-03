/**
  ******************************************************************************
  * @file    gpio.h
  * @author  Equip Embedded
  * @brief   Baremetal GPIO driver public interface: pin defines, config types, and API.
  * @note    This copyright applies only to this file.
  *
  *          This file may contain:
  *           - GPIO pin number macros (GPIO_PIN_0 … GPIO_PIN_15)
  *           - Configuration types: mode, output type, output speed, pull, level
  *           - GPIO driver API: GPIO_Init, GPIO_WritePin
  *
  ******************************************************************************
  * MIT License
  *
  * Copyright (c) 2026 Equip Embedded
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is
  * furnished to do so, subject to the following conditions:
  *
  * The above copyright notice and this permission notice shall be included in
  * all copies or substantial portions of the Software.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  * THE SOFTWARE.
  ******************************************************************************
  */

#ifndef DEVICE_DRIVERS_GPIO_H_
#define DEVICE_DRIVERS_GPIO_H_

#include <stdint.h>
#include "device_headers/stm32c562xx.h"

#define GPIO_PIN_0   (0U)
#define GPIO_PIN_1   (1U)
#define GPIO_PIN_2   (2U)
#define GPIO_PIN_3   (3U)
#define GPIO_PIN_4   (4U)
#define GPIO_PIN_5   (5U)
#define GPIO_PIN_6   (6U)
#define GPIO_PIN_7   (7U)
#define GPIO_PIN_8   (8U)
#define GPIO_PIN_9   (9U)
#define GPIO_PIN_10  (10U)
#define GPIO_PIN_11  (11U)
#define GPIO_PIN_12  (12U)
#define GPIO_PIN_13  (13U)
#define GPIO_PIN_14  (14U)
#define GPIO_PIN_15  (15U)

typedef enum {
	GPIO_MODE_INPUT = 0U,
	GPIO_MODE_OUTPUT,
	GPIO_MODE_ALTERNATE,
	GPIO_MODE_ANALOG
} GPIO_Mode_et;

typedef enum
{
    GPIO_OTYPE_PUSHPULL  = 0U,
    GPIO_OTYPE_OPENDRAIN
} GPIO_OutputType_et;

typedef enum
{
    GPIO_OUTPUT_SPEED_LOW       = 0U,
    GPIO_OUTPUT_SPEED_MEDIUM,
    GPIO_OUTPUT_SPEED_HIGH,
    GPIO_OUTPUT_SPEED_VERY_HIGH
} GPIO_OutputSpeed_et;

typedef enum
{
    GPIO_PULL_NONE = 0U,
    GPIO_PULL_UP, // HIGH
	GPIO_PULL_DOWN // LOW
} GPIO_Pull_et;

typedef enum
{
    GPIO_LOW  = 0U,
    GPIO_HIGH = 1U
} GPIO_Level_et;

void GPIO_Init(GPIO_TypeDef * port,
		uint8_t pin,
		GPIO_Mode_et mode,
		GPIO_OutputType_et outputType,
		GPIO_OutputSpeed_et outputSpeed,
		GPIO_Pull_et pullUpDown);

void GPIO_WritePin(GPIO_TypeDef * port, uint8_t pin, GPIO_Level_et value);

#endif /* DEVICE_DRIVERS_GPIO_H_ */
