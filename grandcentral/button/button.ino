const int ledPin = 13;
const int inputPin = 2;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(inputPin, INPUT);
    digitalWrite(inputPin, HIGH); //inputPin에 대해 내부 풀업 저항을 작동시킨다.
}

void loop() {
    int val = digitalRead(inputPin); //입력값을 읽는다.
    if ( val == HIGH )
    {
        digitalWrite(ledPin, HIGH); //LED를 끈다.
    }
    else
    {
        digitalWrite(ledPin, LOW); //LED를 켠다.
    }
}
