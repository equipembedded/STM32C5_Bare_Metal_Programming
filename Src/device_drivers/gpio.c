/**
  ******************************************************************************
  * @file    gpio.c
  * @author  Equip Embedded
  * @brief   Baremetal GPIO driver: pin configuration and output control.
  * @note    This copyright applies only to this file.
  *
  *          This file may contain:
  *           - GPIO pin initialization (GPIO_Init)
  *           - GPIO pin write / output control (GPIO_WritePin)
  *           - Direct register-level access (MODER, OTYPER, OSPEEDR, PUPDR, BSRR)
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

#include "device_drivers/gpio.h"

void GPIO_Init(GPIO_TypeDef * port,
		uint8_t pin,
		GPIO_Mode_et mode,
		GPIO_OutputType_et outputType,
		GPIO_OutputSpeed_et outputSpeed,
		GPIO_Pull_et pullUpDown){

	// MODER: 2 bits per pin — clear this pin's 2 bits first
	port->MODER &= ~(0x3U << (pin * 2U));
	// MODER: write the new mode into those 2 bits
	port->MODER |= ((uint32_t)(mode << (pin * 2U)));

	// OTYPER: 1 bit per pin — clear this pin's bit
	port->OTYPER &= ~(0x1 << pin);
	// OTYPER: write push-pull or open-drain
	port->OTYPER |= ((uint32_t)(outputType << pin));

	// OSPEEDR: 2 bits per pin — clear this pin's 2 bits
	port->OSPEEDR &= ~(0x3U << (pin * 2U));
	// OSPEEDR: write the new output speed
	port->OSPEEDR |= ((uint32_t)(outputSpeed << (pin * 2U)));

	// PUPDR: 2 bits per pin — clear this pin's 2 bits
	port->PUPDR &= ~(0x3U << (pin * 2U));
	// PUPDR: write pull-up / pull-down setting
	port->PUPDR |= ((uint32_t)(pullUpDown << (pin * 2U)));

}

void GPIO_WritePin(GPIO_TypeDef * port, uint8_t pin, GPIO_Level_et value) {
	if (value == 1U) {
		// Set pin HIGH: write 1 to lower half of BSRR (bits 0-15)
		port->BSRR = (1UL << pin);
	} else {
		// Set pin LOW: write 1 to upper half of BSRR (bits 16-31)
		port->BSRR = (1UL << (pin + 16));
	}
}

