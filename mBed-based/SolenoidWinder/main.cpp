#include "mbed.h"
#include "Stepper.h"

int main() {
    
        Stepper motor1 (0.5, p22, p21, 32);
        Stepper motor2 (0.5, p23, p24, 32); 
        
        // 1000 iterations of 0.1 seconds for Motor 2 
        int count = 0;
        while (count < 1000) {
            
            motor2.turnMotor(0.1);
            count += 1; 
        }
        
        // 1000 iterations of 0.1 seconds for Motor 1 and Motor 2 
        /* count = 0;
        while (count < 1000) {
            motor1.turnMotor(0.1); 
            motor2.turnMotor(0.1);
            count += 1; 
        } */ 
    
     } 
