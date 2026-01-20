const int pulsePin = A0;
const int tempPin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // টেম্পারেচার ক্যালকুলেশন
  float totalTemp = 0;
  for(int i = 0; i < 10; i++) {
    int tempRaw = analogRead(tempPin);
    float tempC = (tempRaw * 5.0 * 100.0) / 1024.0;
    totalTemp += tempC;
    delay(2);
  }
  float stableTemp = totalTemp / 10.0;
  int pulseRaw = analogRead(pulsePin);

  // RoboRemo ফরম্যাট
  Serial.print("P "); 
  Serial.println(pulseRaw);

  Serial.print("T ");
  Serial.println(stableTemp);

  // ডিলে বাড়িয়ে ১০০ করা হলো (আগে ৫০ ছিল)
  // এতে কানেকশন অনেক স্টেবল থাকবে
  delay(150); 
}