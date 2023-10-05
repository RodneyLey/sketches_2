// Define the digital pin for the pushbutton
int pushButton = 2;

// Variables to store button states
int previousButtonState = LOW; // Previous button state
int buttonState = LOW; // Current button state

// Variable to count button presses
int pressCount = 0;

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);

  // Set the pushbutton's pin as an input
  pinMode(pushButton, INPUT);
}

void loop() {
  // Read the current button state
  buttonState = digitalRead(pushButton);

  // Check for a button press (LOW to HIGH transition) with debounce
  if (buttonState == HIGH && previousButtonState == LOW) {
    delay(50); // Debounce delay to ignore noise
    buttonState = digitalRead(pushButton); // Read again

    // Check if the button is still pressed after debounce
    if (buttonState == HIGH) {
      // Button press detected
      pressCount++; // Increment press count
      Serial.print("You've pressed the button ");
      Serial.print(pressCount);
      Serial.println(" times");
    }
  }

  // Update previous button state
  previousButtonState = buttonState;
}
