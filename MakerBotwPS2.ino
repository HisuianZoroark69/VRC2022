#define DEBUG

#include "motors.h"
#include "PS2_controller.h"
#include "Controls.h"
#include "Sensor.h"

bool pressed;
unsigned int sensorResult;

void setup()
{
  #ifdef DEBUG
  Serial.begin(115200);
  #endif
  initMotors();
  setupPS2controller();
  SetupSensor();

  initServo(PWM_CHANNELJ3, Normal);
  Serial.println("Done setup!");
}
int i = 0;
void loop()
{
  ps2x.read_gamepad(pressed, 0);
  pressed = false;
  MovementControl(pressed);
  ServoControl(pressed);
  GetSensorResult(sensorResult);

  if(!pressed) resetMotors();

  //Bắt buộc phải delay, k thì lủng LMAO
  delay(25);
}
