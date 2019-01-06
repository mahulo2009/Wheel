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
		
    	virtual void move(float velocity);                          //velocity demanded radians per second.
    	virtual void stop();										//reset duty to 0 and direction to forward
		virtual void update();

		inline Pid * getPid() {return pid_;};
			
	private:

		EncoderBase * encoder_;											//Encoder	
		Pid * pid_;													//Pid
		os_timer_t timer_;											//Timer for periodic task, Pid controller	
		float period_pid_controller_;								//Period of the periodic task, Pid controller
		static void timer_callback_(void *pArg);					//Timer callback function, Pid controller
		void timer_setup_();										//Setup the timer for the periodic task, Pid controller
		void update_();												//Pid controller function
		
};
#endif