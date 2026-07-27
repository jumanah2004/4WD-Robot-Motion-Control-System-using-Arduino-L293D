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