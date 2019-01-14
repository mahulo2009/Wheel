#include "WheelEncoder.h"

WheelEncoder::WheelEncoder() : 
	pid_(0)
{
}

void WheelEncoder::move(double velocity)
{
	this->targetVelocity_=velocity;

	if (pid_ != 0) {
		pid_->setTarget(this->targetVelocity_);
	}
}

void WheelEncoder::stop()
{
  	this->targetVelocity_=0;

	if (pid_ != 0) {
		pid_->setTarget(this->targetVelocity_);
	}  
	
}

void WheelEncoder::attachEncoder(EncoderBase * encoder)
{
	this->encoder_= encoder;
}

void WheelEncoder::attachPid(Pid * pid)
{	
	this->pid_=pid;
}


void WheelEncoder::update(double dt)
{
	update_(dt);	//TODO CALL THIS FROM OUTSIDE USING A TIMER
}

void WheelEncoder::update_(double dt)
{
	this->currentVelocity_ = encoder_->getVelocity(dt);

	if (pid_ != 0) {
		this->demandedVelocity_= 
			pid_->update(this->currentVelocity_,dt); 
	} else {
		this->demandedVelocity_ = targetVelocity_;
	}
	  
  	this->controller_->velocity(demandedVelocity_);

	if (demandedVelocity_ < 0 ) {
		encoder_->setupDirection(-1);
	} else {
		encoder_->setupDirection(1);
	}

	#ifdef WHEEL_DEBUG
  	Serial.print("WheelEncoder::update_:");
	Serial.print("\t");
  	Serial.print(targetVelocity_);
  	Serial.print("\t");
  	Serial.print(currentVelocity_);
  	Serial.print("\t");
  	Serial.print(this->demandedVelocity_);
  	Serial.print("\n");
  	#endif
}