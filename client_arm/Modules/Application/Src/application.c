/**
 *  @title{Module: APPLICATION}
 *
 *  This module is responsible to control the when the client has to enable the
 *  serial reception and turns on the LED.
 *
 *  @file: application.c
 */
/*#################################
 # 			INCLUDES		      #
 #################################*/
#include <stdbool.h>
#include <string.h>
#include "serial.h"

#include "application.h"


/*#################################
 # 		 GLOBAL VARIABLES     	  #
 #################################*/
APPLICATION_Config_t g_applicationConfig = {0};

/*#################################
 # 		 PRIVATE FUNCTIONS     	  #
 #################################*/

/*
 * @title{Check Chip Select}
 *
 * Description: Check if the chip select is enable e set the reception control to be able to receive
 */
static int CheckChipSelect(void){
	int ret = 0;

	/* Check if the chip select is enable */
	if(HAL_GPIO_ReadPin(g_applicationConfig.inCS.Port, g_applicationConfig.inCS.Pin)){
		SERIAL_ReceptionControl(true);
		ret = 1;
	}

	return ret;
}

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
int APPLICATION_Init(APPLICATION_Config_t *config){
	int ret = HAL_OK;

	/* Clears configuration variable */
	memset(&g_applicationConfig, 0, sizeof(g_applicationConfig));
	/* Check if there is configuration */
	if(config != NULL){
		// Copies the configuration
		memcpy(&g_applicationConfig, config, sizeof(g_applicationConfig));
		/* Disable the reception */
		SERIAL_ReceptionControl(false);
	} else {
		ret = HAL_ERROR;
	}

	return ret;
}

/*
 * @title{Application Loop Function}
 *
 * Description: Runs the main functionality
 */
void APPLICATION_Loop(void){
	/* Check if the chip select is enable */
	if(CheckChipSelect()){
		/* Enables the reception */
		SERIAL_ReceptionControl(true);
		/* Check if it was received a new valid data */
		if(SERIAL_GetNewReceivedValidData() == HAL_OK){
			/* Toggle the LED */
			HAL_GPIO_TogglePin(g_applicationConfig.outLED.Port, g_applicationConfig.outLED.Pin);
		}
	}else{
		/* Disable the reception */
		SERIAL_ReceptionControl(false);
	}
}
