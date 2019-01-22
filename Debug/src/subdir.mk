################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Adjusted.c \
../src/Basic.c \
../src/Check.c \
../src/Datefun.c \
../src/Fileio.c \
../src/Matrix.c \
../src/Propagate.c \
../src/Vector.c 

OBJS += \
./src/Adjusted.o \
./src/Basic.o \
./src/Check.o \
./src/Datefun.o \
./src/Fileio.o \
./src/Matrix.o \
./src/Propagate.o \
./src/Vector.o 

C_DEPS += \
./src/Adjusted.d \
./src/Basic.d \
./src/Check.d \
./src/Datefun.d \
./src/Fileio.d \
./src/Matrix.d \
./src/Propagate.d \
./src/Vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


