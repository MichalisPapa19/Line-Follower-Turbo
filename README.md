# 🏎️ High-Speed Line Follower Turbo Robot

<img width="766" height="471" alt="Screenshot_2" src="https://github.com/user-attachments/assets/f2f34b1a-0e16-4045-bb2d-5c5c47de90ce" />


A high-performance autonomous robot engineered for speed and precision. This project showcases a complete engineering cycle: from custom PCB design and sensor fusion to advanced control algorithms.

## 🌟 Overview
This robot is built to navigate complex tracks at high speeds. Unlike standard line followers, it utilizes a high-resolution 16-sensor array and a custom-designed PCB to achieve smooth PID-controlled motion and "turbo" speed profiles.

## 🛠️ Technical Specifications

### Hardware & Electronics
* **Microcontroller:** Arduino Nano (ATmega328P).
* **Custom PCB:** Designed in **EasyEDA**, optimized for low noise and compact footprint.
* **Sensor Array:** 16x **QRE1113GR** miniature reflectance sensors for high-density line tracking.
* **Signal Multiplexing:** Integrated **CD74HC4067** 16-channel analog multiplexer to handle the large sensor array using minimal I/O pins.
* **Turbine:** 30mm EDF with a 7000KV Brushless Motor.
* **Motor Driver:** **TB6612FNG** dual-channel H-Bridge for efficient and responsive motor control.
* **Power System:** [Insert your battery type here, e.g., 11.1V 3S LiPo].

  <img width="915" height="476" alt="Screenshot_4" src="https://github.com/user-attachments/assets/e29275b0-ed47-42f6-b2b2-d91cebb6cabe" />
  
  <img width="865" height="540" alt="Screenshot_5" src="https://github.com/user-attachments/assets/4b59b113-3b8a-4410-9345-eb32c4b3209a" />

<img width="798" height="561" alt="Screenshot_3" src="https://github.com/user-attachments/assets/c4fb593c-b512-4b3a-9961-ba2de94e9bc8" />

  

### Software & Control
* **PID Control:** Implementation of a Proportional-Integral-Derivative controller for precise line centering.
* **Multiplexer Polling:** Optimized code for rapid sequential reading of the 16-channel sensor array.
* **Turbo Logic:** Dynamic speed adjustment based on line curvature (aggressive acceleration on straights, controlled braking on curves).
* **Sensor Calibration:** Auto-calibration routine to adapt to different floor reflectivities and ambient light.

## 📂 Repository Structure
* `/Firmware` : Arduino (.ino) source code and logic.
* `/Hardware` : Schematic diagrams (PDF), Gerber files, and Bill of Materials (BOM).
* `/Media` : Photos of the custom PCB and videos of the robot in action.

## 🚀 Key Engineering Challenges Solved
* **Resource Management:** Expanded the limited analog inputs of the Arduino Nano using the CD74HC4067 multiplexer.
* **PCB Integrity:** Successfully routed a dense 16-sensor array to a central processing unit on a custom 2-layer board.
* **High-Speed Stability:** Fine-tuned PID constants to eliminate oscillations at "turbo" voltage levels.

## 📜 License
This project is licensed under the **MIT License** - feel free to use and modify it!

## 👨‍💻 Author
**Michil Papaioannou**
*Graduate Engineer in Informatics, Computer and Telecommunications Engineering*
*Robotics & IoT Enthusiast*
