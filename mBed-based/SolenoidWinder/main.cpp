#include "mbed.h"
#include "Stepper.h"

int main() {
    
        Stepper Motor1(0.25, 200, p21, p22);  
        Motor1.turnMotor(100);
     } 

