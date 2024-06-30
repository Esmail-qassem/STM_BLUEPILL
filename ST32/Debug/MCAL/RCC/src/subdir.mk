################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC/src/RCC_program.c 

C_DEPS += \
./MCAL/RCC/src/RCC_program.d 

OBJS += \
./MCAL/RCC/src/RCC_program.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC/src/%.o MCAL/RCC/src/%.su MCAL/RCC/src/%.cyclo: ../MCAL/RCC/src/%.c MCAL/RCC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-RCC-2f-src

clean-MCAL-2f-RCC-2f-src:
	-$(RM) ./MCAL/RCC/src/RCC_program.cyclo ./MCAL/RCC/src/RCC_program.d ./MCAL/RCC/src/RCC_program.o ./MCAL/RCC/src/RCC_program.su

.PHONY: clean-MCAL-2f-RCC-2f-src

