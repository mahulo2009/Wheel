#include <WheelEncoder.h>

#define ENCODER_TICKS_PER_REVOLUTION 21
#define MAX_SPEED 9.42477796076938
#define POWER_MIN 0
#define POWER_MAX 1023
#define PIN_ENCODER 12
#define PIN_POWER 4
#define PIN_DIRECTION 2

//Encoders
Encoder * encoder = new Encoder(ENCODER_TICKS_PER_REVOLUTION);
//Wheel
WheelEncoder wheel(MAX_SPEED);

void setup() {
  //Setup Serial line.
  Serial.begin(115200);
	//Attach Encoder Left
	encoder->attach(PIN_ENCODER);
	wheel.attachEncoder(encoder);

	wheel.attachPower(PIN_POWER,POWER_MIN,POWER_MAX);
	wheel.attachDirection(PIN_DIRECTION);
}

void loop() {
	float velocity = wheel.getVelocity(0.250);
	Serial.print("Wheel velocity:");
  Serial.print("\t");
  Serial.print(velocity);
  Serial.print("\n");

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
