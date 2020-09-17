int l,r;
int forwardR = 9;
int backwardR = 8;
int forwardL = 4;
int backwardL = 5;
int sensorR = 3;
int sensorL = 2;

void setup()
{
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(forwardR,OUTPUT);
  pinMode(backwardR,OUTPUT);
  pinMode(forwardL,OUTPUT);
  pinMode(backwardL,OUTPUT);
  pinMode(sensorR,INPUT);
  pinMode(sensorL,INPUT);
}
void loop()
{
  r=digitalRead(sensorR);
  l=digitalRead(sensorL);
  Serial.print(r);
  Serial.print(" -- ");
  Serial.print(l);
  Serial.print("\n");

  if(r==HIGH && l==HIGH)
  {
    // drive forward
    drive(HIGH,LOW,HIGH,LOW);
  }
  else if(r==HIGH && l==LOW)
  {
    // drive to the right
    drive(HIGH,LOW,HIGH,HIGH);
  }
  else if(r==LOW && l==HIGH)
  {
   	// drive to the left
    drive(HIGH,HIGH,HIGH,LOW);
  }
  else if(r==LOW && l==LOW)
  {
    // if the robot is on a black surface, full stop
    drive(HIGH,HIGH,HIGH,HIGH);
  }
  delay(100);
}

void drive(int FR, int BR, int FL, int BL){
  digitalWrite(forwardR,FR);
  digitalWrite(backwardR,BR);
  digitalWrite(forwardL,FL);
  digitalWrite(backwardL,BL);
}