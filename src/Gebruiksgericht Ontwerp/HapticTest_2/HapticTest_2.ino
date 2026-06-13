#include "OneButton.h"
#include "HapticPattern.h"

// ================= HARDWARE =================
HapticPattern motor(5);

OneButton button_1(8, true);   // ON/OFF + pairing (active LOW)
OneButton button_2(9, true);   // index scroll
OneButton button_3(10, true);  // lock

// ================= STATES =================
enum Mode {
  MODE_OFF,
  MODE_ON,
  MODE_PAIRING
};

Mode currentMode = MODE_OFF;

bool indexLocked = false;

int Index = 0;
const int maxIndex = 6;

// ================= SETUP =================
void setup() {
  Serial.begin(9600);

  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

  // 👉 CHECK: knop 1 ingedrukt bij opstart = pairing mode
  if (digitalRead(8) == LOW) {
    delay(1000); // check long press
    if (digitalRead(8) == LOW) {
      currentMode = MODE_PAIRING;
    }
  }

  // Knop 1 (ON/OFF)
  button_1.setPressMs(1000);
  button_1.attachLongPressStart(togglePower);

  // Knop 2 (index verhogen)
  button_2.attachClick(nextIndex);

  // Knop 3 (lock/unlock)
  button_3.attachClick(toggleLock);
}

// ================= LOOP =================
void loop() {
  motor.update();

  button_1.tick();
  button_2.tick();
  button_3.tick();

  handlePairingFeedback();
}

// ================= FUNCTIES =================

// 👉 ON/OFF toggle
void togglePower() {
  if (currentMode == MODE_PAIRING) return;

  if (currentMode == MODE_OFF) {
    currentMode = MODE_ON;
    motor.trigger(1);
    Serial.println("MODE: ON");
  } else {
    currentMode = MODE_OFF;
    motor.trigger(2);
    Serial.println("MODE: OFF");

    indexLocked = false;
  }
}

// 👉 Index verhogen (via knop i.p.v. potmeter)
void nextIndex() {
  if (currentMode != MODE_ON) return;
  if (indexLocked) return;

  Index++;
  if (Index > maxIndex) Index = 0;

  Serial.print("Index: ");
  Serial.println(Index);

  motor.trigger(5);
}

// 👉 Lock / unlock index
void toggleLock() {
  if (currentMode != MODE_ON) return;

  indexLocked = !indexLocked;

  if (indexLocked) {
    motor.trigger(7);
    Serial.println("Index LOCKED");
  } else {
    motor.trigger(8);
    Serial.println("Index UNLOCKED");
  }
}

// 👉 Pairing feedback (blijft pulsen)
void handlePairingFeedback() {
  if (currentMode != MODE_PAIRING) return;

  static unsigned long last = 0;

  if (millis() - last > 1000) {
    last = millis();
    motor.trigger(6); // pairing vibe patroon
    Serial.println("PAIRING...");
  }
}
