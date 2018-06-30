#ifndef Wheel_Encoder_H
#define Wheel_Encoder_H

#include "Arduino.h"
#include "Wheel.h"
#include "Encoder.h"

#define WHEEL_DEBUG 1

class WheelEncoder : public Wheel {
  public:
    WheelEncoder();													//default constructor.
    WheelEncoder(float max_speed);					//constructor with maximun speed [radians per sencond]
		void attachEncoder(Encoder * encoder);
		virtual float getVelocity(float dt);
  private:
		Encoder * encoder_;
};
#endif

