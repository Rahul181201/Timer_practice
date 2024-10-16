void init_port(void);
void init_timer(void);
void setup() {
  volatile long i;
  int j=0;
  init_port();
  init_timer();
  Serial.begin(9600);
  while(1){
    for(i=0;i<500000;i++);
    Serial.println(j,DEC);
    j++;
  }
}
void init_port(){
  volatile char *dirf = (volatile char *)0x30;
  *dirf = 0x01;
}
void init_timer(){
  volatile char *Timer1_TIMSK1 = 0x6F;
  volatile char *Timer1_TCCR1A = 0x80;
  volatile char *Timer1_TCCR1B = 0x81;
  volatile short *Timer1_TCNT1 = 0x84;
  volatile short *Timer1_OCR1A = 0x88;

  *Timer1_TIMSK1 = 0x02;
  *Timer1_TCCR1A = 0;
  *Timer1_TCCR1B = 0x0C;
  *Timer1_TCNT1 = 0;
  *Timer1_OCR1A = 60000;
}
ISR(TIMER1_COMPA_vect){
  volatile char *outf = (volatile char *)0x31;
  *outf = *outf^0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}
