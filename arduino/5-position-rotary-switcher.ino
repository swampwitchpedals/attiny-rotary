#define POSITION A0

byte lastPin = 0xAA;
const int threshold = 10;
const int selectPins[3] = {A13, A14, A15}; // S-pins to Arduino pins: S0~2, S1~3, S2~4

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600); // uncomment to debug
  pinMode(POSITION, INPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A15, OUTPUT);
}

void loop() {

  int position = analogRead(POSITION);

  // The following line works for 5 positions)
  const int totalPositions = 5;
  const int expectedValues[] = {985, 767, 493, 220, 0};
  
  for (int i = 0; i < totalPositions; i++) {
    if (evaluatePosition(position, expectedValues[i], threshold)) {
      selectMuxPin(totalPositions - 1 - i);    
      break;
    }
  }
}

// Returns true if the expected position is within 1 of the given value
bool evaluatePosition(int position, int expectedValue, int threshold) {
  if (expectedValue == 0 && position == 0) {
    return true;
  }

  return (expectedValue <= (position + threshold) && 
      expectedValue >= (position - threshold));
}
// The selectMuxPin function sets the S0, S1, and S2 pins to select the give pin
void selectMuxPin(byte pin) {
  if (pin == lastPin) return; // Exit if we have already set this pin
  if (pin > 7) return; // Exit if pin is out of scope
  lastPin = pin;

  Serial.print("Selecting a pin: ");
  Serial.println(pin);

  for (int i=0; i<3; i++) {
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}

