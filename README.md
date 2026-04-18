# 🏎️ High-Speed Line Follower Turbo Robot

A high-performance autonomous robot engineered for speed and precision. This project showcases a complete engineering cycle: from custom PCB design and sensor fusion to advanced control algorithms.

## 🌟 Overview
This robot is built to navigate complex tracks at high speeds. Unlike standard line followers, it utilizes a high-resolution 16-sensor array and a custom-designed PCB to achieve smooth PID-controlled motion and "turbo" speed profiles.

## 🛠️ Technical Specifications

### Hardware & Electronics
* **Microcontroller:** Arduino Nano (ATmega328P).
* **Custom PCB:** Designed in **EasyEDA**, optimized for low noise and compact footprint.
* **Sensor Array:** 16x **QRE1113GR** miniature reflectance sensors for high-density line tracking.
* **Signal Multiplexing:** Integrated **CD74HC4067** 16-channel analog multiplexer to handle the large sensor array using minimal I/O pins.
* **Motor Driver:** **TB6612FNG** dual-channel H-Bridge for efficient and responsive motor control.
* **Power System:** [Insert your battery type here, e.g., 7.4V 2S LiPo].

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
**[Το Ονοματεπώνυμό Σου]**
*Graduate Engineer in Informatics, Computer and Telecommunications Engineering*
*Special Forces Veteran | Robotics & IoT Enthusiast*
