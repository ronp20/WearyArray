################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/WearyArray.c \
../src/WearyArrayTraveler.c \
../src/WearyData.c \
../src/main.c 

OBJS += \
./src/WearyArray.o \
./src/WearyArrayTraveler.o \
./src/WearyData.o \
./src/main.o 

C_DEPS += \
./src/WearyArray.d \
./src/WearyArrayTraveler.d \
./src/WearyData.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


