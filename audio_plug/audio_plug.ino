/*
 Lucas Dahl
 Audio_Plug code which takes the input for 5 switches and 3 audio cable plugs which when all is activated sends a signal to the 60 min timer
 
 */

int sensorcenter = A4; //The middle audio cable
int sensortop = A5; //The top audio cable
int sensorbottom = A3; //the bottom audio cable
int sensorswitch = A2;// The switch
//When voltage is applied to the audio cables there is interference with the rest of the circuit so to make sure that the voltage for the cables are the voltages tested
//I connected the other end of the audio cables to the outbottom, outcenter, and out top.
int outbottom = 2; 
int outcenter = 3;
int outtop = 4;
//same for the switch, and I have it set so they have different voltages to try to eliminate the interference
int outswitch = 5;
//The recorded values for each of the sensors
int sensorValuec = 0; 
int sensorValueb = 0;
int sensorValues = 0;
int sensorValuet = 0;
int ledPin = 13;// variable to store the value coming from the sensor

int cent = 0;
int bot = 0;
int top = 0;
int swit = 0;

void setup() {
  // declare the pwm as an OUTPUT:
  pinMode(outbottom, OUTPUT);  
  pinMode(outcenter, OUTPUT);
  pinMode(outtop, OUTPUT);
  pinMode(outswitch, OUTPUT); 
  pinMode(ledPin, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  digitalWrite(outcenter, HIGH);
  sensorValuec = analogRead(sensorcenter); 
  if( sensorValuec > 1000)
  {
   cent = 1; 
  }  
  else
  {
   cent = 0; 
  }
  digitalWrite(outcenter, LOW);

  digitalWrite(outbottom, HIGH);
  sensorValueb = analogRead(sensorbottom); 
  //Serial.println(sensorValueb);
  if( sensorValueb > 1000)
  {
   bot = 1; 
  }  
  else
  {
   bot = 0; 
  }
  digitalWrite(outbottom, LOW);


  digitalWrite(outswitch, HIGH);
  sensorValues = analogRead(sensorswitch); 
  Serial.println(sensorValues);
  if( sensorValues > 1000)
  {
   swit = 1; 
   digitalWrite(12, HIGH);

  }  
  else
  {
    digitalWrite(12, LOW );

   swit = 0; 
  }
  digitalWrite(outswitch, LOW);
 
  digitalWrite(outtop, HIGH);
  sensorValuet = analogRead(sensortop);   
  Serial.println(sensorValuet);
  if( sensorValuet > 1000)
  {
   top = 1; 
  }  
  else
  {
   top = 0; 
  }
  digitalWrite(outtop, LOW);
  digitalWrite(outbottom, LOW);
  digitalWrite(outcenter, LOW);
  
  if(top == 1 && bot ==1 && cent ==1)
  {
  digitalWrite(ledPin, HIGH); 
  delay(100);
  if(swit ==1)
  {
   digitalWrite(7, HIGH); 
  }
  else{
    digitalWrite(7, LOW);
    delay(1000);
  }
  }
 else
{
 //Serial.println(top);
 
  digitalWrite(ledPin, LOW);
  delay(100);
                 
}

}
