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
 * @title{Serial Get Data}
 *
 * Description: Is responsible to get the new data received
 *
 * @param[out] pData - Received data
 */
int SERIAL_GetNewReceivedValidData(void);

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
 * @title{Serial RX Callback}
 *
 * Description: Is called in loop to receive a serial data
 *
 */
void SERIAL_Loop(void);

#endif /*__SERIAL_H__*/
