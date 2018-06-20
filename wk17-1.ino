const byte intPin=2;
const byte ledPin=13;
boolean state =LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
pinMode(intPin,INPUT);
digitalWrite(ledPin,state);
attachInterrupt(0,int0,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledPin,state);
}
void int0(){
state=!state;
}

