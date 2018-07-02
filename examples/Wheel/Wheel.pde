#include <Wheel.h>

#define MAX_SPEED 9.42477796076938
#define PIN_POWER 4
#define PIN_DIRECTION 2
#define POWER_MIN 0
#define POWER_MAX 1023

Wheel wheel(MAX_SPEED);

void setup() {
	//Setup Serial line.
  	Serial.begin(115200);
	wheel.attachPower(PIN_POWER,POWER_MIN,POWER_MAX);
	wheel.attachDirection(PIN_DIRECTION);
}

void loop() {
	wheel.move(0.1);
	delay(2500);
	wheel.move(-0.1);
	delay(2500);
	wheel.stop();
	delay(1000);
}
