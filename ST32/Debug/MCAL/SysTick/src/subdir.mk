################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SysTick/src/SysTick_program.c 

OBJS += \
./MCAL/SysTick/src/SysTick_program.o 

C_DEPS += \
./MCAL/SysTick/src/SysTick_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SysTick/src/%.o MCAL/SysTick/src/%.su MCAL/SysTick/src/%.cyclo: ../MCAL/SysTick/src/%.c MCAL/SysTick/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-SysTick-2f-src

clean-MCAL-2f-SysTick-2f-src:
	-$(RM) ./MCAL/SysTick/src/SysTick_program.cyclo ./MCAL/SysTick/src/SysTick_program.d ./MCAL/SysTick/src/SysTick_program.o ./MCAL/SysTick/src/SysTick_program.su

.PHONY: clean-MCAL-2f-SysTick-2f-src

