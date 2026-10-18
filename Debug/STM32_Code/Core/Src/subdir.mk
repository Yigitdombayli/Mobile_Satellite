################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_Code/Core/Src/app_freertos.c \
../STM32_Code/Core/Src/main.c \
../STM32_Code/Core/Src/stm32g0xx_hal_msp.c \
../STM32_Code/Core/Src/stm32g0xx_hal_timebase_tim.c \
../STM32_Code/Core/Src/stm32g0xx_it.c \
../STM32_Code/Core/Src/syscalls.c \
../STM32_Code/Core/Src/sysmem.c \
../STM32_Code/Core/Src/system_stm32g0xx.c 

OBJS += \
./STM32_Code/Core/Src/app_freertos.o \
./STM32_Code/Core/Src/main.o \
./STM32_Code/Core/Src/stm32g0xx_hal_msp.o \
./STM32_Code/Core/Src/stm32g0xx_hal_timebase_tim.o \
./STM32_Code/Core/Src/stm32g0xx_it.o \
./STM32_Code/Core/Src/syscalls.o \
./STM32_Code/Core/Src/sysmem.o \
./STM32_Code/Core/Src/system_stm32g0xx.o 

C_DEPS += \
./STM32_Code/Core/Src/app_freertos.d \
./STM32_Code/Core/Src/main.d \
./STM32_Code/Core/Src/stm32g0xx_hal_msp.d \
./STM32_Code/Core/Src/stm32g0xx_hal_timebase_tim.d \
./STM32_Code/Core/Src/stm32g0xx_it.d \
./STM32_Code/Core/Src/syscalls.d \
./STM32_Code/Core/Src/sysmem.d \
./STM32_Code/Core/Src/system_stm32g0xx.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_Code/Core/Src/%.o STM32_Code/Core/Src/%.su STM32_Code/Core/Src/%.cyclo: ../STM32_Code/Core/Src/%.c STM32_Code/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32G071xx '-DCMSIS_device_header=<stm32g0xx.h>' -DUSE_HAL_DRIVER -c -I../STM32_Code/Core/Inc -I../STM32_Code/Core/Inc/App -I../STM32_Code/Core/Inc/Drivers -I../STM32_Code/Core/Inc/Services -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc -I../STM32_Code/Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../STM32_Code/Drivers/CMSIS/Include -I../STM32_Code/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/include -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../STM32_Code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_Code-2f-Core-2f-Src

clean-STM32_Code-2f-Core-2f-Src:
	-$(RM) ./STM32_Code/Core/Src/app_freertos.cyclo ./STM32_Code/Core/Src/app_freertos.d ./STM32_Code/Core/Src/app_freertos.o ./STM32_Code/Core/Src/app_freertos.su ./STM32_Code/Core/Src/main.cyclo ./STM32_Code/Core/Src/main.d ./STM32_Code/Core/Src/main.o ./STM32_Code/Core/Src/main.su ./STM32_Code/Core/Src/stm32g0xx_hal_msp.cyclo ./STM32_Code/Core/Src/stm32g0xx_hal_msp.d ./STM32_Code/Core/Src/stm32g0xx_hal_msp.o ./STM32_Code/Core/Src/stm32g0xx_hal_msp.su ./STM32_Code/Core/Src/stm32g0xx_hal_timebase_tim.cyclo ./STM32_Code/Core/Src/stm32g0xx_hal_timebase_tim.d ./STM32_Code/Core/Src/stm32g0xx_hal_timebase_tim.o ./STM32_Code/Core/Src/stm32g0xx_hal_timebase_tim.su ./STM32_Code/Core/Src/stm32g0xx_it.cyclo ./STM32_Code/Core/Src/stm32g0xx_it.d ./STM32_Code/Core/Src/stm32g0xx_it.o ./STM32_Code/Core/Src/stm32g0xx_it.su ./STM32_Code/Core/Src/syscalls.cyclo ./STM32_Code/Core/Src/syscalls.d ./STM32_Code/Core/Src/syscalls.o ./STM32_Code/Core/Src/syscalls.su ./STM32_Code/Core/Src/sysmem.cyclo ./STM32_Code/Core/Src/sysmem.d ./STM32_Code/Core/Src/sysmem.o ./STM32_Code/Core/Src/sysmem.su ./STM32_Code/Core/Src/system_stm32g0xx.cyclo ./STM32_Code/Core/Src/system_stm32g0xx.d ./STM32_Code/Core/Src/system_stm32g0xx.o ./STM32_Code/Core/Src/system_stm32g0xx.su

.PHONY: clean-STM32_Code-2f-Core-2f-Src

