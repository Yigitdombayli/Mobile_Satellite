/*
 * uart_variables.h
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */
#include <stdint.h>


#ifndef STM32_CODE_CORE_INC_SERVICES_UART_VARIABLES_H_
#define STM32_CODE_CORE_INC_SERVICES_UART_VARIABLES_H_

#define MAX_PAYLOAD_SIZE	  32

#define START_BYTE            0xAA  // Represents the starting byte of a communication frame.
#define STOP_BYTE             0x55  // Represents the ending byte of a communication frame.

#define MODE_STANDBY          0x00  // Indicates the safe idle state where the system is waiting.
#define MODE_MANUEL           0x01  // Indicates manual control mode driven by user interface inputs.
#define MODE_AUTO             0x02  // Indicates automatic tracking and stabilization mode using sensors.

#define CMD_SET_MODE          0x10  // Command ID used to change the system's current operational mode.
#define CMD_MANUAL_ANGLES     0x11  // Command ID used to send target azimuth and elevation angles.
#define CMD_SET_SATELLİTE_GPS 0x12  // Command ID used to provide GPS coordinates for satellite angle calculations.
#define CMD_REQ_TELEMETRY     0x20  // Command ID used to request real-time system and sensor data.
#define CMD_RES_TELEMETRY     0x21  // Response ID indicating the packet contains the requested telemetry data.


#pragma pack(push, 1)

//Frame
typedef struct {
    uint8_t  startByte;                 // Represents the starting indicator of the communication frame.
    uint8_t  payloadLength;             // Indicates the number of actual data bytes contained in the payload.
    uint8_t  payload[MAX_PAYLOAD_SIZE]; // Holds the actual data structure being transmitted.
    uint16_t crc16;                     // Stores the 16-bit checksum value to verify data integrity.
    uint8_t  stopByte;                  // Represents the ending indicator of the communication frame.
} UartFrame_t;

//Telemetry Data
typedef struct {
    uint8_t currentMode;      // Indicates the currently active operational mode (e.g., Standby, Manual, Auto).
    float   currentAzimuth;   // Represents the real-time azimuth angle of the antenna in degrees.
    float   currentElevation; // Represents the real-time elevation angle of the antenna in degrees.
    float   currentRoll;      // Stores the real-time roll angle of the Stewart platform from the IMU.
    float   currentPitch;     // Stores the real-time pitch angle of the Stewart platform from the IMU.
    uint8_t systemStatus;     // Contains error codes or system health flags (0x00 indicates no error).
} TelemetryData_t;

//Manual Command Data
typedef struct {
    float targetAzimuth;      // Specifies the desired azimuth angle set by the user via the interface.
    float targetElevation;    // Specifies the desired elevation angle set by the user via the interface.
} ManualCommandData_t;

//GPS Parameter Data
typedef struct {
    float latitude;           // Contains the GPS latitude coordinate entered or acquired from the interface.
    float longitude;          // Contains the GPS longitude coordinate entered or acquired from the interface.
} GpsParameterData_t;

#pragma pack(pop)
#endif /* STM32_CODE_CORE_INC_SERVICES_UART_VARIABLES_H_ */
