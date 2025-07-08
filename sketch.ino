// Pin Definitions
const int relayPin = 13;   // Pin to control the relay
const int buzzerPin = 12;  // Pin for the Buzzer
const int eyeBlinkPin = 3; // Digital output pin from the eye blink sensor

void setup() {
  // Set up relay and buzzer as outputs
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Set up eye blink sensor pin as input
  pinMode(eyeBlinkPin, INPUT);

  // Start with the relay and buzzer OFF
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // Read the state of the eye blink sensor
  int eyeBlinkState = digitalRead(eyeBlinkPin);

  // Check if the person is asleep (eyeBlinkState == HIGH means eyes are closed)
  if (eyeBlinkState == HIGH) {
    // Activate the relay (cut power to the motor)
    digitalWrite(relayPin, HIGH);

    // Turn ON the buzzer
    digitalWrite(buzzerPin, HIGH);

    // Keep the buzzer ON for 5 seconds
    delay(5);

    // After 5 seconds, turn off the buzzer, but keep the motor off
    digitalWrite(buzzerPin, LOW);
  } else {
    // Deactivate the relay (power goes to the motor, motor runs)
    digitalWrite(relayPin, LOW);

    // Ensure the buzzer remains off
    digitalWrite(buzzerPin, LOW);
  }
}
