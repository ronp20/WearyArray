################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/WaryArrayTraveler.c \
../src/WearyArray.c \
../src/WearyStruct.c 

OBJS += \
./src/WaryArrayTraveler.o \
./src/WearyArray.o \
./src/WearyStruct.o 

C_DEPS += \
./src/WaryArrayTraveler.d \
./src/WearyArray.d \
./src/WearyStruct.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


