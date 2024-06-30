#ifndef SENSORS_H
#define SENSORS_H

//Definição dos endereços dos sensores VL53L0X. Endereço padrão: 0b0101001 ou 41.
#define Sensor1_endereco 42

const int distanciaMin = 0; //Distância mínima de detecção do VL53L0X.
const int distanciaMax = 1200; //Distância máxima de detecção do VL53L0X.

// Variáveis de controle:
boolean detectado = false;
byte signalState = LOW;

void initLaserSensors();
int readLaserSensors();
 
/* Functions for various sensor types */

float microsecondsToCm(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per cm.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long Ping(int pin) {
  long duration, range;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pin, INPUT);
  duration = pulseIn(pin, HIGH);

  // convert the time into meters
  range = microsecondsToCm(duration);
  
  return(range);
}
#endif