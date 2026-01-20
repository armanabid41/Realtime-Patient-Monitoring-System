# 🚑 Wireless Real-time Patient Monitoring System

## 📌 Project Overview
A low-cost, portable IoT-based biotelemetry system designed to monitor a patient's **Heart Rate (BPM)** and **Body Temperature** in real-time. The system transmits data via **USB (Serial)** to a PC dashboard and via **Bluetooth (HC-05)** to an Android application.

## 🛠 Tech Stack
- **Hardware:** Arduino Uno, Pulse Sensor, LM35 Temperature Sensor, HC-05 Bluetooth Module.
- **Software:** Arduino IDE (C++), Python (Matplotlib, PySerial), Android (Bluetooth Electronics/RoboRemo).

## 📊 Features
- Real-time PPG waveform plotting using Python.
- Wireless monitoring on Smartphone via Bluetooth.
- Noise reduction using averaging algorithms.
- Dual-mode communication (Wired & Wireless).

## 📸 Screenshots
### Python Dashboard (PC View)
![Python Graph](Screenshots/20251220_224306.jpg)

### Android App (Mobile View)
![App View](Screenshots/android_dashboard.jpg)

## 🚀 How to Run
1. **Hardware Setup:** Connect the Pulse Sensor to Pin A0 and LM35 to Pin A1.
2. **Arduino:** Upload the code from `Arduino_Code` folder.
   - Use `Laptop_Mode` for PC visualization.
   - Use `Wireless_Mode` for Android App.
3. **Python:** Run the script using:
   ```bash
   pip install pyserial matplotlib
   python monitor.py
   Android: Connect via Bluetooth using the RoboRemo or Bluetooth Electronics app.

🔗 Author
Arman Hossain Abid EEE Student, IIUC

[www.linkedin.com/in/armanhossainabideee]
