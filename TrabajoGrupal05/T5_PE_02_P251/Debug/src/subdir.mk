################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Infijo\ a\ postfijo.c 

OBJS += \
./src/Infijo\ a\ postfijo.o 

C_DEPS += \
./src/Infijo\ a\ postfijo.d 


# Each subdirectory must supply rules for building sources it contributes
src/Infijo\ a\ postfijo.o: ../src/Infijo\ a\ postfijo.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Infijo a postfijo.d" -MT"src/Infijo\ a\ postfijo.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


