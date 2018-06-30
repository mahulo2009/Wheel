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

