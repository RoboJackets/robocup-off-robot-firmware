// Stepper class for a stepper motor to be used for the solenoid winder
class Stepper {
    private: 
        //Rotations per second for the motor 
        float rps; 
        //How many steps per revolution the motor makes, default is 200 
        int motorStepsPerRev; 
        //Factor of microstepping, default is 1 with no microstepping 
        int microstepFactor; 
        
        //Objects of DigitalOut class to control motor motion and direction
        DigitalOut* motor; 
        DigitalOut* motor_dir; 
        
        // Method returns the period in seconds
        float rpsToPeriod();  
   
    public: 
        // public direction 
        int dir; 
        // Constructor for stepper motor 
        Stepper(float rps, PinName pwmPin, PinName digitalPin, int microstepFactor = 1, int motorStepsPerRev = 200, int dir = 0 ); 
        
        // Getter and setter for rps 
        void setRPS(float rps) {this-> rps = rps; }
        float getRPS() {return rps; }

        // Getter and setter for motorStepsPerRev
        void setMotorStepsPerRev(int motorStepsPerRev) {this-> motorStepsPerRev = motorStepsPerRev; }
        int getmotorStepsPerRev() {return motorStepsPerRev; }
        
        // Method reverses the direction of the motor after given waitTime in seconds
        void reverseMotor(int waitTime);
        
        // Method turns motor in a certain direction (default is 0) for a given runTime in seconds
        void TurnMotor(int runTime, int dir = 0); 
    
       
        } ; 