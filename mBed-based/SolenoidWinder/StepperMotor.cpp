#include "mbed.h"
// Solenoid Winder, Robocup 


// Class for a stepper motor 
class stepper {
    public: 
        PwmOut motor(p21); 
        DigitalOut motor_dir(p22);  
        float rps; 
        int motorStepsPerRev; 
        // Constructor 
        stepper(float y, int z) {
            rps = y; 
            motorStepsPerRev = z; 
            } 
        
        // Function returns the period in milliseconds 
        int rpsToPeriod (float rps, int motorStepsPerRev) {
            float period; 
            float steps; 
            steps = rps * motorStepsPerRev; 
            period = (1/(steps)) * 1000; 
            return int(period); } 
       
       // Function reverses the direction of the motor after given waitTime in seconds  
       void reverseMotor(int waitTime) {
           int period = rpsToPeriod(rps, motorStepsPerRev);
           motor.write(0.5f);
           while (1) {
               wait(waitTime); 
               motor_dir = !motor_dir; 
               }
           
        }  
      
};

int main() {
    
        stepper Motor1(50 , 200);  
        Motor1.rpsToPeriod(50, 200);
        Motor1.reverseMotor(0.2);

    
    }

