################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp \
../src/turtle.cpp \
../src/utils.cpp \
../src/window.cpp 

OBJS += \
./src/main.o \
./src/turtle.o \
./src/utils.o \
./src/window.o 

CPP_DEPS += \
./src/main.d \
./src/turtle.d \
./src/utils.d \
./src/window.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


