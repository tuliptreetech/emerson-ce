const int ledPin = LED_BUILTIN;
bool enableDebounce = true;

int ledState = HIGH;
int buttonState = LOW;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 1;

const int numTests = 10;
const int arrSize = 24;

int testIndex = 0;
int readingIndex = 0;

int testData[numTests][arrSize] = {
  {0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0},
  {0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0},
  {0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0},

};
void setup() {
  Serial.begin(9600);

  Serial.print("Test: ");
  Serial.println(testIndex);
}

  
void loop() {
  if (readingIndex >= arrSize) {
    readingIndex = 0;  // Restart from the beginning
    testIndex = (testIndex + 1) % numTests;  // Move to next test case
    Serial.print("Test: ");
    Serial.println(testIndex);

  }

  int reading = testData[testIndex][readingIndex];

  if (enableDebounce) {
    // If the button state changed due to noise or pressing
    if (reading != lastButtonState) {
      lastDebounceTime = millis(); // Reset debounce timer
    }
    // If the reading has been stable for the debounce delay, accept it
    if ((millis() - lastDebounceTime) >= debounceDelay) {
      // If the debounced state has changed
      if (reading != buttonState) {
        buttonState = reading;
        if (buttonState == HIGH) {
          ledState = !ledState;
          digitalWrite(ledPin, ledState);
        }
        Serial.println(buttonState == HIGH ? "Pressed" : "Released");
      }
    }
  //if debounce is not enabled
  } else {
      if (reading != buttonState) {
        buttonState = reading;
      }
      if (buttonState == HIGH) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
      Serial.println(buttonState == HIGH ? "Pressed (No Debounce)" : "Released (No Debounce)");
    }
  // Save the current reading as the last state
  lastButtonState = reading;
  // Move to next reading
  readingIndex++;

  delay(1);
}