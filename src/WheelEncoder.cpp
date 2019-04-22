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

void WheelEncoder::attachPid(Pid * pid)
{	
	this->pid_=pid;
}


void WheelEncoder::update(double dt)
{
	this->currentVelocity_ = controller_->getVelocity(dt); //TODO UPDATE

	if (pid_ != 0) {
		this->demandedVelocity_= 
			pid_->update(this->currentVelocity_,dt); 
	} else {
		this->demandedVelocity_ = targetVelocity_;
	}
	  
  	this->controller_->velocity(demandedVelocity_);

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
