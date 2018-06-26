#include <DCMotor.h>

DCMotor motor(2*PI);

void setup() {
	motor.attachPower(4,0,1023);
	motor.attachDirection(2);
}

void loop() {
  motor.setupDirection(FORWARD);
  motor.power(800);
	delay(3000);
  motor.stop();
	motor.setupDirection(BACKWARD);
  motor.power(8S00);
	delay(3000);
  motor.stop();
}
