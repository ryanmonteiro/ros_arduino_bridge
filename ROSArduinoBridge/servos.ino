/***************************************************************
   Servo Sweep - by Nathaniel Gallinger

   Sweep servos one degree step at a time with a user defined
   delay in between steps.  Supports changing direction 
   mid-sweep.  Important for applications such as robotic arms
   where the stock servo speed is too fast for the strength
   of your system.

 *************************************************************/

#ifdef USE_SERVOS

Sweeper::Sweeper(){
  this->currentPosition = 0;
  this->targetPosition = 0;
  this->increment = 1;
  this->lastUpdate = 0;
}

void Sweeper::initServo(int servoPin, int servoDelay, int servoInit){
  this->servo.attach(servoPin);
  this->updateInterval = servoDelay;
  this->currentPosition = servoInit;
  this->targetPosition = servoInit;
}

void Sweeper::detachServo(){
  this->servo.detach();
}

void Sweeper::doSweep(){
  if ((millis() - this->lastUpdate) > this->updateInterval)   //Time to update
  {
    this->lastUpdate = millis();
    this->currentPosition += this->increment;
    this->servo.write(this->currentPosition);
    if ((this->currentPosition >= 180) || (this->currentPosition <= 0)) // end of sweep
    {
      //reverse direction
      this->increment = -this->increment;
    }
  } 
}

void Sweeper::setTargetPosition(int position){
  this->currentPosition = position;
  this->servo.write(this->currentPosition);
}

Servo Sweeper::getServo(){
  return this->servo;
}

#endif
