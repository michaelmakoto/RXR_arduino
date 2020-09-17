int sensorValue = 0;
float voltage = 0.0;
int time = 0;
int ledPins[] = {6,5,4,3};
int readPin = A5;
int totalLed = 0;
int selectLed = 0;

void setup()
{
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(readPin, INPUT);

  //enable pins in ledPins
  int i = 0;
  while(ledPins[i]!= NULL){
  	pinMode(i, OUTPUT);
    i++;
  }

  //calculate the amount of leds to use
  totalLed = sizeof(ledPins)/ sizeof(ledPins[0]);
}
void loop()
{
  int tmp;
  // adjust the potentiometer to change the delay
  // read the value from the sensor
  sensorValue = analogRead(readPin);
  // map voltage 0-1023 to 50ms - 300ms
  time = map(sensorValue,0,1023,50,300);

  // example: 1023 250 (sec)
  // for serial monitor
  Serial.print(sensorValue);
  Serial.print("-> ");
  Serial.print(time);
  Serial.print(" (ms)");
  Serial.print("\t");

  tmp = random(0,totalLed);
  selectLed = ledPins[tmp];

  Serial.print("Pin:");
  Serial.print(selectLed);
  Serial.print("\n");

  digitalWrite(selectLed, HIGH);
  delay(time);
  digitalWrite(selectLed, LOW);
  delay(time);
  // make sure it goes off
  delay(50);
}
