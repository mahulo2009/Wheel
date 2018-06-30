#include <DCMotor.h>

#define PIN_POWER 4
#define PIN_DIRECTION 2

DCMotor motor(2*PI);

void setup() {
	motor.attachPower(PIN_POWER,0,1023);
	motor.attachDirection(PIN_DIRECTION);
}

void loop() {
  motor.setupDirection(FORWARD);
  motor.power(800);
	delay(3000);
  motor.stop();
	motor.setupDirection(BACKWARD);
  motor.power(800);
	delay(3000);
  motor.stop();
	delay(1000);	
}
