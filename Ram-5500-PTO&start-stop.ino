int STOPPin=8;
int STARTPin=4;
int buttonPin=12;
int buttonRead;
int dt=250;
int dstop=1900;
int dstart=200;
int LEDState=0;
int buttonNew;
int buttonOld=0;


void setup() {
  // put your setup code here, to run once:
pinMode(STARTPin, OUTPUT);
pinMode(STOPPin, OUTPUT);
pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(STOPPin, LOW);
digitalWrite(STARTPin, LOW);
buttonNew=digitalRead(buttonPin);

if(buttonOld==1 && buttonNew==0){
  if (LEDState==0) {
    digitalWrite(STOPPin, HIGH);
    delay(dstop);
    digitalWrite(STOPPin, LOW);


    LEDState=1;
  }
  else{
    digitalWrite(STARTPin, HIGH);
    delay(dstart);
    digitalWrite(STARTPin, LOW);

    LEDState=0;
  }
}
buttonOld=buttonNew;
delay(dt);
}