#include "WheelEncoder.h"

WheelEncoder::WheelEncoder() : 
	Wheel(), period_pid_controller_(0.5),pid_(0)
{
	timer_setup_();
}

WheelEncoder::WheelEncoder(float max_speed) : 
	Wheel(max_speed), period_pid_controller_(0.5),pid_(0)
{
	timer_setup_();
}
void WheelEncoder::timer_setup_()
{
	os_timer_setfn(&timer_,WheelEncoder::timer_callback_, this); 
	os_timer_arm(&timer_, this->period_pid_controller_*1000, true);   // timer in ms
}

void WheelEncoder::move(float velocity)
{
	this->targetVelocity_=velocity;
	if (pid_ != 0) {
		pid_->setTarget(this->targetVelocity_);
	}
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

void WheelEncoder::attachPid(Pid * pid)
{	
	this->pid_=pid;
}
	
void WheelEncoder::timer_callback_(void *pArg)
{
	WheelEncoder * wheel = (WheelEncoder *)pArg;
	wheel->update_();
}

void WheelEncoder::update_()
{
	this->currentVelocity_ = encoder_->getVelocity(this->period_pid_controller_);
	if (pid_ != 0) {
		this->demandedVelocity_= 
			pid_->update(this->currentVelocity_,this->period_pid_controller_); //TODO Review this command
	} else {
		this->demandedVelocity_ = targetVelocity_;
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
	Wheel::move(this->demandedVelocity_); //TODO Change this, create a move_ low level.
}