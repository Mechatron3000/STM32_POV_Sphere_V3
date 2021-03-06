/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "timer_driver.h"
/**********************************************************************************************************************
 * Private definitions and macros
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private typedef
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private constants
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private variables
 *********************************************************************************************************************/
CREATE_DEBUG_MODULE(TIMER_DRIVER)
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
void Timer_Driver_Init_TIM1 () {
    MX_TIM1_Init();
}

void Timer_Driver_Init_TIM2 () {
    MX_TIM2_Init();
}

void Timer_Driver_Init_TIM3 () {
    MX_TIM3_Init();
}
