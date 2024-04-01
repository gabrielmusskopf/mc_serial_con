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
 # 			INCLUDES		      #
 #################################*/
#define MAX_RX_DATA_LENGTH		1	// 2 bytes
#define VALID_RX_DATA			'T'

/*#################################
 # 		 GLOBAL VARIABLES     	  #
 #################################*/
static uint32_t g_receivedRxData = 0;
static uint32_t g_processedRxData = 0;
static bool g_seriaReceptionControl = false;
SERIAL_Config_t g_serialConfig = {0};
uint8_t g_rxData[MAX_RX_DATA_LENGTH] = {0};

/*#################################
 # 		 PRIVATE FUNCTIONS     	  #
 #################################*/
/*
 * @title{Check RX Data}
 *
 * Description: This function is responsible to validate the received data
 *
 * @param[out] pData - Received data
 */
static int CheckRxData(uint8_t *pData){
	int ret = HAL_ERROR;

	/* Check if is a valid data */
	if(!strcmp((char*)pData, (char*)"T")){
		ret = HAL_OK;
	}

	return ret;
}

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
int SERIAL_GetNewReceivedValidData(void){
	int ret = HAL_ERROR;

	/* Check if there is a new data */
	if(g_receivedRxData > g_processedRxData){
		/* Updates the necessary values */
		g_processedRxData = g_receivedRxData;
		ret = HAL_OK;
	}

	return ret;
}

/*
 * @title{Serial Reception Control}
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

	/** Clears configuration variable */
	memset(&g_serialConfig, 0, sizeof(g_serialConfig));
	/* Check if there is configuration */
	if(config != NULL){
		/* Copies the configuration */
		memcpy(&g_serialConfig, config, sizeof(g_serialConfig));
		/* Initializes the reception */
		HAL_UART_Init(g_serialConfig.usart);
	} else {
		ret = HAL_ERROR;
	}

	return ret;
}

/*
 * @title{Serial RX Callback}
 *
 * Description: Is called when the receiver buffer is full
 *
 */
void SERIAL_Loop(void){
	/* Check if the reception is enable */
	if(g_seriaReceptionControl){
		// Receive
		HAL_UART_Receive(g_serialConfig.usart, &g_rxData[0], sizeof(g_rxData), 1000);
		/* Check if is valid date received */
		if(CheckRxData(&g_rxData[0]) == HAL_OK){
			/* Increment the received RX data counter */
			g_receivedRxData++;
		}
	}
}
