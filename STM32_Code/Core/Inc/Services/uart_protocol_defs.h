/*
 * uart_variables.h
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */



#ifndef STM32_CODE_CORE_INC_SERVICES_UART_PROTOCOL_DEFS_H_
#define STM32_CODE_CORE_INC_SERVICES_UART_PROTOCOL_DEFS_H_
#include <stdint.h>


#define START_BYTE            0xAA  // Represents the starting byte of a communication frame.
#define STOP_BYTE             0x55  // Represents the ending byte of a communication frame.

#define MODE_STANDBY          0x00  // Indicates the safe idle state where the system is waiting.
#define MODE_MANUAL           0x01  // Indicates manual control mode driven by user interface inputs.
#define MODE_AUTO             0x02  // Indicates automatic tracking and stabilization mode using sensors.

#define CMD_SET_MODE          0x10  // Command ID used to change the system's current operational mode.
#define CMD_MANUAL_ANGLES     0x11  // Command ID used to send target azimuth and elevation angles.
#define CMD_SET_SATELLITE_GPS 0x12  // Command ID used to provide GPS coordinates for satellite angle calculations.
#define CMD_REQ_TELEMETRY     0x20  // Command ID used to request real-time system and sensor data.
#define CMD_RES_TELEMETRY     0x21  // Response ID indicating the packet contains the requested telemetry data.





#endif /* STM32_CODE_CORE_INC_SERVICES_UART_PROTOCOL_DEFS_H_ */
