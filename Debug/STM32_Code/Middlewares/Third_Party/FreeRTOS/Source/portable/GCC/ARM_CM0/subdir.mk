################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c 

OBJS += \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.o 

C_DEPS += \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/%.o STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/%.su STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/%.cyclo: ../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/%.c STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32G071xx '-DCMSIS_device_header=<stm32g0xx.h>' -DUSE_HAL_DRIVER -c -I../STM32_Code/Core/Inc -I../STM32_Code/Core/Inc/App -I../STM32_Code/Core/Inc/Drivers -I../STM32_Code/Core/Inc/Services -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc -I../STM32_Code/Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../STM32_Code/Drivers/CMSIS/Include -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/include -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_Code-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0

clean-STM32_Code-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0:
	-$(RM) ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.su

.PHONY: clean-STM32_Code-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0

