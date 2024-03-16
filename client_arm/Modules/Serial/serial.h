/**
 *  @title{Module: SERIAL}
 *
 *  This module is responsible to implement the components of a serial communication
 *
 *  @file: serial.h
 */
#ifndef __SERIAL_H__
#define __SERIAL_H__

/*#################################
 # 			INCLUDES		      #
 #################################*/
#include <stdbool.h>
#include "usart.h"
#include "gpio_structure.h"

/*#################################
 # 		 TYPEDEFS STUCTURES       #
 #################################*/

/* Serial Configuration Structure Type */
typedef struct {
	UART_HandleTypeDef *usart;
} SERIAL_Config_t;

/*#################################
 # 		 PUBLIC FUNCTIONS     	  #
 #################################*/
/*
 * @title{Serial Reception Control}
 *
 * Description: Enables/Disables the serial reception
 *
 * @param[in] enable - Flag of control
 */
void SERIAL_ReceptionControl(bool enable);

/*
 * @title{Serial Init Function}
 *
 * Description: Get the configuration of the serial module
 *
 * @param[in] config - Configuration of the module
 */
int SERIAL_Init(SERIAL_Config_t *config);

/*
 * Serial Loop Function
 *
 * Description: Runs the main functionality
 */
void SERIAL_Loop(void);

#endif /*__SERIAL_H__*/
