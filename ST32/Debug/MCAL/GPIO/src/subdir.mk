################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/src/GPIO_program.c 

C_DEPS += \
./MCAL/GPIO/src/GPIO_program.d 

OBJS += \
./MCAL/GPIO/src/GPIO_program.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/src/%.o MCAL/GPIO/src/%.su MCAL/GPIO/src/%.cyclo: ../MCAL/GPIO/src/%.c MCAL/GPIO/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-GPIO-2f-src

clean-MCAL-2f-GPIO-2f-src:
	-$(RM) ./MCAL/GPIO/src/GPIO_program.cyclo ./MCAL/GPIO/src/GPIO_program.d ./MCAL/GPIO/src/GPIO_program.o ./MCAL/GPIO/src/GPIO_program.su

.PHONY: clean-MCAL-2f-GPIO-2f-src

