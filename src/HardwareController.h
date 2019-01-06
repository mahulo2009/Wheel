#ifndef HardwareController_H
#define HardwareController_H

//#define HARDWARE_CONTROLLER_DEBUG 1

typedef enum { FORWARD, BACKWARD} Wheel_Direction;

class HardwareController {

    public:
    
        HardwareController();
       
        virtual void velocity(double velocity) = 0;

    protected:

        virtual void setupDirection(Wheel_Direction direction) = 0;        
        virtual void power(double power) = 0 ;
};

#endif
