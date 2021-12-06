/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "motor_driver.h"
/**********************************************************************************************************************
 * Private definitions and macros
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private typedef
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private constants
 *********************************************************************************************************************/
#define MOTOR_DRIVER_MAX_SPEED_VALUE 100
#define MOTOR_DRIVER_MIN_SPEED_VALUE 1
/**********************************************************************************************************************
 * Private variables
 *********************************************************************************************************************/
CREATE_DEBUG_MODULE(MOTOR_DRIVER)

uint8_t motor_driver_motor_speed = MOTOR_DRIVER_MAX_SPEED_VALUE;

uint32_t motor_driver_now = 0;
uint32_t motor_driver_new_time = 0;
uint32_t motor_driver_old_time = 0;
uint32_t motor_driver_interval = 1;
uint32_t motor_driver_rotations = 0;
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
void Motor_Driver_Init (uint8_t motor_speed) {
    if (motor_speed > MOTOR_DRIVER_MAX_SPEED_VALUE) {
        return;
    }
    TIM3->CCR1 = MOTOR_DRIVER_MAX_SPEED_VALUE;
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void Motor_Driver_ChangeSpeed (uint8_t motor_speed) {
    if (motor_speed > MOTOR_DRIVER_MAX_SPEED_VALUE) {
        debug("Motor speed value not inside %d - %d bounds\r\n", MOTOR_DRIVER_MIN_SPEED_VALUE, MOTOR_DRIVER_MAX_SPEED_VALUE);
        return;
    }
    motor_driver_motor_speed = motor_speed;
    debug("Motor speed changed to %d%\r\n", motor_speed);
}

void Motor_Driver_Start () {
    TIM3->CCR1 = MOTOR_DRIVER_MAX_SPEED_VALUE - motor_driver_motor_speed;
    debug("Motor started\r\n");
}

void Motor_Driver_Stop () {
    TIM3->CCR1 = MOTOR_DRIVER_MAX_SPEED_VALUE;
    debug("Motor stopped\r\n");
}

uint32_t Motor_Driver_GetReferenceTime () {
    return motor_driver_new_time;
}

uint32_t Motor_Driver_GetInterval () {

}

void Motor_Driver_Interrupt () {
    motor_driver_rotations++;
    if (motor_driver_rotations >= 5) {
        motor_driver_rotations -= 5;
        motor_driver_old_time = motor_driver_new_time;
        motor_driver_new_time = Timer_Driver_GetCurrentTime();
        motor_driver_interval = motor_driver_new_time - motor_driver_old_time;
    }
}
