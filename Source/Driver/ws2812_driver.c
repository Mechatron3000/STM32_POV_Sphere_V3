/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "ws2812_driver.h"
/**********************************************************************************************************************
 * Private definitions and macros
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private typedef
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private constants
 *********************************************************************************************************************/
//uint16_t black[DATA_PER_PIXEL] = {LOW_BYTE};
//uint16_t white[DATA_PER_PIXEL] = {HIGH_BYTE};
//uint16_t stop[STOP_DATA] = {PWM_STOP_VALUE};
//uint16_t red[DATA_PER_PIXEL] = {[0 ... 7] = LOW_BYTE, [8 ... 15] = HIGH_BYTE, [16 ... 23] = LOW_BYTE};
//uint16_t green[DATA_PER_PIXEL] = {[0 ... 7] = HIGH_BYTE, [8 ... 15] = LOW_BYTE, [16 ... 23] = LOW_BYTE};
//uint16_t blue[DATA_PER_PIXEL] = {[0 ... 7] = LOW_BYTE, [8 ... 15] = LOW_BYTE, [16 ... 23] = HIGH_BYTE};
/**********************************************************************************************************************
 * Private variables
 *********************************************************************************************************************/
CREATE_DEBUG_MODULE(WS2812_Driver)

uint16_t *ws2812_driver_pwm_data = NULL; //[PWM_DATA_SIZE] = {[0 ... STOP_BYTES_START_INDEX - 1] = LOW_BYTE, [STOP_BYTES_START_INDEX ... STOP_BYTES_STOP_INDEX] = STOP_BYTE};
uint16_t ws2812_driver_data_elements = 0;
bool ws2812_driver_data_sent_flag = true;
uint16_t ws2812_driver_led_count = 0;
/**********************************************************************************************************************
 * Exported variables and references
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Prototypes of private functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Definitions of private functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Definitions of exported functions
 *********************************************************************************************************************/
void WS2812_Driver_Send (void) {
    while (!ws2812_driver_data_sent_flag) {
    };
    ws2812_driver_data_sent_flag = false;
    HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_3, (uint32_t*) ws2812_driver_pwm_data, ws2812_driver_data_elements);
}

void WS2812_Driver_Init (uint16_t led_count) {
    if (led_count == 0) {
        return;
    }
    ws2812_driver_data_elements = (led_count * DATA_PER_PIXEL) + STOP_DATA;
    ws2812_driver_pwm_data = calloc(ws2812_driver_data_elements, sizeof(uint16_t));
    if (ws2812_driver_pwm_data == NULL) {
        debug("MEMORY ALLOCATION FAILURE in WS2812_Driver_Init\r\n");
    }
}

