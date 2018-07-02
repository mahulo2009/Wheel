#include "WheelEncoder.h"

WheelEncoder::WheelEncoder() : 
	Wheel()
{
}

WheelEncoder::WheelEncoder(float max_speed) : 
	Wheel(max_speed)
{
}

float WheelEncoder::getVelocity(float dt)
{
	this->velocity_ = encoder_->getVelocity(dt);
	return velocity_;
}

void WheelEncoder::attachEncoder(Encoder * encoder)
{
	this->encoder_= encoder;
}

void WheelEncoder::setupDirection(Wheel_Direction direction)
{
	Wheel::setupDirection(direction);
	switch(direction) {
    	case FORWARD:
    		encoder_->setupDirection(1);
			break;
    	case BACKWARD:
			encoder_->setupDirection(-1);
      		break;
   }
}

