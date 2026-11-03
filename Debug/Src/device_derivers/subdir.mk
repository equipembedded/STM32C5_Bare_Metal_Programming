################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/device_derivers/gpio.c 

OBJS += \
./Src/device_derivers/gpio.o 

C_DEPS += \
./Src/device_derivers/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Src/device_derivers/%.o Src/device_derivers/%.su Src/device_derivers/%.cyclo: ../Src/device_derivers/%.c Src/device_derivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32C562KETx -DSTM32C5 -c -I../Inc -I../Inc/device_drivers -I../Inc/device_headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-device_derivers

clean-Src-2f-device_derivers:
	-$(RM) ./Src/device_derivers/gpio.cyclo ./Src/device_derivers/gpio.d ./Src/device_derivers/gpio.o ./Src/device_derivers/gpio.su

.PHONY: clean-Src-2f-device_derivers

