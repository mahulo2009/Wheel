#ifndef Arduino_Duty_Single_Motor_HardwareController_H
#define Arduino_Duty_Single_Motor_HardwareController_H

 #include "HardwareController.h"
 #include "Arduino.h"

//#define ARDUINIO_DUTY_SINGLE_MOTOR_HARDWARE_CONTROLLER_DEBUG 1

class ArduinoDutySingleMotorHardwareController : public HardwareController {

    public:

        ArduinoDutySingleMotorHardwareController(double max_speed,int min_duty, int max_duty);
        
        void attachPower(int pin);		                                           //attach the power pin selecting
		void attachDirection(int pin);											   //attach the direction pin

        
        virtual void velocity(double velocity);
    
    protected:
    
        virtual void setupDirection(Wheel_Direction direction);       
        virtual void power(double duty);

    private:

        double max_speed_;			    //maximun speed of the motor in radians per second.
        int min_duty_;				    //minimum duty
        int max_duty_;				    //maximun duty
        int pin_power_;				    //pin number for the motor power, pwm.
        int pin_direction_;		        //pin number for the motor direction, H-bridge.	
        int duty_;						//duty currently sent to the motor.
};

#endif
