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
## 🔗 Interactive Tinkercad Circuit Simulation

👉 **[Click Here to Launch the Tinkercad Simulation](https://www.tinkercad.com/things/lXKyrP2NtSe-dc-motor-use-l293d)**

> 📌 **Note:** You can click the "Start Simulation" button inside Tinkercad to watch the motors execute the programmed directional logic.

---
## 📐 Circuit Diagram

![Circuit Diagram](https://github.com/jumanah2004/4WD-Robot-Motion-Control-System-using-Arduino-L293D/blob/bed14c72d7be31ed2c1d8c994eb46859effc541a/dc.png)


---
## 🎬 Video Demonstration
https://github.com/user-attachments/assets/d15a071b-5aee-4692-a472-b5dfc066fd13

[also the link of video!](https://github.com/user-attachments/assets/d15a071b-5aee-4692-a472-b5dfc066fd13
)
---
## 💻 Arduino Code

```cpp
// L293D Motor Driver

// Left Motors
int ENA = 5;
int IN1 = 2;
int IN2 = 3;

// Right Motors
int ENB = 6;
int IN3 = 4;
int IN4 = 7;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void loop() {

  // ===== Move Forward for 30 seconds =====
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(30000);

  // ===== Stop for 1 minute =====
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(60000);

  // ===== Turn Right and Left Alternately for 1 minute =====
  for (int i = 0; i < 6; i++) {

    // Turn Right (5 seconds)
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    delay(5000);

    // Turn Left (5 seconds)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    delay(5000);
  }

  // ===== Final Stop =====
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  while (true);
}
```
----
## 🚀 Applications:

* **Timed Automated Patrols:** Running fixed, scheduled movement patterns for basic indoor patrolling.
* **Motor & Driver Testing:** Serving as a testbench to check L293D performance and DC motor balance.
* **Educational Demonstrations:** Demonstrating Arduino digital/PWM pin control, H-Bridge logic, and non-blocking delays.
* **Basic Automated Conveyors / Rovers:** Executing precise timed operations (move, pause, switch directions) without external feedback.
