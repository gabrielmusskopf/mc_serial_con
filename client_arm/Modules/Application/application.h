/**
 *  @title{Module: APPLICATION}
 *
 *  This module is responsible to control the when the client has to enable the
 *  serial reception and turns on the LED.
 *
 *  @file: application.h
 */
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

/*#################################
 # 			INCLUDES		      #
 #################################*/
#include "usart.h"
#include "gpio_structure.h"

/*#################################
 # 		 TYPEDEFS STUCTURES       #
 #################################*/

/* Application Configuration Structure Type */
typedef struct {
	GPIO_Structure_t outLED;
	GPIO_Structure_t inCS;
}APPLICATION_Config_t;

/*#################################
 # 		 PUBLIC FUNCTIONS     	  #
 #################################*/
/*
 * @title{Application Init Function}
 *
 * Description: Get the configuration of the serial module
 *
 * @param[in] config - Configuration of the module
 */
int APPLICATION_Init(APPLICATION_Config_t *config);

/*
 * @title{Application Loop Function}
 *
 * Description: Runs the main functionality
 */
void APPLICATION_Loop(void);

#endif /*__SERIAL_H__*/
