################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../BinaryStream.o 

CPP_SRCS += \
../Amf3Type.cpp \
../Amf3TypeBoolean.cpp \
../Amf3TypeInteger.cpp \
../Amf3TypeNumber.cpp \
../Amf3TypeObject.cpp \
../Amf3TypeSimple.cpp \
../Amf3TypeString.cpp \
../BinaryStream.cpp \
../Deserializer.cpp \
../main.cpp \
../utils.cpp 

OBJS += \
./Amf3Type.o \
./Amf3TypeBoolean.o \
./Amf3TypeInteger.o \
./Amf3TypeNumber.o \
./Amf3TypeObject.o \
./Amf3TypeSimple.o \
./Amf3TypeString.o \
./BinaryStream.o \
./Deserializer.o \
./main.o \
./utils.o 

CPP_DEPS += \
./Amf3Type.d \
./Amf3TypeBoolean.d \
./Amf3TypeInteger.d \
./Amf3TypeNumber.d \
./Amf3TypeObject.d \
./Amf3TypeSimple.d \
./Amf3TypeString.d \
./BinaryStream.d \
./Deserializer.d \
./main.d \
./utils.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


