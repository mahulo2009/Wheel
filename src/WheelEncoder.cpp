#include "WheelEncoder.h"

WheelEncoder::WheelEncoder() : 
	period_pid_controller_(0.5),pid_(0)
{
	timer_setup_();
}

//TODO CALL FROM OUTISE USING TIMER TASK

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
	
void WheelEncoder::timer_callback_(void *pArg)
{
	WheelEncoder * wheel = (WheelEncoder *)pArg;
	wheel->update_();
}

void WheelEncoder::update()
{
	update_();	//TODO CALL THIS FROM OUTSIDE USING A TIMER
}

void WheelEncoder::update_()
{
	this->currentVelocity_ = encoder_->getVelocity(this->period_pid_controller_);
	if (pid_ != 0) {
		this->demandedVelocity_= 
			pid_->update(this->currentVelocity_,this->period_pid_controller_); 
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