#include <Wheel.h>

#define PIN_POWER 4
#define PIN_DIRECTION 2

Wheel wheel(2*PI);

void setup() {
	wheel.attachPower(PIN_POWER,0,1023);
	wheel.attachDirection(PIN_DIRECTION);
}

void loop() {
  wheel.setupDirection(FORWARD);
  wheel.power(800);
	delay(3000);
  wheel.stop();
	wheel.setupDirection(BACKWARD);
  wheel.power(800);
	delay(3000);
  wheel.stop();
	delay(1000);	
}
