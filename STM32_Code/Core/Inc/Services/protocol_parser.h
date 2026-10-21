/*
 * protocol_parser.h
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */

#ifndef STM32_CODE_CORE_INC_DRIVERS_PROTOCOL_PARSER_H_
#define STM32_CODE_CORE_INC_DRIVERS_PROTOCOL_PARSER_H_

#define MAX_PAYLOAD_SIZE	  32

#pragma pack(push, 1)
//Frame
typedef struct {
    uint8_t  startByte;                 // Represents the starting indicator of the communication frame.
    uint8_t	 commandID;
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

#endif /* STM32_CODE_CORE_INC_DRIVERS_PROTOCOL_PARSER_H_ */
