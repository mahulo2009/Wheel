#ifndef Wheel_H
#define Wheel_H

#include "WheelBase.h"
#include "Arduino.h"
#include "HardwareController.h"

//#define WHEEL_DEBUG 1

class Wheel : public WheelBase {

  public:

    Wheel();																	//default constructor.

    virtual void move(double velocity);                                //velocity demanded radians per second.
    virtual void stop();															                //reset duty to 0 and direction to forward
    virtual void update(double dt);
    
};
#endif

