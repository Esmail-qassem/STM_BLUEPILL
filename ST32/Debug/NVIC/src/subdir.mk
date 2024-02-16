################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NVIC/src/NVIC_program.c 

OBJS += \
./NVIC/src/NVIC_program.o 

C_DEPS += \
./NVIC/src/NVIC_program.d 


# Each subdirectory must supply rules for building sources it contributes
NVIC/src/%.o NVIC/src/%.su NVIC/src/%.cyclo: ../NVIC/src/%.c NVIC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-NVIC-2f-src

clean-NVIC-2f-src:
	-$(RM) ./NVIC/src/NVIC_program.cyclo ./NVIC/src/NVIC_program.d ./NVIC/src/NVIC_program.o ./NVIC/src/NVIC_program.su

.PHONY: clean-NVIC-2f-src

