################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/AFIO/src/AFIO_program.c 

OBJS += \
./MCAL/AFIO/src/AFIO_program.o 

C_DEPS += \
./MCAL/AFIO/src/AFIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/AFIO/src/%.o MCAL/AFIO/src/%.su MCAL/AFIO/src/%.cyclo: ../MCAL/AFIO/src/%.c MCAL/AFIO/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-AFIO-2f-src

clean-MCAL-2f-AFIO-2f-src:
	-$(RM) ./MCAL/AFIO/src/AFIO_program.cyclo ./MCAL/AFIO/src/AFIO_program.d ./MCAL/AFIO/src/AFIO_program.o ./MCAL/AFIO/src/AFIO_program.su

.PHONY: clean-MCAL-2f-AFIO-2f-src

