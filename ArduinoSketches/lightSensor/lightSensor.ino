int photoRPin = 0; 
int minLight;
int maxLight;
int lightAmt;
int percentageLightLevel;

void setup() {
 Serial.begin(9600);
 
 //Setup the starting light level limits
 lightAmt=analogRead(photoRPin);
 minLight=lightAmt-20;
 maxLight=lightAmt;
}

void loop(){
 //auto-adjust the minimum and maximum limits in real time
 lightLevel=analogRead(photoRPin);
 if(minLight>lightAmt){
 minLight=lightAmt;
 }
 if(maxLight<lightAmt){
 maxLight=lightAmt;
 }
 
 //Adjust the light level to produce a result between 0 and 100.
 percentageLightLevel = map(lightAmt, minLight, maxLight, 0, 100); 
 
 //Send the adjusted Light level result to Serial port (processing)
 Serial.println(percentageLightLevel);
 
 //slow down the transmission for effective Serial communication.
 delay(50);
}
