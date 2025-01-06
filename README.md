# Project_Smart_Fan

## 프로젝트 개요
- 프로젝트 기간: 2024.08.06 - 2024.08.09
- 주요기능:
    - 버튼 및 UART를 사용한 풍량 조절
    - 타이머 설정 (3,5,7분 구동 후 자동 종료)
    - LCD 및 FND 상태 표시
    - 부저 알림

## 기술 스택

| 기술     |설명             |
|------|---------------|
| ATmega128a | 하드웨어 제어 및 펌웨어 설계 |
| C언어 | 소프트웨어 설계, FSM 설계 |
| Microchip Studio | ATmega128a 펌웨어 작성 |
| Timer Interrupt | System Clock을 이용한 Interrupt 구동 |
| UART | Serial 통신으로 원격 제어 구현 |
| I2C | LCD 및 FND Serial 연결 구현 |

## 📁디렉토리 구조

```plaintext
📦Fan_Project
 ┣ 📂ap
 ┃ ┣ 📂listener         # 이벤트 리스터 구현
 ┃ ┣ 📂model            # State의 mode 결정 model
 ┃ ┣ 📂presenter        # UI 구현
 ┃ ┣ 📂service          # 비즈니스 로직 처리
 ┃ ┣ 📜apMain.c         # 메인 실행 파일
 ┃ ┗ 📜apMain.h         # 메인 헤더 파일
 ┣ 📂driver             # 디바이스 드라이브 구성
 ┃ ┣ 📂button           # 버튼 입력 처리
 ┃ ┣ 📂buzzer           # buzzer 출력 처리
 ┃ ┣ 📂fan              # 선풍기 모터 제어
 ┃ ┣ 📂fnd              # 7Segment 출력 처리
 ┃ ┗ 📂lcd              # lcd 출력 처리
 ┣ 📂periph             # 주변기기 구성
 ┃ ┣ 📂GPIO             # GPIO 핀 제어
 ┃ ┣ 📂timer            # 타이머 인터럽트 처리
 ┃ ┗ 📂UART0            # UART 통신 처리
 ┗ 📜main.c             # main 최상단 파일
 ```
---
## HW 구조
- ATmega128a : MCU로서 디바이스 제어를 담당
- Motor Driver : Motor에 전력 및 제어 시퀸스 전달
- FND : 7 Segment로서 시간 표시
- LCD : 현재 선풍기의 상태를 화면에 표시
- Button : 상태 전환 및 타이머 설정을 위한 Trigger
- Buzzer : 현재의 상태를 소리로 나타내주는 스피커
- Serial line : 컴퓨터와 MCU를 연결하는 전선

<p align="center">
<img src="./Image/Fan HW.jpg">
</p>

## SW Stack
- Main : 구동의 최상단에서 작동하는 코드. apMain 함수를 호출.
- apMain : Init 함수의 구동 및 Listener 함수를 호출.
- Listener : Event 처리를 위한 코드. Event 발생 시 각 함수를 호출.
- Model : 각종 변수를 불러오는 Get, Set 함수로 이루어진 함수.
- Service : 로직 처리를 위한 코드.
- Presenter : 화면 표시를 위한 코드. 출력을 위한 Device의 함수를 호출.
<p align="center">
<img src="./Image/Fan SW Stack.png">
</p>

## FSM
- FSM을 기반으로 선풍기의 각 동작 상태를 설계하고 구현
    - 초기상태 : OFF
    - Button, UART를 통하여 상태 변환
    - Auto Mode는 Power 3개의 상태를 랜덤으로 구현
<p align="center">
<img src="./Image/fan FSM.jpg">
</p>

----

## 상세 설명