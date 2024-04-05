################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/bruno/OneDrive/Documentos/Unisinos/Micros/Aula_ARM/Trabalho_Serial/mc_serial_con/server_arm/Modules/ServerController/Src/servercontroller.c 

OBJS += \
./Modules/ServerController/Src/servercontroller.o 

C_DEPS += \
./Modules/ServerController/Src/servercontroller.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/ServerController/Src/servercontroller.o: C:/Users/bruno/OneDrive/Documentos/Unisinos/Micros/Aula_ARM/Trabalho_Serial/mc_serial_con/server_arm/Modules/ServerController/Src/servercontroller.c Modules/ServerController/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Modules/ServerController/ -I../../Modules/Common/ -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-ServerController-2f-Src

clean-Modules-2f-ServerController-2f-Src:
	-$(RM) ./Modules/ServerController/Src/servercontroller.cyclo ./Modules/ServerController/Src/servercontroller.d ./Modules/ServerController/Src/servercontroller.o ./Modules/ServerController/Src/servercontroller.su

.PHONY: clean-Modules-2f-ServerController-2f-Src

