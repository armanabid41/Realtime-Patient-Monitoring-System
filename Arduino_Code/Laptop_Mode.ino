// পিন কনফিগারেশন
const int pulsePin = A0; // পালস সেন্সর
const int tempPin = A1;  // টেম্পারেচার সেন্সর (LM35)

void setup() {
  Serial.begin(9600); // সিরিয়াল কমিউনিকেশন শুরু
}

void loop() {
  // --- পার্ট ১: টেম্পারেচার সেন্সর --
  // টেম্পারেচার সেন্সর খুব সেনসিটিভ, তাই আমরা ২০ বার রিডিং নিয়ে গড় করব
  float totalTemp = 0;
  for(int i = 0; i < 20; i++) {
    int tempRaw = analogRead(tempPin);
    // LM35 সূত্র: (Reading * 5.0V * 100) / 1024
    float tempC = (tempRaw * 5.0 * 100.0) / 1024.0;
    totalTemp += tempC;
    delay(2); // ছোট বিরতি
  }
  float stableTemp = totalTemp / 20.0; // গড় তাপমাত্রা


  // --- পার্ট ২: পালস সেন্সর (রিয়েল হার্টবিট) ---
  int pulseRaw = analogRead(pulsePin);

  
  Serial.print(pulseRaw);
  Serial.print(",");
  Serial.println(stableTemp); 

  delay(10); 
}
