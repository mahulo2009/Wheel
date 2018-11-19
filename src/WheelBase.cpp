#include "WheelBase.h"

WheelBase::WheelBase():
    targetVelocity_(0),
    currentVelocity_(0),
    demandedVelocity_(0)
{
}

void WheelBase::attachController(HardwareController * controller)
{
  this->controller_ = controller;
}
