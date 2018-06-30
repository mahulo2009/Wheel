#include "DCMotor.h"

DCMotor::DCMotor() : 
	max_speed_(0),
	velocity_(0),
	duty_(0),
	direction_(FORWARD)
{
}

DCMotor::DCMotor(float max_speed) : 
	max_speed_(max_speed),
	velocity_(0),
	duty_(0),
	direction_(FORWARD)
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
			this->direction_=FORWARD;
      digitalWrite(pin_direction_,LOW);
      break;
    case BACKWARD:
			this->direction_=BACKWARD;
      digitalWrite(pin_direction_,HIGH);
      break;
   }
}

void DCMotor::move(float velocity)
{
	if (velocity<0) {
		setupDirection(BACKWARD);
		this->velocity_=-velocity;	
	} else {
		setupDirection(FORWARD);
		this->velocity_=velocity;	
	}
	float duty = (max_duty_*this->velocity_)/(max_speed_);
	power(duty);
}

void DCMotor::power(float duty)
{
 if (duty<min_duty_)
    duty=min_duty_;
  if (duty>max_duty_)
    duty=max_duty_;
  this->duty_ = ceil(duty); 
  #ifdef DCMOTOR_DEBUG
  Serial.print("DCMotor::power:");
  Serial.print("\t");
  Serial.print(this->duty_);
  Serial.print("\n");
  #endif
  analogWrite(pin_power_,this->duty_); 
}

void DCMotor::stop()
{
  this->duty_=0;
	this->velocity_=0;
	this->direction_=FORWARD;
  analogWrite(pin_power_,0);
  digitalWrite(pin_direction_,LOW);
}
