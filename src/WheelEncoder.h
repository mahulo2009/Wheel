#ifndef Wheel_Encoder_H
#define Wheel_Encoder_H

#include "Arduino.h"
#include "WheelBase.h"
#include "Pid.h"

#if defined(ESP8266)
extern "C" {
#include "user_interface.h"
}
#endif

#define WHEEL_DEBUG 1

class WheelEncoder : public WheelBase {

	public:
  
    	WheelEncoder();												//default constructor. 

		
    	virtual void move(double velocity);                          //velocity demanded radians per second.
    	virtual void stop();										//reset duty to 0 and direction to forward

		virtual void update(double dt);
		
		void attachPid(Pid * pid);									//Attach the Pid


		inline Pid * getPid() {return pid_;};
			
	private:

		Pid * pid_;													//Pid		
		
};
#endif