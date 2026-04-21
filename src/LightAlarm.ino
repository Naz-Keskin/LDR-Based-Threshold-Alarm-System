// LDR-Based Logic Trigger (Threshold Alarm System)
// Author: Naz | TOBB ETU - Electrical and Electronics Engineering

// --- Hardware Pin Definitions ---
const int ldrPin = A0;      // Analog input pin for the LDR voltage divider
const int buzzerPin = 8;    // Digital output pin for the active buzzer

// --- System Parameters ---
// The specific ADC value at which the state changes from LOW to HIGH.
// Adjust this value (e.g., between 400 and 800) for calibration.
int alarmThreshold = 650; 

void setup() {
  pinMode(buzzerPin, OUTPUT); // Configure buzzer pin as output
  
  // Initialize serial communication for threshold calibration
  Serial.begin(9600);
}

void loop() {
  // 1. Sample Analog Data
  int lightLevel = analogRead(ldrPin);

  // 2. Debugging Output (Monitor real-time values vs setpoint)
  Serial.print("Current ADC: ");
  Serial.print(lightLevel);
  Serial.print(" | Threshold: ");
  Serial.println(alarmThreshold);

  // 3. Threshold Logic (Binary State Trigger)
  // IF the environment is darker than the set threshold...
  if (lightLevel > alarmThreshold) {
    // Generate a 1kHz (1000 Hz) square wave tone
    tone(buzzerPin, 1000); 
  } else {
    // Otherwise, ensure the buzzer is completely silenced
    noTone(buzzerPin);
  }

  // Polling delay for system stability
  delay(100); 
}
