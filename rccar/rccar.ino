int trigPin = 11;  // Trigger
int echoPin = 12;  // Echo
long duration, cm, inches;

int mot1in1Pin = 2, mot1in2Pin = 3, mot2in1Pin = 6, mot2in2Pin = 7;
int redPin=8;
int greenPin=9;
int bluePin=10;
int speedPin=5;
int direction =1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(mot1in1Pin, OUTPUT);
  pinMode(mot1in2Pin, OUTPUT);
  pinMode(mot2in1Pin, OUTPUT);
  pinMode(mot2in2Pin, OUTPUT);
  pinMode(mot1in2Pin, OUTPUT);
  pinMode(mot2in1Pin, OUTPUT);
  pinMode(mot2in2Pin, OUTPUT);
   pinMode(speedPin, OUTPUT);
}

void stop() {
  Serial.println("Stopping...");
  digitalWrite(mot1in1Pin, LOW);
  digitalWrite(mot1in2Pin, LOW);
  digitalWrite(mot2in1Pin, LOW);
  digitalWrite(mot2in2Pin, LOW);
  turnOnRed();
}

void forward() {
  direction =1;
  digitalWrite(mot1in1Pin, LOW);
  digitalWrite(mot1in2Pin, HIGH);
  digitalWrite(mot2in1Pin, LOW);
  digitalWrite(mot2in2Pin, HIGH);
  turnOnGreen();
}

void reverse() {
  direction=-1;
  digitalWrite(mot1in1Pin, HIGH);
  digitalWrite(mot1in2Pin, LOW);
  digitalWrite(mot2in1Pin, HIGH);
  digitalWrite(mot2in2Pin, LOW);
  turnOnBlue();
}

int getDistanceInCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;  // Divide by 29.1 or multiply by 0.0343
    // Serial.print(inches);
  // Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  return cm;
}
void  turnOnGreen(){
digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
}
void  turnOnRed(){
digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}
void  turnOnBlue(){
digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:

  // inches = (duration / 2) / 74;  // Divide by 74 or multiply by 0.0135

  cm = getDistanceInCm();
  analogWrite(speedPin, 130);
  if (cm < 50) {
    if(direction== 1){
    stop();
    delay(1000);
    }
    reverse();
    // delay(1000);
  } else {
    forward();
 
  }


  delay(100);
}
