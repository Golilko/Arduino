
int tn = 0;
int potPin = A0;
int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int rotation = analogRead(potPin);
  int brig = rotation/4;
  analogWrite(ledPin, brig);
  Serial.println(brig);
  if(millis() - tn > 1){
    tn = 1;
  }
}
