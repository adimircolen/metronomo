#include <LiquidCrystal.h>

#define BUZZER  6      // buzzer pin
#define MIN_BPM 60      // minimum bpm value
#define MAX_BPM 141     // maximum bpm value
#define POT A0          // pot analog pin

int bpm;

LiquidCrystal lcd(2,3,10,11,12,13);

void setup() {
  lcd.begin(16,2);
  lcd.print("Metronomo: ");
  lcd.setCursor(0,1);
  lcd.print("BPM: ");
  pinMode(BUZZER, OUTPUT);
}

void loop() {

    bpm = map(analogRead(POT), 0, 1023, MIN_BPM, MAX_BPM);
    lcd.setCursor(6,1);
    lcd.println(bpm);
    lcd.display();
    tone(BUZZER, 5090);       // does a "tick" for...
    delay(6000 / bpm);        // 10% of T (where T is the time between two BPSs)
    noTone(BUZZER);           // silence for...
    delay(54000 / bpm);       // 90% of T
}

