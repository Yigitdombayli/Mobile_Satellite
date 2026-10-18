################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Services/comm_func.c \
../Core/Src/Services/kalman_func.c 

OBJS += \
./Core/Src/Services/comm_func.o \
./Core/Src/Services/kalman_func.o 

C_DEPS += \
./Core/Src/Services/comm_func.d \
./Core/Src/Services/kalman_func.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Services/%.o Core/Src/Services/%.su Core/Src/Services/%.cyclo: ../Core/Src/Services/%.c Core/Src/Services/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32G071xx '-DCMSIS_device_header=<stm32g0xx.h>' -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Core/Inc/App -I../Core/Inc/Services -I../Core/Inc/Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Services

clean-Core-2f-Src-2f-Services:
	-$(RM) ./Core/Src/Services/comm_func.cyclo ./Core/Src/Services/comm_func.d ./Core/Src/Services/comm_func.o ./Core/Src/Services/comm_func.su ./Core/Src/Services/kalman_func.cyclo ./Core/Src/Services/kalman_func.d ./Core/Src/Services/kalman_func.o ./Core/Src/Services/kalman_func.su

.PHONY: clean-Core-2f-Src-2f-Services

