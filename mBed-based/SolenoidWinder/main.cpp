#include "mbed.h"
#include "Stepper.h"

int main() {
    
        Stepper Motor1(0.25, p22, p21, 32);  
        Stepper Motor2(0.25, p23, p24, 32); 
        Motor2.TurnMotor(100, Motor1);
     } 

