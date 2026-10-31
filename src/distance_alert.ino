/*
  Ultrasonic Distance Alert System
  Hardware: Elegoo Uno R3, HC-SR04 Sensor, Passive Buzzer
  
  Connections:
    - HC-SR04 VCC -> 5V, GND -> GND, Trig -> Pin 9, Echo -> Pin 8
    - Passive Buzzer -> Pin 7 and GND
*/

const int TRIG_PIN = 9;
const int ECHO_PIN = 8;
const int BUZZER_PIN = 7;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Ultrasonic Distance Alert System Initialized.");
}

void loop() {
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send a 10-microsecond high pulse to trigger the sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo pin pulse duration in microseconds
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance in centimeters (speed of sound = 0.0343 cm/us, divided by 2)
  float distanceCm = duration * 0.0343 / 2.0;

  // Print results and handle proximity alerts
  if (duration == 0) {
    Serial.println("Warning: No echo received! Check wiring.");
  } else {
    Serial.print("Distance: ");
    Serial.print(distanceCm, 1);
    Serial.println(" cm");

    // Proximity Alert Logic using the Passive Buzzer
    if (distanceCm > 0 && distanceCm < 10) {
      // Danger zone: Rapid high-pitched beep (< 10 cm)
      tone(BUZZER_PIN, 2500);
      delay(50);
      noTone(BUZZER_PIN);
      delay(50);
    } 
    else if (distanceCm >= 10 && distanceCm < 25) {
      // Caution zone: Slower, lower-pitched beep (10 to 25 cm)
      tone(BUZZER_PIN, 1500);
      delay(100);
      noTone(BUZZER_PIN);
      delay(200);
    } else {
      // Safe zone: Silence buzzer (> 25 cm)
      noTone(BUZZER_PIN);
    }
  }

  delay(200); // Sampling interval
}
