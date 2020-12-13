#include "mbed.h"
#include "Stepper.h"

int main() {

        Stepper Motor1(0.25, p21, p22, 32);
        Motor1.TurnMotor(100);
     }
