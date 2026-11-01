# Ultrasonic Distance Alert System

A precision-engineered proximity monitoring and acoustic alert system built using an **Elegoo Uno R3**, an **HC-SR04 ultrasonic distance sensor**, and a **passive piezo buzzer**. This system translates real-time distance telemetry into frequency-modulated audio feedback.

---

## System Demonstration

![Proximity Alert System Demo](docs/proximity_demo.gif)

*Demonstration of the dynamic proximity feedback loop: as an obstacle approaches the HC-SR04 ultrasonic sensor, the passive buzzer escalates beep frequency and tone pitch in real time.*

---

## Key Features
* **Real-Time Telemetry:** Calculates precise target distance in centimeters using precise acoustic pulse-echo timing.
* **Frequency-Modulated Acoustic Feedback:** Utilizes a passive buzzer driven by custom `tone()` frequency mapping to indicate proximity danger zones.
* **Modular Threshold Logic:** Features multi-tier alert states (Safe, Caution, and Danger) to prevent false positives.

---

## Hardware & Component Specifications
* **Microcontroller:** Elegoo Uno R3 (ATmega328P)
* **Sensor:** HC-SR04 Ultrasonic Ranging Module (4-pin interface)
* **Audio Output:** Non-polarized Passive Piezo Buzzer
* **Development Environment:** Arduino IDE / C++

---

## Wiring & Pin Mapping

| Component | Component Pin | Breadboard Coordinates | Uno R3 Destination |
| :--- | :--- | :--- | :--- |
| **HC-SR04** | VCC | Row 5, Col D (Wire from Col A) | 5V Pin |
| **HC-SR04** | Trig | Row 6, Col D (Wire from Col A) | Digital Pin 9 |
| **HC-SR04** | Echo | Row 7, Col D (Wire from Col A) | Digital Pin 8 |
| **HC-SR04** | GND | Row 8, Col D (Wire from Col A) | GND Pin |
| **Buzzer** | Terminal 1 | Row 20, Col D (Wire from Col A) | Digital Pin 7 |
| **Buzzer** | Terminal 2 | Row 25, Col D (Wire from Col A) | GND Pin |

---

## Proximity Alert Logic
* **Safe Zone (> 25 cm):** Buzzer remains silent.
* **Caution Zone (10 cm – 25 cm):** Medium-frequency pulse (1,500 Hz) with moderate spacing.
* **Danger Zone (< 10 cm):** High-frequency rapid warning tone (2,500 Hz) with short pulse intervals.

---

## Visual Documentation

### Hardware Assembly
![Hardware Setup](docs/weather-light-monitoring-station-Circuits-Setup.png)

### Telemetry Output
![Serial Monitor](docs/Serial-monitor-Output.png)
