// the idea of the code is to get data from the movement of a ball as it passes four sensors.
// the code intends to get the time the ball passes by every sensor, including when it comes in and out of it.
// it also calculates the mean speed, and potentially could calculate the acceleration, and net force acting on it

// max speed the ball can reach is ~6m/s. for an spacing of 5cm between sensors it will take <8.333ms for the ball to reach the next sensor.
// with 10μs periods, the percent error would be 0.036.

const double r_sensors = 0.1905; //distance between sensors (m)
const double mass_ball = 45.93 * (10 ^ -3); // mass of the golf ball (kg)

const int sensor1 = 3; //TX -> sensor 1
const int sensor2 = 2; //RX -> sensor 2
const int sensor3 = 0; //SDA -> sensor 3
const int sensor4 = 1; //SCL -> sensor 4

unsigned long time_sensor[4]; //time sensor was triggered (μs)
int j;
double mean_velocity;
boolean passAllSensors[] = {false, false, false, false};

void setup() {
  Serial.begin(115200);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);

  attachInterrupt(digitalPinToInterrupt(sensor1), interrupt1, FALLING);
  attachInterrupt(digitalPinToInterrupt(sensor2), interrupt2, FALLING);
  attachInterrupt(digitalPinToInterrupt(sensor3), interrupt3, FALLING);
  attachInterrupt(digitalPinToInterrupt(sensor4), interrupt4, FALLING);
}

// reading sensors and saving times ball passes
void loop() {
  if (passAllSensors[0] && passAllSensors[1] && passAllSensors[2] && passAllSensors[3] ) {
    calculations();
  }
}
// an interrupt for each sensor
void interrupt1 () {
  noInterrupts();
  time_sensor[0] = micros();
  passAllSensors[0] = true;
  interrupts();
}
void interrupt2 () {
  noInterrupts();
  time_sensor[1] = micros();
  passAllSensors[1] = true;
  interrupts();
}
void interrupt3 () {
  noInterrupts();
  time_sensor[2] = micros();
  passAllSensors[2] = true;
  interrupts();
}
void interrupt4 () {
  noInterrupts();
  time_sensor[3] = micros();
  passAllSensors[3] = true;
  interrupts();
}

// calculating variables
void calculations() {
  mean_velocity = 0.0;

  for (j = 0; j < 3; j++) {
    mean_velocity += r_sensors / (0.000001 * (time_sensor[j + 1] - time_sensor[j]));
  }

  mean_velocity /= 3;

  Serial.print("Mean speed (m/s): ");
  Serial.println(mean_velocity, 4);
  memset(passAllSensors, 0, sizeof(passAllSensors));
}
