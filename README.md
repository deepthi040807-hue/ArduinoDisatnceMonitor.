# ArduinoDisatnceMonitor.
Distance Monitor (Arduino)
A simple embedded systems project built during my first-year engineering holiday, using an Arduino Uno kit. The system uses an ultrasonic sensor to measure how close the object is to the sensor, and lights up a Red or Green LED depending on the distance.

# What it does:

Continuously measures distance to the nearest object using an HC-SR04 ultrasonic sensor
Prints the live distance reading to the Serial Monitor
Lights up a Red LED if the distance is less than 10 cm (too close)
Lights up a Green LED otherwise (safe distance)

# Hardware used:
Arduino Uno R3
HC-SR04 Ultrasonic Distance Sensor
1x Red LED, 1x Green LED
2x resistors (one per LED)
Breadboard + jumper wires

# Wiring:
Ultrasonic sensor:
Sensor Pin          	Arduino Pin
VCC             	       5V
GND	                     GND
Trig           	        Pin 9
Echo	                  Pin 10

LEDs:
LED	Arduino Pin	Path:
(Red	Pin) 7	Pin → Resistor → LED(+) → LED(−) → GND
(Green	Pin) 6	Pin → Resistor → LED(+) → LED(−) → GND

# How it works:
The Trig pin sends a short ultrasonic pulse.
The pulse travels out, bounces off the nearest object, and returns to the Echo pin.
pulseIn() measures how long the Echo pin stayed HIGH — the round-trip travel time.
That time is converted into distance using the speed of sound, divided by 2 (since the pulse travels there and back):
   distance = (duration * 0.034) / 2;
Based on the distance, the code switches the LEDs on/off accordingly.

# Bugs I hit and fixed
0.00 cm reading: The ECHO_PIN in code didn't match the pin I'd actually wired the sensor's Echo pin to. Fixed by matching the code's pin number to the physical wiring.
LEDs not lighting up: The breadboard's ground rail wasn't connected back to the Arduino's GND pin, so the LED circuit had no return path. Fixed by wiring the breadboard ground rail directly to Arduino GND.


# Why I didn't add more sensors (yet):
The kit includes a thermistor (temperature) and photoresistor (light) sensor. I considered adding them next, but held off — a human doesn't need a sensor to notice a room is dark or hot, so bolting on more sensors that just report obvious conditions wouldn't make the project meaningfully better. More hardware isn't the same as a more interesting project.

# Where this is going next:
Instead of adding more sensors, the next step is making the system smarter about the data it already has:
Serial communication with Python — stream live sensor data from the Arduino to a Python script over serial, instead of just watching numbers in the Serial Monitor.
Logging real usage data — record distance readings over multiple study sessions to see actual patterns, not just instant reactions.
A lightweight decision-making layer — instead of a hardcoded threshold (distance < 15cm), use the logged data to inform smarter behavior — e.g. combining distance patterns over time into a judgment a simple if-statement wouldn't make, using a basic model (like a simple classifier in scikit-learn) trained on my own usage data.
The goal is to move this from "sensor triggers an LED" to a system that actually reasons about behavior over time — the part that separates it from a standard beginner Arduino demo.

# [The link for the video of the project is pasted below]:
<https://youtu.be/OMUWLKM0V2c>
