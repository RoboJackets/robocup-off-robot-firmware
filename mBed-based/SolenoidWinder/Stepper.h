// Stepper class for a stepper motor to be used for the solenoid winder
class Stepper {
    private: 
        //Pin connected to PwmOut 
        PinName pwmPin; 
        //Pin connected to DigitalOut 
        PinName digitalPin;   
        //Rotations per second for the motor 
        float rps; 
        //How many steps per revolution the motor makes 
        int motorStepsPerRev; 
        
        // Method returns the period in seconds
        float rpsToPeriod();  
   
    public: 
        // Constructor for stepper motor 
        Stepper(float rps, int motorStepsPerRev, PinName pwmPin, PinName digitalPin); 
        
        // Getter and setter for the PwmOut Pin 
        void setPwmPin(PinName pin) {pwmPin = pin;}
        PinName getPwmPin(){return pwmPin;}
        
        //Getter and setter for the DigitalOut Pin 
        void setDigitalPin(PinName pin) {digitalPin = pin; }
        PinName getDigitalPin(){return digitalPin;}

        // Getter and setter for rps 
        void setRPS(float rps) {this-> rps = rps; }
        float getRPS() {return rps; }

        // Getter and setter for motorStepsPerRev
        void setMotorStepsPerRev(int motorStepsPerRev) {this-> motorStepsPerRev = motorStepsPerRev; }
        int getmotorStepsPerRev() {return motorStepsPerRev; }
        
        // Method reverses the direction of the motor after given waitTime in seconds
        void reverseMotor(int waitTime);
        
        void turnMotor(int waitTime); 
    
       
        } ; 