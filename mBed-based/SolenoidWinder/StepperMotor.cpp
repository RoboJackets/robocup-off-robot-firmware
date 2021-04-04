 #include "mbed.h"
 #include "Stepper.h"

 // Stepper constructor

    Stepper::Stepper(float rps, PinName speedPin, PinName dirPin, int microstepFactor, int motorStepsPerRev, int dir) {
        this-> rps = rps;
        this-> motorStepsPerRev = motorStepsPerRev;
        this -> microstepFactor = microstepFactor;
        motor = new DigitalOut (speedPin);
        motor_dir = new DigitalOut (dirPin);
        this-> dir = dir; }

    // Method returns the period in seconds
    float Stepper::rpsToPeriod () {
            float period;
            float steps;
            steps = rps * motorStepsPerRev * microstepFactor;
            period = (1/(steps));
            return period ; }

    // Method reverses direction of motor
   // void Stepper::reverseMotor(int runTime) {
     //   int period = rpsToPeriod();
       // dir = 1 - dir ;
        //TurnMotor(runTime); }

    // Method turns motor in one direction then in the other direction, each for half of period 
    void Stepper::TurnMotor(int runTime) {
           float period = rpsToPeriod();
           float numIter = runTime / period ;
           (*motor_dir) = dir;
           int count = 0 ;
           while (count < int(numIter)) {
               (*motor) = 1;
               wait(period/2);
               (*motor_dir) = 1 - dir ;
               wait(period/2);
               count += 1;
        }}

      //overloaded method that will run both motors at once: one will run forward and backward, adn one will just run forward 

         
      void Stepper::TurnMotor(int runTime, Stepper motor1) {
           Timer t; 
           motor1.TurnMotor(runTime); 
           t.start(); 
           while (((int)t.read()) < runTime ) {
               (*motor) = 1;
          }
          t.stop();
          }
        
