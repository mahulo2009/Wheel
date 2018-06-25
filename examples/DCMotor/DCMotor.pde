#include <DCMotor.h>

DCMotor motor;

void setup() {
  // put your setup code here, to run once:
	motor.attachPower(0,0,255);
	motor.attachDirection(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.setupDirection(FORWARD);
  motor.power(50);
  motor.stop();

}
