# 🚀 Transformable Aerial–Ground Robot  
### Institute Technical Summer Project (ITSP)

This project presents the design and development of a **hybrid robot capable of operating both as a ground vehicle and as a quadcopter drone**. The system mechanically transforms between driving and flying configurations using servo-actuated arms.

Inspired by research in **reconfigurable robotics** from leading institutions like MIT, this project explores **multi-modal mobility**, where a single robot can adapt its structure to traverse different terrains and environments.

---

## 🎯 Project Objectives

- Design a robot that can **drive on the ground and fly in the air**
- Develop a **mechanical transformation system**
- Integrate **aerial and ground mobility** into one platform
- Build a **low-cost student prototype** using accessible components

---

## 🧩 System Overview

| Subsystem | Description |
|----------|-------------|
| 🛞 Ground Mobility | Differential drive wheel system using DC motors |
| 🚁 Aerial Mobility | Quadcopter propulsion using brushless motors + ESCs |
| 🔁 Transformation Mechanism | Servo-actuated rotating arms |
| 🎮 Control Unit | Arduino-based control system |
| 🔋 Power System | LiPo battery powering motors and control electronics |

---

## 🛠 Hardware Design

The robot frame and transformation mechanism were custom-designed and iterated through multiple prototypes.

**Key Mechanical Features**
- Rotating arms that reposition wheels into propeller arms
- Lightweight structural frame
- Integrated motor mounting system

📁 See `Hardware/3D_Models/` for CAD files  
📁 Assembly visuals available in `Hardware/Assembly_Images/`

---

## 🔌 Electronics System

The electronics architecture manages both locomotion modes and the transformation system.

**Main Components**
- Arduino Uno
- Brushless motors + ESCs
- DC drive motors
- Servo motors for transformation
- RF transmitter & receiver module

📁 Circuit diagrams → `Electronics/Circuit_Diagrams/`  
📁 Wiring layouts → `Electronics/Wiring_Layouts/`  
📁 Tinkercad designs → `Electronics/Tinkercad_Designs/`

---

## 💻 Software Architecture

The control software is divided by functional modules.

| Module | Function |
|-------|----------|
| Flight Controller | Stabilization and motor control for drone mode |
| Car Mode Control | Wheel motor control for ground movement |
| Mode Switching | Handles transformation between car and drone |
| ESC Calibration | Calibration routine for brushless ESCs |

📁 All Arduino programs are available in the `Software/` directory.

---

## 🔁 Transformation Mechanism

The robot transitions between modes using servo-driven arms:

**Car Mode ➝ Drone Mode**
1. Arms rotate outward  
2. Wheels reposition to become landing supports  
3. Propellers align for flight  

**Drone Mode ➝ Car Mode**
1. Arms fold inward  
2. Wheels align for ground contact  
3. Drive motors engage  

This allows the robot to adapt based on terrain and task requirements.

---

## 🧪 Simulations & Testing

Early-stage circuit and control logic were tested using simulation tools before hardware implementation.

📁 Simulation files available in `Simulations/`

---

## 🎥 Demonstrations

Project demonstration videos showing transformation and testing:

📁 `Media/Transformation_Videos/`

---

## 📘 Documentation

Complete design explanation and project presentation:

📁 `Documentation/ITSP_Presentation.pdf`

---

## ⚠️ Safety Notice

This is a student-built prototype. Flight tests were conducted in controlled environments with safety precautions. The system is not intended for commercial or outdoor autonomous operation.

---

## 👨‍🔬 Developed Under

**Institute Technical Summer Project (ITSP)**  
Student Engineering Research Initiative

---

## 📌 Future Improvements

- Autonomous stabilization using IMU + PID control  
- Lightweight composite frame  
- Automatic terrain-based mode switching  
- Onboard camera for aerial surveillance  

---

## 🤝 Acknowledgment

This project was inspired by ongoing research in **transformable and reconfigurable robotics**, demonstrating how adaptable robots can enhance mobility in complex environments.

---

**⭐ If you find this project interesting, consider starring the repository!**
