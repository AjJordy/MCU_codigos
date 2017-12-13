#define CS_PIN 15 // Use 10 when compiling for Arduino



void setup() {
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setFrequency(1000000); // 1 MHz -- remove line when running on Arduino UNO
  Serial.begin(9600);
  digitalWrite(CS_PIN, HIGH);
}

void loop() {
  Serial.println(adcRead(0));
  delay(50);
}

int adcRead(int channel) {
  if ((channel > 7) || (channel < 0)) {
    return -1;
  }
  
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(1);
  uint8_t r1 = SPI.transfer((channel + 8) << 4);
  uint8_t r2 = SPI.transfer(0);
  digitalWrite(CS_PIN, HIGH);

  return ((r1 & 3) << 8) + r2;
}
