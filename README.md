# Project_Smart_Fan
Smart Fan project with AVR


# 📁디렉토리 구조

📦Fan_Project
 ┣ 📂ap
 ┃ ┣ 📂listener                 # 이벤트 리스터 구현
 ┃ ┃ ┣ 📜listener.c
 ┃ ┃ ┗ 📜listener.h
 ┃ ┣ 📂model                    # State의 mode 결정 model
 ┃ ┃ ┣ 📜modelautodata.c
 ┃ ┃ ┣ 📜modelautodata.h
 ┃ ┃ ┣ 📜modelfanmodestate.c
 ┃ ┃ ┣ 📜modelfanmodestate.h
 ┃ ┃ ┣ 📜modelfantimestate.c
 ┃ ┃ ┣ 📜modelfantimestate.h
 ┃ ┃ ┣ 📜modeltimedata.c
 ┃ ┃ ┗ 📜modeltimedata.h
 ┃ ┣ 📂presenter                # UI 구현
 ┃ ┃ ┣ 📜presenter.c
 ┃ ┃ ┗ 📜presenter.h
 ┃ ┣ 📂service                  # 비즈니스 로직 처리
 ┃ ┃ ┣ 📜fansystem.c
 ┃ ┃ ┣ 📜fansystem.h
 ┃ ┃ ┣ 📜Sound.c
 ┃ ┃ ┗ 📜Sound.h
 ┃ ┣ 📜apMain.c                 # 메인 실행 파일
 ┃ ┗ 📜apMain.h                 # 메인 헤더 파일
 ┣ 📂driver                     # 
 ┃ ┣ 📂button
 ┃ ┃ ┣ 📜Button.c
 ┃ ┃ ┗ 📜Button.h
 ┃ ┣ 📂buzzer
 ┃ ┃ ┣ 📜buzzer.c
 ┃ ┃ ┗ 📜buzzer.h
 ┃ ┣ 📂fan
 ┃ ┃ ┣ 📜fan.c
 ┃ ┃ ┗ 📜fan.h
 ┃ ┣ 📂fnd
 ┃ ┃ ┣ 📜fnd.c
 ┃ ┃ ┗ 📜fnd.h
 ┃ ┗ 📂lcd
 ┃ ┃ ┣ 📜lcd.c
 ┃ ┃ ┗ 📜lcd.h
 ┣ 📂periph
 ┃ ┣ 📂GPIO
 ┃ ┃ ┣ 📜GPIO.c
 ┃ ┃ ┗ 📜GPIO.h
 ┃ ┣ 📂timer
 ┃ ┃ ┣ 📜timer.c
 ┃ ┃ ┗ 📜timer.h
 ┃ ┗ 📂UART0
 ┃ ┃ ┣ 📜UART0.c
 ┃ ┃ ┗ 📜UART0.h
 ┗ 📜main.c