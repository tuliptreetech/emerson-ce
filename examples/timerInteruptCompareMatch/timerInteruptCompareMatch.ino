void setup() {
  Serial.begin(9600);
  
  noInterrupts();                   
  TCCR1A = 0;
  TCCR1B = (1 << WGM12) | (1 << CS12);  // CTC mode, prescaler 256
  TIMSK1 |= (1 << OCIE1A);  // Enable Timer1 Compare Match A
  OCR1A = 625;
  interrupts();
}

//Trigger ISR though Compare Match
ISR(TIMER1_COMPA_vect) {
  Serial.println("Hello World!");
}

void loop() {}