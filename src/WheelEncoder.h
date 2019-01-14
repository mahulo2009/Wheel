#ifndef Wheel_Encoder_H
#define Wheel_Encoder_H

#include "Arduino.h"
#include "WheelBase.h"
#include "EncoderBase.h"
#include "Pid.h"

extern "C" {
#include "user_interface.h"
}


#define WHEEL_DEBUG 1

class WheelEncoder : public WheelBase {

	public:
  
    	WheelEncoder();												//default constructor. 

		void attachEncoder(EncoderBase * encoder);						//Attach the Encoder
		void attachPid(Pid * pid);									//Attach the Pid
		
    	virtual void move(double velocity);                          //velocity demanded radians per second.
    	virtual void stop();										//reset duty to 0 and direction to forward
		virtual void update(double dt);

		inline Pid * getPid() {return pid_;};
			
	private:

		EncoderBase * encoder_;											//Encoder	
		Pid * pid_;													//Pid
		void update_(double dt);												//Pid controller function
		
};
#endif