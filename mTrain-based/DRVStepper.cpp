#include "DRVStepper.hpp"
#include "DigitalOut.cpp"
#include "mtrain.h"
#include "delay.h"

DRVStepper::DRVStepper(float rps, PinName speedPin, PinName dirPin, int microstepFactor,
  int motorStepsPerRev, DRVStepper::Direction dir){
    this -> rps = rps;
    this -> motorStepsPerRev = motorStepsPerRev;
    this -> microstepFactor = microstepFactor;
    motor = new DigitalOut (speedPin);
    motor_dir = new DigitalOut (dirPin);
    this -> dir = dir;
}

// computation to determine period
float DRVStepper::rpsToPeriod() {
   float period;
   float steps;
   steps = rps * motorStepsPerRev * microstepFactor;
   period = (1/(steps));
   return period ;
}

// reverses the direction of the motor turns
void DRVStepper::reverseMotor(float runTime) {
  dir = 1 - dir ;
  TurnMotor(runTime);

}

//turns motor in one direction for half the runTime and in opposite direction for next half of runTime
void DRVStepper::TurnMotor(float runTime, DRVStepper::Direction direction) {
  float period = rpsToPeriod();
  float numIter = runTime / period ;
  this -> dir = direction;

  (*motor_dir) = dir;
  int count = 0 ;
  uint32_t delayTime = period / 2 * 1000000;

  while (count < int(numIter)) {
      (*motor) = dir;
      DWT_Delay(delayTime);
      (*motor) = 1 - dir;
      DWT_Delay(delayTime);
      count += 1;

}
