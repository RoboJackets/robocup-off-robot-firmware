#include "mbed.h"
#include "Stepper.h"
#include "PinDetect.h"

PinDetect pin(p28);

bool dir = 0;

void keyReleased(){
    dir = !dir;     
}

int main() {

     pin.attach_deasserted(&keyReleased);

 
     // Sampling does not begin until you set a frequency.
     // The default is 20ms. If you want a different frequency
     // then pass the period in microseconds for example, for 10ms :-
     //     pin.setSampleFrequency( 10000 );
     //
     pin.setSampleFrequency(); // Defaults to 20ms.
    
        Stepper motor1 (0.20, p22, p21, 32);
        Stepper motor2 (0.4, p23, p24, 32); 
        
        // 1000 iterations of 0.1 seconds for Motor 2 
        int count = 0;
        while (count < 5000) {
            
            motor2.turnMotor(0.1);
            motor2.setDir(dir);
            motor1.turnMotor(0.1);
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
