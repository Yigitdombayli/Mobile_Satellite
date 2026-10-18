################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/list.c \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/queue.c \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/croutine.o \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/event_groups.o \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/list.o \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/queue.o \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/tasks.o \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/croutine.d \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/event_groups.d \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/list.d \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/queue.d \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/tasks.d \
./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/%.o STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/%.su STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/%.cyclo: ../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/%.c STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32G071xx '-DCMSIS_device_header=<stm32g0xx.h>' -DUSE_HAL_DRIVER -c -I../STM32_Code/Core/Inc -I../STM32_Code/Core/Inc/App -I../STM32_Code/Core/Inc/Drivers -I../STM32_Code/Core/Inc/Services -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc -I../STM32_Code/Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../STM32_Code/Drivers/CMSIS/Include -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/include -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_Code-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

clean-STM32_Code-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source:
	-$(RM) ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/croutine.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/croutine.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/croutine.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/croutine.su ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/event_groups.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/event_groups.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/event_groups.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/event_groups.su ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/list.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/list.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/list.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/list.su ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/queue.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/queue.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/queue.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/queue.su ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.su ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/tasks.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/tasks.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/tasks.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/tasks.su ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/timers.cyclo ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/timers.d ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/timers.o ./STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/timers.su

.PHONY: clean-STM32_Code-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

