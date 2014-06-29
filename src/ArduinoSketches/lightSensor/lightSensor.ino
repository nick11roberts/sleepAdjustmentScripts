/*   ---------------
 *   lightSensor.ino
 *   ---------------
 * 
 *   
 *   Nicholas Roberts
 *
 *   This file reads data from a photoresistor connected to an Arduino
 *   and prints it to the serial port. 
 *
 *   Slightly modified from http://arduinobasics.blogspot.com/2011/06/arduino-uno-photocell-sensing-light.html
 * 
 *   Happy Arduino-ing! 
 */


// Initialize relevant variables
int photoRPin = 0; 
int minLight;
int maxLight;
int lightAmt;
int percentageLightLevel;

void setup() {
  
  Serial.begin(9600);
  
  // Set relevant variables
  lightAmt=analogRead(photoRPin);
  minLight=lightAmt-20;
  maxLight=lightAmt;
  
} // END setup

void loop(){
  
  // manage the mins and maxes
  lightAmt=analogRead(photoRPin);
  
  if( minLight >= lightAmt-1 ){
    minLight=lightAmt;
  } // END if
  
  if( maxLight <= lightAmt-1 ){
    maxLight=lightAmt;
  } // END if
  
  // Convert to a percentage
  percentageLightLevel = map(lightAmt, minLight, maxLight, 0, 100); 
  
  // Send the stuff to the serial port
  Serial.println(percentageLightLevel);
  
  // add a 15 second delay (four times per minute)
  delay(15000);
  
} // END void loop()


