#include "DCMotor.h"

DCMotor::DCMotor()
{
  
}

void DCMotor::attachPower(int pin,int min_duty, int max_duty)
{
  this->pin_power_ = pin;
	this->min_duty_=min_duty;
	this->max_duty_=max_duty;

  pinMode(pin, OUTPUT);
}

void DCMotor::attachDirection(int pin)
{
	this->pin_direction_=pin;

	pinMode(pin_direction_, OUTPUT);
}

void DCMotor::setupDirection(DCMotor_Direction direction) 
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

void DCMotor::power(double duty)
{
  
 if (duty<min_duty_)
    duty=min_duty_;
  if (duty>max_duty_)
    duty=max_duty_;
  
  this->duty_ = duty; 
  
  #ifdef DC_MOTOR_DEBUG
  Serial.print("DCMotor::power:");
  Serial.print("\t");
  Serial.print(this->duty_);
  Serial.print("\n");
  #endif
    
  //Send to the hardware both duty and direcction
  analogWrite(pin_power_,this->duty_); 
}

void DCMotor::stop()
{
  analogWrite(pin_power_,0);
  digitalWrite(pin_direction_,LOW);
  this->duty_=0;
}
