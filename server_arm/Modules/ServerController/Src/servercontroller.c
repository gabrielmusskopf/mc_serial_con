/**
 *  @title{Module: SERVERCONTROLLER}
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

#include "servercontroller.h"


/*#################################
 # 		 GLOBAL VARIABLES     	  #
 #################################*/
SERVERCONTROLLER_Config_t g_serverControllerConfig = {0};
const uint8_t txData[] = "T";

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
int SERVERCONTROLLER_Init(SERVERCONTROLLER_Config_t *config){
	int ret = HAL_OK;

	/* Clears configuration variable */
	memset(&g_serverControllerConfig, 0, sizeof(g_serverControllerConfig));
	/* Check if there is configuration */
	if(config != NULL){
		// Copies the configuration
		memcpy(&g_serverControllerConfig, config, sizeof(g_serverControllerConfig));
		g_serverControllerConfig.clients[0].buttonPressed = false;
		g_serverControllerConfig.clients[1].buttonPressed = false;

	} else {
		ret = HAL_ERROR;
	}

	return ret;
}

/*
 * @title{Server Controller Loop Function}
 *
 * Description: Runs the main functionality
 */
void SERVERCONTROLLER_Loop(void){
	int i;
	int currentState;

	// It runs the main logical for each client
	for(i = 0; i<g_serverControllerConfig.numClients; i++){
		// Read the button of the current client
		currentState = HAL_GPIO_ReadPin(g_serverControllerConfig.clients[i].inButton.Port, g_serverControllerConfig.clients[i].inButton.Pin);
		if(currentState && !g_serverControllerConfig.clients[i].buttonPressed){
			g_serverControllerConfig.clients[i].buttonPressed = true;

			// Enables the chip select of this client
			HAL_GPIO_WritePin(g_serverControllerConfig.clients[i].outChipSelect.Port, g_serverControllerConfig.clients[i].outChipSelect.Pin, GPIO_PIN_SET);
			// Transmit the signal on the line
			HAL_UART_Transmit(&huart1, &txData[0], sizeof(txData), 100);
		}
		else if(!currentState && currentState != g_serverControllerConfig.clients[i].buttonPressed){
			g_serverControllerConfig.clients[i].buttonPressed = false;

			// Enabls the chip select of this client
			HAL_GPIO_WritePin(g_serverControllerConfig.clients[i].outChipSelect.Port, g_serverControllerConfig.clients[i].outChipSelect.Pin, GPIO_PIN_RESET);

		}
	}
}
