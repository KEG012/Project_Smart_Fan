다음은 깔끔하게 이모지를 추가한 README 파일입니다. 각 섹션에 맞는 이모지를 넣어 가독성을 높였습니다.

---

# 🌬️ Project_Smart_Fan

## 📋 프로젝트 개요  
- **프로젝트 기간**: 2024.08.06 - 2024.08.09  
- **주요기능**:  
    - 🕹️ 버튼 및 UART를 사용한 풍량 조절  
    - ⏲️ 타이머 설정 (3,5,7분 구동 후 자동 종료)  
    - 📟 LCD 및 FND 상태 표시  
    - 🔊 부저 알림  

---

## 🛠️ 기술 스택  

| 기술         | 설명                           |  
|--------------|--------------------------------|  
| 🖥️ ATmega128a | 하드웨어 제어 및 펌웨어 설계        |  
| 💻 C언어      | 소프트웨어 설계, FSM 설계          |  
| 🛠️ Microchip Studio | ATmega128a 펌웨어 작성      |  
| ⏳ Timer Interrupt | System Clock을 이용한 Interrupt 구동 |  
| 🔗 UART       | Serial 통신으로 원격 제어 구현      |  
| 🖧 I2C        | LCD 및 FND Serial 연결 구현     |  

---

## 📁 디렉토리 구조  

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

## 🔧 HW 구조  

- **ATmega128a**: MCU로서 디바이스 제어를 담당  
- **Motor Driver**: Motor에 전력 및 제어 시퀸스 전달  
- **FND**: 7 Segment로서 시간 표시  
- **LCD**: 현재 선풍기의 상태를 화면에 표시  
- **Button**: 상태 전환 및 타이머 설정을 위한 Trigger  
- **Buzzer**: 현재의 상태를 소리로 나타내주는 스피커  
- **Serial line**: 컴퓨터와 MCU를 연결하는 전선  

<p align="center">  
<img src="./Image/Fan HW.jpg" alt="HW 구조">  
</p>  

---

## 💻 SW Stack  

- **Main**: 구동의 최상단에서 작동하는 코드. apMain 함수를 호출.  
- **apMain**: Init 함수의 구동 및 Listener 함수를 호출.  
- **Listener**: Event 처리를 위한 코드. Event 발생 시 각 함수를 호출.  
- **Model**: 각종 변수를 불러오는 Get, Set 함수로 이루어진 함수.  
- **Service**: 로직 처리를 위한 코드.  
- **Presenter**: 화면 표시를 위한 코드. 출력을 위한 Device의 함수를 호출.  

<p align="center">  
<img src="./Image/Fan SW Stack.png" alt="SW Stack">  
</p>  

---

## 🔄 FSM  

- **FSM을 기반으로 선풍기의 각 동작 상태를 설계하고 구현**  
    - 초기상태: OFF  
    - Button, UART를 통하여 상태 변환  
    - Auto Mode는 Power 3개의 상태를 랜덤으로 구현  

<p align="center">  
<img src="./Image/fan FSM.jpg" alt="FSM">  
</p>  

---

## 🔍 상세 설명  

### 🔘 Button으로 Fan 세기 변경  

- Button1을 눌러 선풍기 ON/OFF  
- Button2를 눌러 풍량 조절  
- Button3을 눌러 Auto 모드로 변경. Auto 모드로 들어가기 전의 모드를 기억하여 Auto모드 종료 시 원래 모드로 복귀.  
- Global interrupt를 사용하여 PWM의 Duty Cycle을 구현. Hertz를 변경하여 풍량 조절  
- Auto 모드는 Hertz를 랜덤으로 변경하여 풍량의 세기를 랜덤으로 구현.  

<p align="center">  
<img src="./Image/fan off.png" alt="Fan Off">  
<img src="./Image/fan spd1.png" alt="Fan Speed 1">  
<img src="./Image/fan spd2.png" alt="Fan Speed 2">  
<img src="./Image/fan spd3.png" alt="Fan Speed 3">  
<img src="./Image/fan auto.png" alt="Fan Auto">  
</p>  

### ⏲️ Button으로 Timer 설정  

- Button4를 눌러 Timer 변경  
- 정확한 시간 구현을 위하여 Global Interrupt를 활용하여 1ms마다 interrupt가 일어나게 설정.  
- Interrupt가 일어날 때마다 count값이 증가(1ms).  
- 타이머가 끝나면 선풍기 OFF.  

<p align="center">  
<img src="./Image/fan 3min.png" alt="3분 Timer">  
<img src="./Image/fan 5min.png" alt="5분 Timer">  
<img src="./Image/fan 7min.png" alt="7분 Timer">  
</p>  

### 🔗 UART로 Fan 세기 변경  

- Comport Master를 통하여 문자열을 전달하면 이에 맞춰 선풍기를 가동.  
- 수신된 데이터는 내부 버퍼에 저장된 후 처리됨.  

<p align="center">  
<img src="./Image/fan uart.png" alt="UART Control">  
</p>  

---

## 🎥 시연 영상  

### 버튼 사용 선풍기 영상  
<p align="center">  
<img src="./Image/smart fan 3.gif" alt="Button Fan Video">  
</p>  

### UART 사용 선풍기 영상  
<p align="center">  
<img src="./Image/smart fan 4.gif" alt="UART Fan Video">  
</p>  

---  

이제 프로젝트의 내용을 더 명확하게 전달할 수 있을 것입니다! 😊
