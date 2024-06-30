################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI/src/EXTI_program.c 

C_DEPS += \
./MCAL/EXTI/src/EXTI_program.d 

OBJS += \
./MCAL/EXTI/src/EXTI_program.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTI/src/%.o MCAL/EXTI/src/%.su MCAL/EXTI/src/%.cyclo: ../MCAL/EXTI/src/%.c MCAL/EXTI/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-EXTI-2f-src

clean-MCAL-2f-EXTI-2f-src:
	-$(RM) ./MCAL/EXTI/src/EXTI_program.cyclo ./MCAL/EXTI/src/EXTI_program.d ./MCAL/EXTI/src/EXTI_program.o ./MCAL/EXTI/src/EXTI_program.su

.PHONY: clean-MCAL-2f-EXTI-2f-src

