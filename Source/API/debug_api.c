/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "debug_api.h"
/**********************************************************************************************************************
 * Private definitions and macros
 *********************************************************************************************************************/
#define DEBUG_API_MSG_SIZE 1024
#define DEBUG_MODULE_AMOUNT 5
#define DEBUG_API_UART eUartDriverUsart1
#define DEBUG_API_UART_BAUDRATE 921600
#define DEBUG_API_UART_DELIMITER "\n"
/**********************************************************************************************************************
 * Private typedef
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private constants
 *********************************************************************************************************************/
const osMutexAttr_t debug_api_mutex_attr = {
    "debug_api_mutex",
    osMutexRecursive | osMutexPrioInherit,
    NULL,
    0U
};
/**********************************************************************************************************************
 * Private variables
 *********************************************************************************************************************/
osMutexId_t debug_api_mutex_id = NULL;
/**********************************************************************************************************************
 * Exported variables and references
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Prototypes of private functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Definitions of private functions
 *********************************************************************************************************************/

static void Debug_API_SendString (char *string) {
    if (string == NULL) {
        super_debug("[SD]\tNULL POINTER in Debug_API_Send\r\n");
        return;
    }
    VCP_API_SendString(string);
}

static void Debug_API_Print (const char *tag, const char *format, va_list args) {
    char *buffer = calloc(DEBUG_API_MSG_SIZE, sizeof(char));
    uint16_t offset = 0;
    offset += snprintf(buffer, DEBUG_API_MSG_SIZE, "[%s]\tDEBUG:\t", tag);
    if (format) {
        offset += vsnprintf(&buffer[offset], DEBUG_API_MSG_SIZE - offset, format, args);
    }
    Debug_API_SendString(buffer);
    free(buffer);
}
/**********************************************************************************************************************
 * Definitions of exported functions
 *********************************************************************************************************************/
void Debug_API_Init (void) {
    //UART_API_Init(DEBUG_API_UART, DEBUG_API_UART_BAUDRATE, DEBUG_API_UART_DELIMITER);
    debug_api_mutex_id = osMutexNew(&debug_api_mutex_attr);
    if (debug_api_mutex_id == NULL) {
        super_debug("[SD]\tMUTEX CREATION FAILURE in Debug_API_Init\r\n");
    }
}

void Debug_API_Log (struct debug_module *module, const char *format, ...) {
    osMutexAcquire(debug_api_mutex_id, osWaitForever);
    va_list args;
    va_start(args, format);
    Debug_API_Print(module->name, format, args);
    va_end(args);
    osMutexRelease(debug_api_mutex_id);
}

eUartEnum_t Debug_API_ReturnUart(void) {
    return DEBUG_API_UART;
}
