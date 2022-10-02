#include <Adafruit_CircuitPlayground.h>

bool slideSwitch;

void setup() {
    Serial.begin(9600);
    CircuitPlayground.begin();
}

void loop() {
    slideSwitch = CircuitPlayground.slideSwitch();

    Serial.print("Slide Switch: ");
    if (slideSwitch) {
        CircuitPlayground.playTone(1000, 100);
        delay(1000);
        Serial.print("+");
    } else {
        CircuitPlayground.playTone(0, 0);
        Serial.print("-");
    }
    Serial.println();

    delay(1000);
}
