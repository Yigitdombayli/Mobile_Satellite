################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../STM32_Code/Core/Startup/startup_stm32g071rbtx.s 

OBJS += \
./STM32_Code/Core/Startup/startup_stm32g071rbtx.o 

S_DEPS += \
./STM32_Code/Core/Startup/startup_stm32g071rbtx.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_Code/Core/Startup/%.o: ../STM32_Code/Core/Startup/%.s STM32_Code/Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"/home/dombayli/STM32CubeIDE/FreeRTOS/MobileSatellite/STM32_Code/Core/Src/Drivers" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-STM32_Code-2f-Core-2f-Startup

clean-STM32_Code-2f-Core-2f-Startup:
	-$(RM) ./STM32_Code/Core/Startup/startup_stm32g071rbtx.d ./STM32_Code/Core/Startup/startup_stm32g071rbtx.o

.PHONY: clean-STM32_Code-2f-Core-2f-Startup

