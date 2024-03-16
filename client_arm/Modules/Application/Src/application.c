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

#include "application.h"

/*#################################
 # 		 GLOBAL VARIABLES     	  #
 #################################*/
APPLICATION_Config_t g_applicationConfig = {0};

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

	// Clears configuration variable
	memset(&g_applicationConfig, 0, sizeof(g_applicationConfig));
	// Check if there is configuration
	if(config != NULL){
		// Copies the configuration
		memcpy(&g_applicationConfig, config, sizeof(g_applicationConfig));
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

}
