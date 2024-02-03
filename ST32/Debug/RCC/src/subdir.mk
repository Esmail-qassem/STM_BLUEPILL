################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RCC/src/RCC_program.c 

OBJS += \
./RCC/src/RCC_program.o 

C_DEPS += \
./RCC/src/RCC_program.d 


# Each subdirectory must supply rules for building sources it contributes
RCC/src/%.o RCC/src/%.su RCC/src/%.cyclo: ../RCC/src/%.c RCC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-RCC-2f-src

clean-RCC-2f-src:
	-$(RM) ./RCC/src/RCC_program.cyclo ./RCC/src/RCC_program.d ./RCC/src/RCC_program.o ./RCC/src/RCC_program.su

.PHONY: clean-RCC-2f-src

