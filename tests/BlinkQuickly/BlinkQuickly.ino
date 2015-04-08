
void setup() {
  pinMode(13, OUTPUT);
  blinkQuickly();
}

void blinkQuickly() {
  for (int i=0; i<=19; i++) {
    digitalWrite(13, HIGH); 
    delay(100);   
    digitalWrite(13, LOW);   
    delay(400);     
  } 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH); 
  delay(300);   
  digitalWrite(13, LOW);   
  delay(1200);     
}
