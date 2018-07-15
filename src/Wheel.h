#ifndef Wheel_H
#define Wheel_H

#include "Arduino.h"

//#define WHEEL_DEBUG 1

typedef enum { FORWARD, BACKWARD} Wheel_Direction;

class Wheel {
  public:
    Wheel();																							  //default constructor.
    Wheel(float max_speed);																  //constructor with maximun speed [radians per sencond]
		void attachPower(int pin,int min_duty, int max_duty);		//attach the power pin selecting the maximum and minimum duty
		void attachDirection(int pin);													//attach the direction pin
    void power(float duty);																	//duty demanded
    void stop();																						//reset duty to 0 and direction to forward

		inline Wheel_Direction getDirection() 
      {return direction_;};
    inline int getDuty() 
      {return duty_;};
    inline float getTargetVelocity() 
      {return targetVelocity_;};
    inline float getVelocity() 
      {return currentVelocity_;};
    inline float getDemandedVelocity() 
      {return demandedVelocity_;};

    virtual void setupDirection(Wheel_Direction direction); //setup direction, H-bridge
    virtual void move(float velocity);                      //velocity demanded radians per second.
    
	protected:
    float targetVelocity_;      //Target velocity [radians per second] 
		float currentVelocity_;			//Current velocity [radians per second] 
    float demandedVelocity_;    //Demanded velocity [radians per second]  
  private:
    int pin_power_;				      //pin number for the motor power, pwm.
    int pin_direction_;		      //pin number for the motor direction, H-bridge.
    int min_duty_;				      //minimum duty
    int max_duty_;				      //maximun duty
    float max_speed_;			      //maximun speed of the motor in radians per second.
    int duty_;						      //duty currently sent to the motor.
		Wheel_Direction direction_;	//current direction.
};
#endif

