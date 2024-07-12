// 아두이노 메가 핀 번호 설정
const int sensorPins[] = {13, 15, 11, 7}; //4개의 라인센서가 연결된 아두이노 메가의 핀 번호 정의

void setup() {
  // 시리얼 통신 초기화 (9600)
  Serial.begin(9600);

  // 각 센서 핀을 입력 모드로 설정
  for (int i = 0; i < 4; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  // 초기화 메시지 출력
  Serial.println("Setup complete. Starting sensor readout...");
}

void loop() {
  // 각 센서의 값을 읽고 시리얼로 출력
  for (int i = 0; i < 4; i++) {
    int sensorValue = digitalRead(sensorPins[i]); //현재 센서 핀에서 값 읽기 

    //시리얼 출력 시작
    
    Serial.print("(Sensor ");
    Serial.print(i);  //센서 번호 출력
    Serial.print("): ");
    Serial.print(sensorValue);  // 센서 값 출력

    //가시성 위한 코드
    
    if(i<3) {              // 마지막 센서가 아닐 때,
      Serial.print(" / "); // 센서 값 사이에 "/" 출력
    }
  }

    Serial.println();   // 모든 센서 값 한줄로 출력 후 줄바꿈

  // 0.1초 대기
  delay(100);
}
