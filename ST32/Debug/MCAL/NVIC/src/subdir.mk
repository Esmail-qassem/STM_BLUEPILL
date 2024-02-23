################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/NVIC/src/NVIC_program.c 

OBJS += \
./MCAL/NVIC/src/NVIC_program.o 

C_DEPS += \
./MCAL/NVIC/src/NVIC_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/NVIC/src/%.o MCAL/NVIC/src/%.su MCAL/NVIC/src/%.cyclo: ../MCAL/NVIC/src/%.c MCAL/NVIC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-NVIC-2f-src

clean-MCAL-2f-NVIC-2f-src:
	-$(RM) ./MCAL/NVIC/src/NVIC_program.cyclo ./MCAL/NVIC/src/NVIC_program.d ./MCAL/NVIC/src/NVIC_program.o ./MCAL/NVIC/src/NVIC_program.su

.PHONY: clean-MCAL-2f-NVIC-2f-src

