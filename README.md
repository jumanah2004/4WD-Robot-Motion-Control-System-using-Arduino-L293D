# 4WD-Robot-Motion-Control-System-using-Arduino-L293D
---
# 🤖 4-Wheel Robot Drive Control using Arduino & L293D

This project demonstrates how to control a 4-wheel drive (4WD) robot using an **Arduino Uno** and an **L293D Motor Driver IC**. The system manages the direction and timing of four DC motors to execute a specific sequence of movements.

---

## 📌 Project Overview

The robot's drive system divides four DC motors into two operational sides:
* **Right Side:** Two DC motors wired in parallel (front & rear).
* **Left Side:** Two DC motors wired in parallel (front & rear).

The **L293D H-Bridge driver** allows the Arduino to regulate the rotation direction of the motors while supplying necessary current and protecting the microcontroller board.

### Motion Sequence:
1. **Forward:** Drives forward for 30 seconds.
2. **Pause:** Brief delay for safe transition.
3. **Reverse:** Drives backward for 1 minute (60 seconds).
4. **Pause:** Brief delay.
5. **Alternating Turn:** Alternates between turning right and left repeatedly for 1 minute.

---

## 🛠️ Hardware & Components

* **Arduino Uno**
* **L293D Motor Driver IC**
* **4x DC Motors**
* **9V Battery** (External power source for motors)
* **Breadboard**
* **Jumper Wires**

---

## 📐 Circuit Diagram

![Circuit Diagram](circuit.png)
*(Save your circuit image as `circuit.png` in the same repository directory to render it properly)*

---

## 💻 Arduino Code

```cpp
// L293D Control Pins Definition
const int IN1 = 2; // Left side control pin 1
const int IN2 = 3; // Left side control pin 2
const int IN3 = 4; // Right side control pin 1
const int IN4 = 5; // Right side control pin 2

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// Helper function to stop all motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function to move forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to move backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to turn left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  // 1. Move Forward for 30 seconds
  moveForward();
  delay(30000);

  stopMotors();
  delay(1000); // Short pause to protect motors

  // 2. Move Backward for 1 minute (60 seconds)
  moveBackward();
  delay(60000);

  stopMotors();
  delay(1000);

  // 3. Alternate between Turning Right and Left for 1 minute
  // (30 cycles * 2 seconds per cycle = 60 seconds)
  for (int i = 0; i < 30; i++) {
    turnRight();
    delay(1000);
    turnLeft();
    delay(1000);
  }

  stopMotors();
  delay(2000); // Pause before repeating loop
}
