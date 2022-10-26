################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/autos.c \
../src/informes.c \
../src/p1lab1.1a.c \
../src/trabajos.c \
../src/validaciones.c 

C_DEPS += \
./src/autos.d \
./src/informes.d \
./src/p1lab1.1a.d \
./src/trabajos.d \
./src/validaciones.d 

OBJS += \
./src/autos.o \
./src/informes.o \
./src/p1lab1.1a.o \
./src/trabajos.o \
./src/validaciones.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/autos.d ./src/autos.o ./src/informes.d ./src/informes.o ./src/p1lab1.1a.d ./src/p1lab1.1a.o ./src/trabajos.d ./src/trabajos.o ./src/validaciones.d ./src/validaciones.o

.PHONY: clean-src

