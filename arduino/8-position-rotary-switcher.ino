#define POSITION A2

const int threshold = 10;
byte lastPin = 0xAA;
const int selectPins[3] = {0, 1, 2}; // S-pins to Arduino pins: S0~2, S1~3, S2~4

void setup() {
  pinMode(POSITION, INPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  int position = analogRead(POSITION);

  // The following lines work for 8 positions
  const int totalPositions = 8;
  const int expectedValues[] = {1024, 929, 770, 603, 432, 263, 96, 0};
  
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

  for (int i=0; i<3; i++) {
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}

