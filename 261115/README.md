# 261115 실습

## 실습에 대한 설명

- button_circuit.png : 아두이노의 5V와 GND를 브레드보드에 연결하고, 버튼과 저항을 이용하여 버튼을 누름에 따라 디지털 2번 핀에 HIGH 또는 LOW 신호가 입력되도록 회로를 구성하였습니다.

- button_code.txt : 버튼 입력을 위해 GPIO 2번 핀을 INPUT 모드로 설정하고, 시리얼 통신을 115200baud로 초기화 하였습니다. 이후 루프에서 digitalRead()를 통해 버튼의 입력 상태를 확인하고, 입력값이 HIGH면 시리얼 모니터에 "Pressed"를, LOW면 "Not Pressed"를 출력하도록 구현하였습니다.


- button_with_led_circuit.png : 버튼 회로에서 LED를 7번 핀에 연결하여 버튼을 누름에 따라 LED가 켜지거나 꺼지도록 회로를 구성하였습니다.

- button_with_led_code.txt : 기존 button_code에서 추가로 7번 핀을 LED 출력을 위한 OUTPUT으로 설정하고, 이후 루프에서 digitalWrite()를 통해 입력값이 HIGH면 LED가 켜지고 LOW면 LED가 꺼지도록 구현하였습니다.


- potentiometer_circuit.png : potentiometer를 A2핀, LED를 9핀에 연결하고 potentiometer에 따라 LED의 밝기가 변하도록 회로를 구성하였습니다.

- potentiometer_code.txt : Potentiometer를 A2핀, LED를 9핀으로 설정하고 analogRead()로 0-1023의 Potentiometer 값을 읽고 그 값을 ESP32의 아날로그 출력 크기에 맞게 0-255로 값의 범위를 매핑했습니다. 실행 후 회로에서 Potentiometer를 돌리면 매핑된 값에 맞게 정해진 LED의 출력이 나오게 됩니다.



- buzzer_test.ino : PWM을 통해 GPIO 5번 핀으로 연결된 2000Hz Buzzer의 소리 크기를 단계별로 조절합니다. ledcAttach()로 지정한 핀에 PWM을 출력하고 ledcWrite()로 Duty Cycle을 변경하도록 했습니다.

- potentiometer.ino : potentiometer로 버저의 사운드를 변환시켰습니다. analogRead()를 통해 가변저항의 아날로그 전압을 ADC 값(0~4095)으로 읽고, map()을 이용하여 0~255로 변환하였습니다. 이후 ledcWrite()로 Duty Cycle를 조절하여 potentiometer의 회전에 따라 부저의 출력이 변화하도록 구현하였습니다.

- servo_sweep.ino : 서보모터를 0도에서 180도까지 회전시킨 후, 다시 0도로 돌아오도록 하는 코드입니다. 반복문으로 15ms에 1도씩 모터 각도를 움직이며 마친 경우 다시 180도에서 0도로 1도씩 감소시키도록 구현했습니다.

- servo_test.ino : GPIO 14번 핀을 이용해 서보모터를 0도와 180도로 1초 간격으로 회전시킵니다. attach()로 핀을 설정한 후, write()를 이용하여 서보모터의 목표 각도를 0도와 180도로 번갈아 지정합니다.


<br>

## 기본 개념 정리

**레지스터(Register)**
MCU 내부에서 특정 설정이나 상태를 저장하는 공간

| 종류 | 설명 |
| DDR (Data Direction Register) | 핀을 입력(INPUT) 또는 출력(OUTPUT)으로 설정하는 레지스터 |
| Output Register | 출력 핀의 HIGH 및 LOW 상태를 설정하는 레지스터 |
| Pull-down Resistor | 입력 신호가 연결되지 않았을 때 기본값을 LOW(0)로 유지하는 저항 |
| Pull-up Resistor | 입력 신호가 연결되지 않았을 때 기본값을 HIGH(1)로 유지하는 저항 |

**Serial Communication** : 데이터를 한 번에 한 비트씩 순서대로 전송하는 직렬통신 방식
**Baud Rate** : 초당 전송되는 비트 수 (bit/s).
**Bouncing** : 버튼을 누르기 전후로 버튼이 불안정하게 여러번 빠르게 눌러지는 현상.

**Potentiometer** : 가변저항으로 손잡이를 돌리면 출력 전압이 달라지고, MCU는 ADC를 이용하여 전압을 숫자로 변환
**PWM(Pulse Width Modulation)** : 디지털 신호의 HIGH/LOW 시간을 조절하여 LED 밝기나 모터의 구동 출력을 제어하는 방식
**duty cycle** : 한 주기에서 HIGH가 차지하는 시간 비율


| 보드 구성 요소 | 설명 |
| Motor | 전기 에너지를 회전 운동으로 변환하여 로봇을 움직이는 장치 |
| LiDAR | 레이저를 이용해 주변 물체까지의 거리를 측정하는 센서 |
| IMU | 가속도와 각속도 등을 측정하여 로봇의 움직임과 자세를 추정하는 센서 |
| MPU6050 | 3축 가속도계와 3축 자이로스코프가 결합된 6축 IMU 센서 |
| Servo Motor | 제어 신호에 따라 모터의 각도를 목표 위치로 조절하는 장치 |

<br>
