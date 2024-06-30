#ifndef SERVOS_H
#define SERVOS_H

#define SERVO_PIN 3
#define SERVO_DELAY 150
#define SERVO_INIT 90 // Servo initial position (0 - 180)

class Sweeper
{
  private:
    Servo servo;                // The servo
    int currentPosition;        // Current servo position
    int targetPosition;         // Position to archieve
    int increment;              // Incremente to move for each interval
    int updateInterval;         // Interval between updates
    unsigned long lastUpdate;   // Last update of position
  
  public:
    Sweeper();
    void initServo(int servoPin, int servoDelay, int servoInit);
    void detachServo();
    void doSweep();
    void setTargetPosition(int position);
    Servo getServo();
};

Sweeper servo1;

#endif
