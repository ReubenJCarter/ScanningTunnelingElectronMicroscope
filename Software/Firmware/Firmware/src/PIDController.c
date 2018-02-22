/*
 * PIDController.c
 *
 * Created: 21/02/2018 20:04:00
 *  Author: reuben
 */ 

#include "PIDController.h"

void PIDControllerInit(PIDController* pidController, float kp, float kd, float ki)
{
	pidController->kP = kp;
	pidController->kD = kd;
	pidController->kI = ki;
	
	pidController->errorPrev = 0;
	pidController->integralTerm = 0;
}

float PIDControllerCompute(PIDController* pidController, float processVariable, float setPoint, float deltaTime)
{ 
	float error = setPoint - processVariable;
	pidController->integralTerm += pidController->kI * error * deltaTime;
	float derivativeTerm = pidController->kD * (error - pidController->errorPrev) / deltaTime;
	float proportionalTerm = pidController->kP * error;
	float ctrlOutput = proportionalTerm + pidController->integralTerm + derivativeTerm;

	pidController->errorPrev = error;
	return ctrlOutput;
}