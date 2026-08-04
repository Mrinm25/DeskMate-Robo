# DeskMate-Robo

# 🤖 DeskMate - Interactive Desktop Companion Robot

DeskMate is an Arduino-based interactive desktop companion robot that detects nearby people, greets them, and enters sleep mode in low-light conditions. The project combines an ultrasonic sensor, servo motor, LDR sensor, and LCD display to create a simple yet engaging robotic companion.

---

## ✨ Features

- 🔍 Searches for nearby people by rotating its head.
- 📏 Detects a person using an HC-SR04 ultrasonic sensor.
- 👋 Greets the user with a friendly message.
- 🤖 Stops searching while interacting.
- 🌙 Detects darkness using an LDR sensor.
- 😴 Automatically enters "Good Night" mode in low-light conditions.
- 📺 Displays messages on a 16×2 LCD.

---

## 🛠️ Components Used

| Component | Quantity |
|-----------|---------:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| SG90 Servo Motor | 1 |
| 16×2 LCD Display | 1 |
| LDR Sensor | 1 |
| 220Ω Resistor | 1 |
| 10kΩ Resistor (for LDR) | 1 |
| Breadboard | 1 |
| Jumper Wires | Several |
| USB Cable | 1 |

---

## ⚙️ Working Principle

1. DeskMate starts and initializes all components.
2. It checks the ambient light using the LDR.
3. If the room is dark, it displays:
   - **Good Night**
   - **Z → Zz → Zzz**
4. Otherwise, it enters **Searching Mode**.
5. The servo continuously rotates from **60° to 120°**.
6. The ultrasonic sensor measures the distance.
7. If a person is detected within the preset distance:
   - Servo stops.
   - LCD displays **"Hi Buddy!"**
   - Interaction continues until the person leaves.
8. After the person leaves, DeskMate resumes searching.

---

## 🔌 Circuit Connections

### Servo
- Signal → D6
- VCC → 5V
- GND → GND

### Ultrasonic Sensor
- Trig → D9
- Echo → D10
- VCC → 5V
- GND → GND

### LCD (16×2)

| LCD Pin | Arduino |
|----------|----------|
| RS | D12 |
| E | D11 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |
| RW | GND |
| VSS | GND |
| VDD | 5V |
| V0 | Potentiometer |
| A | 5V (through resistor if required) |
| K | GND |

### LDR

- One leg → 5V
- Other leg → A0
- 10kΩ resistor between A0 and GND

---

---

## 📷 Demo

https://x.com/MrinmoyBhu39446/status/2084684530355667076?s=20

---

## 🚀 Future Improvements

- Voice interaction
- OLED display
- Face tracking
- Bluetooth control
- AI chatbot integration
- Battery-powered version
- Mobile app support

---

## 👨‍💻 Author

**Mrinm**

Made with ❤️ using Arduino Uno.

---

## ⭐ If you like this project

Please consider giving it a ⭐ on GitHub!
