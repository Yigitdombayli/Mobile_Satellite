################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_Code/Core/Src/App/task_control.c \
../STM32_Code/Core/Src/App/task_monitor.c \
../STM32_Code/Core/Src/App/task_telemetry.c \
../STM32_Code/Core/Src/App/task_uart_rx.c 

OBJS += \
./STM32_Code/Core/Src/App/task_control.o \
./STM32_Code/Core/Src/App/task_monitor.o \
./STM32_Code/Core/Src/App/task_telemetry.o \
./STM32_Code/Core/Src/App/task_uart_rx.o 

C_DEPS += \
./STM32_Code/Core/Src/App/task_control.d \
./STM32_Code/Core/Src/App/task_monitor.d \
./STM32_Code/Core/Src/App/task_telemetry.d \
./STM32_Code/Core/Src/App/task_uart_rx.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_Code/Core/Src/App/%.o STM32_Code/Core/Src/App/%.su STM32_Code/Core/Src/App/%.cyclo: ../STM32_Code/Core/Src/App/%.c STM32_Code/Core/Src/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32G071xx '-DCMSIS_device_header=<stm32g0xx.h>' -DUSE_HAL_DRIVER -c -I../STM32_Code/Core/Inc -I../STM32_Code/Core/Inc/App -I../STM32_Code/Core/Inc/Drivers -I../STM32_Code/Core/Inc/Services -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc -I../STM32_Code/Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../STM32_Code/Drivers/CMSIS/Include -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/include -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_Code-2f-Core-2f-Src-2f-App

clean-STM32_Code-2f-Core-2f-Src-2f-App:
	-$(RM) ./STM32_Code/Core/Src/App/task_control.cyclo ./STM32_Code/Core/Src/App/task_control.d ./STM32_Code/Core/Src/App/task_control.o ./STM32_Code/Core/Src/App/task_control.su ./STM32_Code/Core/Src/App/task_monitor.cyclo ./STM32_Code/Core/Src/App/task_monitor.d ./STM32_Code/Core/Src/App/task_monitor.o ./STM32_Code/Core/Src/App/task_monitor.su ./STM32_Code/Core/Src/App/task_telemetry.cyclo ./STM32_Code/Core/Src/App/task_telemetry.d ./STM32_Code/Core/Src/App/task_telemetry.o ./STM32_Code/Core/Src/App/task_telemetry.su ./STM32_Code/Core/Src/App/task_uart_rx.cyclo ./STM32_Code/Core/Src/App/task_uart_rx.d ./STM32_Code/Core/Src/App/task_uart_rx.o ./STM32_Code/Core/Src/App/task_uart_rx.su

.PHONY: clean-STM32_Code-2f-Core-2f-Src-2f-App

