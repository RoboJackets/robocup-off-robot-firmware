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
    void Stepper::reverseMotor(float runTime) {
        int period = rpsToPeriod();
        dir = 1 - dir ;
        turnMotor(runTime); }

    // Method emulates the PWM by sending a tick for half the period, and then waiting another half period 
    // to send a tick, doing this for passed in runTime
    void Stepper::turnMotor(float runTime) {
           float period = rpsToPeriod();
           float numIter = runTime / period ;
           (*motor_dir) = dir;
           int count = 0 ;
           while (count < int(numIter)) {
               (*motor) = 1;
               wait(period/2);
               (*motor) = 0;
               wait(period/2);
               count += 1;
        }
     
    }
    
        
