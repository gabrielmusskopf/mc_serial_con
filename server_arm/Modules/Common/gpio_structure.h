/**
 *  @title{Module: GPIO_STRUCUTRE}
 *
 *  This module is responsible to define the GPIOs structure
 *
 *  @file: gpio_structure.h
 */

#ifndef __GPIO_STRUCTURE_H__
#define __GPIO_STRUCTURE_H__

/* Includes */
#include "gpio.h"

/* GPIO Structure Type */
typedef struct {
	GPIO_TypeDef *Port;
	uint16_t Pin;
} GPIO_Structure_t;

#endif /*__GPIO_STRUCTURE_H__*/
