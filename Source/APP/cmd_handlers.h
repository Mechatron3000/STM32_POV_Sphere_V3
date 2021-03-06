#ifndef __CMD_HANDLERS__H__
#define __CMD_HANDLERS__H__
/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "debug_api.h"
#include "uart_api.h"
#include "led_api.h"
#include "debug_api.h"
/**********************************************************************************************************************
 * Exported definitions and macros
 *********************************************************************************************************************/
#define CMD_MAX_ARGUMENT_COUNT 5
/**********************************************************************************************************************
 * Exported types
 *********************************************************************************************************************/
typedef struct sCmdHandlerArgs_t {
    char *cmd_args[CMD_MAX_ARGUMENT_COUNT];
    char *response_buffer;
    uint16_t response_buffer_size;
} sCmdHandlerArgs_t;
/**********************************************************************************************************************
 * Exported variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Prototypes of exported functions
 *********************************************************************************************************************/
void CMD_LedBlink (sCmdHandlerArgs_t handler_args);
void CMD_LedToggle (sCmdHandlerArgs_t handler_args);
#endif /* __CMD_HANDLERS__H__ */
