// Stepper class for a stepper motor to be used for the solenoid winder
class Stepper {
    private:
        //Rotations per second for the motor
        float rps;
        //How many steps per revolution the motor makes, default is 200
        int motorStepsPerRev;
        //Factor of microstepping, default is 1 with no microstepping
        int microstepFactor;
        // default direction 
        int dir;

        //Objects of DigitalOut class to control motor motion and direction
        DigitalOut* motor;
        DigitalOut* motor_dir;
        
        // Method returns the period in seconds
        float rpsToPeriod();
        
        

    public:
        
        // Constructor for stepper motor
        Stepper(float rps, PinName speedPin, PinName dirPin, int microstepFactor = 1, int motorStepsPerRev = 200, int dir = 0 );


        // Getter and setter for rps
        void setRPS(float rps) {this-> rps = rps; }
        float getRPS() {return rps; }

        // Getter for motorStepsPerRev
        int getmotorStepsPerRev() {return motorStepsPerRev; }

         // Getter for microstepFactor
        int getMicrostepFactor() {return microstepFactor;} 
        
        // Getter and setter for direction 
        void setDir(int dir) {this-> dir = dir;} 
        int getDir() {return dir;} 

        // Method reverses the direction of the motor after given runTime in seconds
        void reverseMotor(float runTime);

        // Method turns motor in a certain direction (default is 0) for a given runTime in seconds
        void turnMotor(float runTime); 


        } ;

