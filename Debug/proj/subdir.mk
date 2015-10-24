################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../proj/Butter.cpp \
../proj/Camera.cpp \
../proj/Car.cpp \
../proj/Cheerio.cpp \
../proj/DynamicObject.cpp \
../proj/Entity.cpp \
../proj/GameManager.cpp \
../proj/GameObject.cpp \
../proj/LightSource.cpp \
../proj/Obstacle.cpp \
../proj/Orange.cpp \
../proj/OrthogonalCamera.cpp \
../proj/PerspectiveCamera.cpp \
../proj/StaticObject.cpp \
../proj/Track.cpp \
../proj/Vector3.cpp \
../proj/main.cpp \
../proj/stdafx.cpp 

OBJS += \
./proj/Butter.o \
./proj/Camera.o \
./proj/Car.o \
./proj/Cheerio.o \
./proj/DynamicObject.o \
./proj/Entity.o \
./proj/GameManager.o \
./proj/GameObject.o \
./proj/LightSource.o \
./proj/Obstacle.o \
./proj/Orange.o \
./proj/OrthogonalCamera.o \
./proj/PerspectiveCamera.o \
./proj/StaticObject.o \
./proj/Track.o \
./proj/Vector3.o \
./proj/main.o \
./proj/stdafx.o 

CPP_DEPS += \
./proj/Butter.d \
./proj/Camera.d \
./proj/Car.d \
./proj/Cheerio.d \
./proj/DynamicObject.d \
./proj/Entity.d \
./proj/GameManager.d \
./proj/GameObject.d \
./proj/LightSource.d \
./proj/Obstacle.d \
./proj/Orange.d \
./proj/OrthogonalCamera.d \
./proj/PerspectiveCamera.d \
./proj/StaticObject.d \
./proj/Track.d \
./proj/Vector3.d \
./proj/main.d \
./proj/stdafx.d 


# Each subdirectory must supply rules for building sources it contributes
proj/%.o: ../proj/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


