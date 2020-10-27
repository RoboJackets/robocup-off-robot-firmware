 #include "mbed.h"
 #include "Stepper.h"
 
 // Stepper constructor 
 
    Stepper::Stepper(float rps, int motorStepsPerRev, PinName pwmPin, PinName digitalPin) {
            this-> rps = rps; 
            this->motorStepsPerRev = motorStepsPerRev; 
            this-> pwmPin = pwmPin; 
            this-> digitalPin = digitalPin; 
            } 
    
    // Method returns the period in milliseconds 
    float Stepper::rpsToPeriod () {
            float period; 
            float steps; 
            steps = rps * motorStepsPerRev; 
            period = (1/(steps))/ 32; 
            return period ; } 
    
    void Stepper::reverseMotor(int waitTime) {
           PwmOut motor(pwmPin); 
           DigitalOut motor_dir(digitalPin);
           int period = rpsToPeriod();
           motor.write(0.5f);
           while (1) {
               wait(waitTime); 
               motor_dir = !motor_dir; 
            } } 
   
    void Stepper::turnMotor(int waitTime) {
           PwmOut motor(pwmPin); 
           DigitalOut motor_dir(digitalPin);
           float period = rpsToPeriod();
           motor.period(period); 
           motor.write(0.5f);
           while (1) {
               wait(waitTime); 
               motor_dir = 0; } 
        }
        