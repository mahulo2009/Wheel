#ifndef Wheel_Encoder_H
#define Wheel_Encoder_H

#include "Arduino.h"
#include "Wheel.h"
#include "Encoder.h"
#include "Pid.h"

extern "C" {
#include "user_interface.h"
}


//#define WHEEL_DEBUG 1

class WheelEncoder : public Wheel {
  public:
    	WheelEncoder();												//default constructor.
   	 	WheelEncoder(float max_speed);								//constructor with maximun speed [radians per sencond]
		void attachEncoder(Encoder * encoder);						//Attach the Encoder
		void attachPid(Pid * pid);									//Attach the Pid
		virtual void setupDirection(Wheel_Direction direction);		//setup direction, H-bridge
		virtual void move(float velocity);                      	//velocity demanded radians per second.
	private:
		Encoder * encoder_;											//Encoder	
		Pid * pid_;													//Pid
		os_timer_t timer_;											//Timer for periodic task, Pid controller	
		float period_pid_controller_;								//Period of the periodic task, Pid controller
		static void timer_callback_(void *pArg);					//Timer callback function, Pid controller
		void timer_setup_();										//Setup the timer for the periodic task, Pid controller
		void update_();												//Pid controller function
};
#endif

