/*
Debounce 
핀 2에 연결된 스위치로 핀 13에 연결된 led를 켠다.
디바운스 논리는 스위치 상태를 잘못 읽게 되는 상황을 방지한다.
*/

const int ledPin = 13; //입력 핀 번호
const int inputPin = 2; //출력 핀 번호
const int debounceDelay = 10; //안정된 상태가 될 때까지 기다리는 시간(밀리초)

//debounce 함수는 지정된 핀의 스위치가 닫혀 있고 안정된 상태이면 true를 리턴한다.
boolean debounce (int pin)
{
    boolean state;
    boolean previousState;

    previousState = digitalRead(pin); //스위치 상태를 저장한다.
    for(int counter=0; counter < debounceDelay; counter++)
    {
        delay(1); // 1밀리초 동안 대기한다.
        state = digitalRead(pin); //핀을 읽는다.
        if( state != previousState )
        {
            counter = 0; //상태가 변경이 되면 카운터를 재설정한다.
            previousState = state; // 그리고 현재 상태를 저장한다.
        }
    }
    // 스위치가 디바운스 기간보다 긴 시간동안 안정된 상태를 유지하게되면 여기에 도달하게 된다.
    return state;
}

int count;

void setup() 
{
    pinMode(ledPin, OUTPUT);
    pinMode(inputPin, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    if (debounce(inputPin))
    {
        digitalWrite(ledPin, HIGH);
        count++; //count 값을 증가시킨다.
        Serial.println(count); 
    }
    else 
    {
        digitalWrite(ledPin, LOW);
    }
}
