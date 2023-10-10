// Pin configurations
const int potPin = A0;    // Analog pin for the potentiometer
const int buttonPin = 2;  // Digital pin for the button
const int redPin = 9;     // PWM pin for the red color of the RGB LED
const int greenPin = 10;  // PWM pin for the green color of the RGB LED
const int bluePin = 11;   // PWM pin for the blue color of the RGB LED

int potValue = 0;        // Variable to store potentiometer value
int buttonState = HIGH;   // Variable to store button state
int lastButtonState = HIGH;  // Variable to store the previous button state

int colorMode = 0;  // 0: Red, 1: Green, 2: Blue

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Initialize button pin as input with internal pull-up resistor
  pinMode(redPin, OUTPUT);           // Initialize redPin as an output
  pinMode(greenPin, OUTPUT);         // Initialize greenPin as an output
  pinMode(bluePin, OUTPUT);          // Initialize bluePin as an output
  Serial.begin(9600);                // Initialize serial communication at 9600 bits per second
}

void loop() {
  // Read the potentiometer value
  potValue = analogRead(potPin);
  
  // Map the potentiometer value to the range of 0-255 (brightness range)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Check if the button is pressed
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    // Button was pressed, cycle to the next color mode
    colorMode = (colorMode + 1) % 3;
  }

  lastButtonState = buttonState;  // Update the last button state

  // Update the RGB LED based on the selected color mode
  switch (colorMode) {
    case 0:  // Red color
      analogWrite(redPin, brightness);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      break;
    case 1:  // Green color
      analogWrite(redPin, 0);
      analogWrite(greenPin, brightness);
      analogWrite(bluePin, 0);
      break;
    case 2:  // Blue color
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, brightness);
      break;
  }

  // Print potentiometer and color mode values to serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(", Color Mode: ");
  Serial.println(colorMode);

  delay(10);  // Small delay for stability
}