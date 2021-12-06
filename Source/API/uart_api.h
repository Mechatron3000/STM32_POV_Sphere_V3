#ifndef __UART_API__H__
#define __UART_API__H__

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "cmsis_os.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "uart_driver.h"
#include "stack_info.h"
#include "debug_api.h"
#include "string_utils.h"
#include "led_app.h"
/**********************************************************************************************************************
 * Exported definitions and macros
 *********************************************************************************************************************/
#define UART_API_MESSAGE_QUEUE_SIZE 1024
/**********************************************************************************************************************
 * Exported types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Prototypes of exported functions
 *********************************************************************************************************************/
void UART_API_Init (eUartEnum_t uart, uint32_t baudrate, char *delimiter);
void UART_API_SendString (eUartEnum_t uart, char *string);
bool UART_API_Receive (eUartEnum_t uart, char *data, uint32_t timeout);
#endif /* __UART_API__H__ */
