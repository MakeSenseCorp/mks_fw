################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/terminal/terminal.c 

OBJS += \
./libraries/terminal/terminal.o 

C_DEPS += \
./libraries/terminal/terminal.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/terminal/%.o: ../libraries/terminal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/workspace/Projects/mks_stm32_node/Inc" -I"C:/workspace/Projects/mks_stm32_node/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/workspace/Projects/mks_stm32_node/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/workspace/Projects/mks_stm32_node/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/workspace/Projects/mks_stm32_node/Drivers/CMSIS/Include" -I"C:/workspace/Projects/mks_stm32_node/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/workspace/Projects/mks_stm32_node/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/workspace/Projects/mks_stm32_node/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/workspace/Projects/mks_stm32_node/libraries/uart_print" -I"C:/workspace/Projects/mks_stm32_node/libraries/terminal"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


