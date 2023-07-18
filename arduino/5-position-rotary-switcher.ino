#define POSITION A0
#define LED 13

const int selectPins[3] = {A13, A14, A15}; // S-pins to Arduino pins: S0~2, S1~3, S2~4
const int totalPositions = 5;

void setup() {
  pinMode(POSITION, INPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A15, OUTPUT);
}

void loop() {
  int position = analogRead(POSITION);
  float shiftedPosition = ((position >> 7) / 2.0); 
  int pin = ceil(shiftedPosition);
  selectMuxPin(pin);    
}


// The selectMuxPin function sets the S0, S1, and S2 pins to select the give pin
void selectMuxPin(byte pin) {
  if (pin > 7) return; // Exit if pin is out of scope
  for (int i=0; i<3; i++) {
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}
