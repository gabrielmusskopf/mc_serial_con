/**
 *  @title{Module: APPLICATION}
 *
 *  This module is responsible to control the when the client has to enable the
 *  serial reception and turns on the LED.
 *
 *  @file: application.h
 */
#ifndef __SERVERCONTROLLER_H__
#define __SERVERCONTROLLER_H__

/*#################################
 # 			INCLUDES		      #
 #################################*/
#include "usart.h"
#include "gpio_structure.h"
#include "stdbool.h"

/*#################################
 # 		 TYPEDEFS STUCTURES       #
 #################################*/

typedef struct {
	GPIO_Structure_t inButton;
	GPIO_Structure_t outChipSelect;
	bool buttonPressed;
}Client_Infos_t;

/* Application Configuration Structure Type */
typedef struct {
	Client_Infos_t *clients;
	UART_HandleTypeDef *usart;
	int numClients;
}SERVERCONTROLLER_Config_t;

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
int SERVERCONTROLLER_Init(SERVERCONTROLLER_Config_t *config);

/*
 * @title{Application Loop Function}
 *
 * Description: Runs the main functionality
 */
void SERVERCONTROLLER_Loop(void);

#endif /*__SERVERCONTROLLER_H__*/
