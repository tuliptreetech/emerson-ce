void setup() {
  Serial.begin(9600);
  
  noInterrupts();                 
  TCCR1A = 0;
  TCCR1B = (1 << CS10);  // Prescaler = 1
  TIMSK1 |= (1 << TOIE1); // Enable overflow interrupt
  TCNT1 = 65000; //This is to speed up emulation. Comment this out when wanting to upload to hardware
  interrupts();
}

//Trigger ISR through Overflow
ISR(TIMER1_OVF_vect) {
  Serial.println("Hello World!: Overflow ISR");
  TCNT1 = 65000;
}

void loop() {}