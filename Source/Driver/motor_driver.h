#ifndef __MOTOR_DRIVER__H__
#define __MOTOR_DRIVER__H__
/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "debug_api.h"
#include "timer_driver.h"
/**********************************************************************************************************************
 * Exported definitions and macros
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Prototypes of exported functions
 *********************************************************************************************************************/
void Motor_Driver_Init (uint8_t motor_speed);
void Motor_Driver_ChangeSpeed (uint8_t motor_speed);
void Motor_Driver_Start ();
void Motor_Driver_Stop ();
uint32_t Motor_Driver_GetReferenceTime ();
uint32_t Motor_Driver_GetInterval ();
void Motor_Driver_Interrupt ();
#endif /* __MOTOR_DRIVER__H__ */
