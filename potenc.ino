
int tn = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensRead = analogRead(A0);
  float sensVal = ((float)sensRead/10.23);
  Serial.println(sensVal);
  if(millis() - tn > 1){
    tn = 1;
  }
}
