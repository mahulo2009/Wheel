#include "ArduinoDutySingleMotorHardwareController.h"

ArduinoDutySingleMotorHardwareController::ArduinoDutySingleMotorHardwareController(float max_speed,int min_duty, int max_duty):
    max_speed_(max_speed), min_duty_(min_duty), max_duty_(max_duty)
{

}

void ArduinoDutySingleMotorHardwareController::attachPower(int pin)
{
    this->pin_power_ = pin;
    pinMode(pin_power_, OUTPUT);
    analogWrite(pin_power_,0); 
}

void ArduinoDutySingleMotorHardwareController::attachDirection(int pin)
{
	this->pin_direction_=pin;
	pinMode(pin_direction_, OUTPUT);
}

void ArduinoDutySingleMotorHardwareController::setupDirection(Wheel_Direction direction) 
{
  switch(direction) {

    case FORWARD:

        digitalWrite(pin_direction_,LOW);

        break;

    case BACKWARD:

		digitalWrite(pin_direction_,HIGH);

      break;
   }
   
}

void ArduinoDutySingleMotorHardwareController::velocity(float velocity)
{
    if (velocity < 0) {
		setupDirection(BACKWARD);	
	} else {
  		setupDirection(FORWARD);
	}

  	float duty = ( (max_duty_-min_duty_) * abs(velocity) ) / (max_speed_) + min_duty_;
    power(duty);
}

void ArduinoDutySingleMotorHardwareController::power(float duty)
{
    if (duty<=min_duty_)
        duty=0;
    if (duty>max_duty_)
        duty=max_duty_;

    this->duty_ = ceil(duty); 

    #ifdef ARDUINIO_DUTY_SINGLE_MOTOR_HARDWARE_CONTROLLER_DEBUG
    Serial.print("ArduinoDutySingleMotorHardwareController::power:");
    Serial.print("\t");
    Serial.print(this->duty_);
    Serial.print("\n");
    #endif

    analogWrite(pin_power_,this->duty_); 
}

