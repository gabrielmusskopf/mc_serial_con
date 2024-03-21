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
#define MAX_RX_DATA_LENGTH		2	// 2 bytes
#define MAX_RX_TIMEOUT			100 // 100 ms
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
int CheckRxData(uint8_t *pData){
	int ret = HAL_OK;

	/* Check if is a valid data */
	if(strcmp((char*)pData, (char*)VALID_RX_DATA)){
		ret = HAL_ERROR;
	}

	return ret;
}

/*#################################
 # 		 PUBLIC FUNCTIONS     	  #
 #################################*/

/*
 * @title{Serial Clear RX Buffer}
 *
 * Description: Is responsible to clear the receiver buffer
 */
void SERIAL_ClearRxBuffer(void){
	// Clear RX Buffer
	memset(&g_rxData, 0, sizeof(g_rxData));
}

/*
 * @title{Serial Get Data}
 *
 * Description: Is responsible to get the new data received
 *
 * @param[out] pData - Received data
 */
void SERIAL_GetData(uint8_t *pData){
	// Check if there is a new data
	if(g_receivedRxData > g_processedRxData){
		// Copies the data already verified
		memcpy(pData, g_rxData, MAX_RX_DATA_LENGTH);
		g_processedRxData = g_receivedRxData;
	}
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

	// Clears configuration variable
	memset(&g_serialConfig, 0, sizeof(g_serialConfig));
	// Check if there is configuration
	if(config != NULL){
		// Copies the configuration
		memcpy(&g_serialConfig, config, sizeof(g_serialConfig));
		// Initializes the UART
		HAL_UART_Init(g_serialConfig.usart);
		// Initializes the reception
		HAL_UART_Receive_IT(g_serialConfig.usart, &g_rxData[0], sizeof(g_rxData));
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
void SERIAL_RX_Callback(void){
	/* Check if the reception is enable */
	if(g_seriaReceptionControl){
		/* Check if is valid date received */
		if(CheckRxData(&g_rxData[0]) == HAL_OK){
			/* Increment the received RX data counter */
			g_receivedRxData++;
		}
	}
}
