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
        digitalWrite(ledPin, LOW); //버튼 입력이 없을때는 HIGH 이므로 LED를 끈다.
    }
    else
    {
        digitalWrite(ledPin, HIGH); //버튼 입력이 있을 때는 LOW 이므로 LED를 켠다.
    }
}
