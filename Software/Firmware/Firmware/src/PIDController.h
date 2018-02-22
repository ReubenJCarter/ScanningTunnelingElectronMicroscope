/*
 * PIDController.h
 *
 * Created: 21/02/2018 20:03:37
 *  Author: reuben
 */ 


#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_


typedef struct
{
	float errorPrev;
	float integralTerm;
	float kP;
	float kD;
	float kI;
} PIDController;

void PIDControllerInit(PIDController* pidController, float kp, float kd, float ki);
float PIDControllerCompute (PIDController* pidController, float processVariable, float setPoint, float deltaTime);


#endif /* PIDCONTROLLER_H_ */