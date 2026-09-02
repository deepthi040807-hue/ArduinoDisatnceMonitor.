// Define pins for HC-SR04
#define TRIG_PIN 9
#define ECHO_PIN 10
#define RedLed 7
#define GreenLed 6
long duration;
float distance;
void setup() {
 // Initialize serial communication
 Serial.begin(9600);
 // Configure pin modes
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 pinMode(RedLed, OUTPUT);
 pinMode(GreenLed, OUTPUT);
}
void loop() {
 // Ensure trigger pin is low
 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(5);
 // Send a 10µs pulse to trigger measurement
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN, LOW);
 // Measure the echo pulse duration
 duration = pulseIn(ECHO_PIN, HIGH);
 // Calculate distance in cm (speed of sound = 0.034 cm/µs)
 distance = (duration * 0.034) / 2;
 if (distance < 10.00){
  digitalWrite(RedLed, HIGH);
  digitalWrite(GreenLed, LOW);  
 }
 else {
  digitalWrite(RedLed, LOW);
  digitalWrite(GreenLed, HIGH);
 }
 // Print result to Serial Monitor
 Serial.print("Distance: ");
 Serial.print(distance);
 Serial.println(" cm");
 delay(500); // Wait before next reading
}
