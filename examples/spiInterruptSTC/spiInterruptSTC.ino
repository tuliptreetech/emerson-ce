#include <SPI.h>

void setup() {
  Serial.begin(9600);
  SPI.begin();
  SPCR |= (1 << SPIE); // Enable SPI interrupt
}

//Trigger ISR when SPI Transfer Complete
ISR(SPI_STC_vect) {
  Serial.println("Hello World!: SPI Complete");
}

void loop() {
  SPI.transfer(0xFF); // Send test byte
  delay(1);
}