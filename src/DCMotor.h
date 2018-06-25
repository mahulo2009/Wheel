#ifndef Motor_DCMotor_H
#define Motor_DCMotor_H

#define DC_MOTOR_DEBUG 1

typedef enum { FORWARD, BACKWARD} DCMotor_Direction;

#include "Arduino.h"

/**
 *
 */
class DCMotor {

  public:
     /**
     *
     */
    DCMotor();

    /**
    *
    */
		void attachPower(int pin,int min_duty, int max_duty);

    /**
    *
    */
		void attachDirection(int pin);
     /**
     *
     */
    void setupDirection(DCMotor_Direction direction);
    /**
     *
     */
    void power(double duty);
    /**
     *
     */
    void stop();
     
  private:

    int pin_power_;
    int pin_direction_;
    int min_duty_;
    int max_duty_;
    int duty_;
  
};
#endif

