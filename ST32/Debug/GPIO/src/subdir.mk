################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/src/GPIO_program.c 

OBJS += \
./GPIO/src/GPIO_program.o 

C_DEPS += \
./GPIO/src/GPIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/src/%.o GPIO/src/%.su GPIO/src/%.cyclo: ../GPIO/src/%.c GPIO/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-GPIO-2f-src

clean-GPIO-2f-src:
	-$(RM) ./GPIO/src/GPIO_program.cyclo ./GPIO/src/GPIO_program.d ./GPIO/src/GPIO_program.o ./GPIO/src/GPIO_program.su

.PHONY: clean-GPIO-2f-src

