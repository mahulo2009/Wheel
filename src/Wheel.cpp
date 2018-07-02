#include "Wheel.h"

Wheel::Wheel() : 
	max_speed_(0),
	velocity_(0),
	duty_(0),
	direction_(FORWARD)
{
}

Wheel::Wheel(float max_speed) : 
	max_speed_(max_speed),
	velocity_(0),
	duty_(0),
	direction_(FORWARD)
{
}

float Wheel::getVelocity(float dt)
{
	return velocity_;
}


void Wheel::attachPower(int pin,int min_duty, int max_duty)
{
  this->pin_power_ = pin;
	this->min_duty_=min_duty;
	this->max_duty_=max_duty;
  pinMode(pin, OUTPUT);
}

void Wheel::attachDirection(int pin)
{
	this->pin_direction_=pin;
	pinMode(pin_direction_, OUTPUT);
}

void Wheel::setupDirection(Wheel_Direction direction) 
{
  switch(direction) {
    case FORWARD:
			this->direction_=FORWARD;
  		#ifdef WHEEL_DEBUG
		  Serial.println("Wheel::direction: LOW");
		  #endif
      digitalWrite(pin_direction_,LOW);
      break;
    case BACKWARD:
			this->direction_=BACKWARD;
  		#ifdef WHEEL_DEBUG
		  Serial.println("Wheel::direction: HIGH");
		  #endif
      digitalWrite(pin_direction_,HIGH);
      break;
   }
}

void Wheel::move(float velocity)
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

void Wheel::power(float duty)
{
 if (duty<min_duty_)
    duty=min_duty_;
  if (duty>max_duty_)
    duty=max_duty_;
  this->duty_ = ceil(duty); 
  #ifdef WHEEL_DEBUG
  Serial.print("Wheel::power:");
  Serial.print("\t");
  Serial.print(this->duty_);
  Serial.print("\n");
  #endif
  analogWrite(pin_power_,this->duty_); 
}

void Wheel::stop()
{
  this->duty_=0;
	this->velocity_=0;
	this->direction_=FORWARD;
  #ifdef WHEEL_DEBUG
  Serial.print("Wheel::power:");
  Serial.print("\t");
  Serial.print(this->duty_);
  Serial.print("\n");
  #endif
  analogWrite(pin_power_,0);
  #ifdef WHEEL_DEBUG
  Serial.println("Wheel::direction: LOW");
  #endif
  digitalWrite(pin_direction_,LOW);
}
