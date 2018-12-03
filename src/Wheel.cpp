#include "Wheel.h"

Wheel::Wheel() 
{
}

void Wheel::move(float velocity)
{ 
  this->demandedVelocity_= velocity;
  this->controller_->velocity(demandedVelocity_);
}

void Wheel::stop()
{

  this->controller_->velocity(0);
  
  this->targetVelocity_=0;
  this->currentVelocity_=0;
  this->demandedVelocity_=0;

  #ifdef WHEEL_DEBUG
  Serial.print("Wheel::power:");
  Serial.print("\t");
  Serial.print(0);
  Serial.print("\n");
  #endif
  
}