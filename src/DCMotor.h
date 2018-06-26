#ifndef Motor_DCMotor_H
#define Motor_DCMotor_H

#include "Arduino.h"

#define DC_MOTOR_DEBUG 1

typedef enum { FORWARD, BACKWARD} DCMotor_Direction;

class DCMotor {
  public:
    DCMotor();																							//default constructor.
    DCMotor(float max_speed);																//constructor with maximun speed [radians per sencond]
		void attachPower(int pin,int min_duty, int max_duty);		//attach the power pin selecting the maximum and minimum duty
		void attachDirection(int pin);													//attach the direction pin
    void setupDirection(DCMotor_Direction direction);				//setup direction, H-bridge
		void move(float velocity);															//velocity demanded radians per second.
    void power(float duty);																	//duty demanded
    void stop();																						//reset duty to 0 and direction to forward
		inline DCMotor_Direction getDirection() {return direction_;};
		inline float getVelocity() {return velocity_;};
		inline int getDuty() {return duty_;};
  private:
    int pin_power_;				//pin number for the motor power, pwm.
    int pin_direction_;		//pin number for the motor direction, H-bridge.
    int min_duty_;				//minimum duty
    int max_duty_;				//maximun duty
    float max_speed_;			//maximun speed of the motor in radians per second.
    int duty_;						//duty currently sent to the motor.
		float velocity_;					//current velocity, related to the duty, sent to the motor.
		DCMotor_Direction direction_;	//current direction.
};
#endif

