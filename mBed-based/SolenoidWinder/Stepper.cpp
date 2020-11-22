 #include "mbed.h"
 #include "Stepper.h"
 
 // Stepper constructor 
 
    Stepper::Stepper(float rps, PinName pwmPin, PinName digitalPin, int microstepFactor, int motorStepsPerRev, int dir) {
            this-> rps = rps; 
            this-> motorStepsPerRev = motorStepsPerRev; 
            this -> microstepFactor = microstepFactor; 
            motor = new DigitalOut (pwmPin); 
            motor_dir = new DigitalOut (digitalPin);
            this-> dir = dir;  
             
            } 
    
    // Method returns the period in seconds 
    float Stepper::rpsToPeriod () {
            float period; 
            float steps; 
            steps = rps * motorStepsPerRev * microstepFactor; 
            period = (1/(steps)); 
            return period ; } 
            
    // Method reverses direction of motor 
    void Stepper::reverseMotor(int runTime) {
        int period = rpsToPeriod(); 
        dir = 1 - dir ; 
        TurnMotor(runTime, dir); } 
   
    // Method turns motor in one direction for some runtime, and then in the other direction for half the runTime 
    void Stepper::TurnMotor(int runTime, int dir) {
           float period = rpsToPeriod();
           float numIter = runTime / period ; 
           (*motor_dir) = dir; 
           int count = 0 ; 
           while (count < int(numIter)) {
               (*motor) = 1;
               wait(period/2); 
               (*motor) = 0 ; 
               wait(period/2); 
               count += 1;   
        }}