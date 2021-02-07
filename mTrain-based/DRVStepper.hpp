#pragma once

#include "DigitalOut.cpp"

class DRVStepper {

public:

  typedef enum {
      Forward = 1,
      Backward = 0
  } Direction;


  // Constructor for stepper motor
  Stepper(float rps, PinName speedPin, PinName dirPin, int microstepFactor = 1, int motorStepsPerRev = 200,
    Direction dir = Forward);

  // Getter and setter for rps
  void setRPS(float rps) {this-> rps = rps; }
  float getRPS() {return rps; }

  // Getter for motorStepsPerRev
  int getMotorStepsPerRev() {return motorStepsPerRev; }
  void setMotorStepsPerRev(int motorStepsPerRev) {this-> motorStepsPerRev = motorStepsPerRev;}

   // Getter for microstepFactor
  int getMicrostepFactor() {return microstepFactor;}
  void setMicrostepFactor(int microstepFactor) {this-> microstepFactor = microstepFactor;}


  // Method reverses the direction of the motor after given waitTime in seconds
  void reverseMotor(float runTime);

  // Method turns motor in a certain direction (default is 0) for a given runTime in seconds
  void TurnMotor(float runTime, DRVStepper::Direction direction);


protected:
  //Rotations per second for the motor
  float rps;

  //How many steps per revolution the motor makes, default is 200
  int motorStepsPerRev;

  //Factor of microstepping, default is 1 with no microstepping
  int microstepFactor;

  //Objects of DigitalOut class to control motor motion and direction
  DigitalOut* motor;
  DigitalOut* motor_dir;

  // Method returns the period in seconds
  float rpsToPeriod();

};
