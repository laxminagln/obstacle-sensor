const int pingPin = 2; 
const int echoPin = 3; 
const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;
const int enA = 10;
const int enB = 11;
int duration, distance;

void setup() 
{
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
}

void Forward()
{
  analogWrite(enA,180);
  analogWrite(enB,180);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void Left()
{
  analogWrite(enA,180);
  analogWrite(enB,180);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

//void Right()
//{
  //analogWrite(enA,180);
 // analogWrite(enB,180);
 // digitalWrite(in1,LOW);
 // digitalWrite(in2,LOW);
//digitalWrite(in3,HIGH);
//digitalWrite(in4,LOW);
//}

void Stop()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void Readsensors()
{
   digitalWrite(pingPin, LOW);
   delay(2);
   digitalWrite(pingPin, HIGH);
   delay(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = duration / 29 / 2;
   Serial.println(distance);
   delay(100);
   if(distance<=20)
   { 
    delay(5);
    Left();
    delay(1500);    
   }
}

void loop() {
  Readsensors();
  Forward();
  delay(500);  
}
