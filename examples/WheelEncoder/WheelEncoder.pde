#include <WheelEncoder.h>

#define ENCODER_TICKS_PER_REVOLUTION 21
#define MAX_SPEED 10.471975511965978
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
  //Attach Encoder 
  encoder->attach(PIN_ENCODER);
  wheel.attachEncoder(encoder);
  //Attach Power and Pin
  wheel.attachPower(PIN_POWER,POWER_MIN,POWER_MAX);
  wheel.attachDirection(PIN_DIRECTION);
}

void loop() {

  wheel.setupDirection(FORWARD);
  wheel.move(2*PI);

  float velocity = wheel.getVelocity();
  Serial.print("Wheel velocity:");
  Serial.print("\t");
  Serial.print(velocity);
  Serial.print("\n");

  delay(1000);
}
