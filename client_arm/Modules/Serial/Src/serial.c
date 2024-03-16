/**
 *  @title{Module: SERIAL}
 *
 *  This module is responsible to implement the components of a serial communication
 *
 *  @file: serial.c
 */

/*#################################
 # 			INCLUDES		      #
 #################################*/
#include <stdlib.h>
#include <string.h>

#include "serial.h"

/*#################################
 # 		 GLOBAL VARIABLES     	  #
 #################################*/
static bool g_seriaReceptionControl = false;
SERIAL_Config_t g_srialConfig = {0};

/*#################################
 # 		 PUBLIC FUNCTIONS     	  #
 #################################*/
/*
 * Serial Reception Control
 *
 * Description: Enables/Disables the serial reception
 *
 * @param[in] enable - Flag of control
 */
void SERIAL_ReceptionControl(bool enable){
	g_seriaReceptionControl = enable;
}

/*
 * @title{Serial Init Function}
 *
 * Description: Get the configuration of the serial module
 *
 * @param[in] config - Configuration of the module
 */
int SERIAL_Init(SERIAL_Config_t *config){
	int ret = HAL_OK;

	// Clears configuration variable
	memset(&g_srialConfig, 0, sizeof(g_srialConfig));
	// Check if there is configuration
	if(config != NULL){
		// Copies the configuration
		memcpy(&g_srialConfig, config, sizeof(g_srialConfig));
	} else {
		ret = HAL_ERROR;
	}

	return ret;
}

/*
 * @title{Serial Loop Function}
 *
 * Description: Runs the main functionality
 */
void SERIAL_Loop(void){

}
