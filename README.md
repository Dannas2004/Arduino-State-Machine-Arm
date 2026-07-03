# Arduino-State-Machine-Arm
A non-blocking, multi-actuator robotic arm controlled via a custom finite state machine. I wanted to build a simple 3-DOF robotic arm ever since I found out about Arduino in Grade 10. I figured this would make a nice exercise in preparation for my Microcontrollers course in Y3S2.

## Project Overview
This project integrates mixed actuator technologies (stepper and servo motors) into a single 3-axis mechanical arm. The control logic utilizes a Finite State Machine (FSM) to multiplex a single analog input across multiple operational states, eliminating the need for complex control panels. 

A major focus of this build was resolving hardware-software integration issues, specifically developing a software deadband filter to eliminate ADC signal noise and stabilize the stepper motor.

## Hardware Architecture
* **Microcontroller:** Arduino UNO R3
* **Actuators:** 28BYJ-48 Stepper Motor (Base), 2x SG90 Micro Servos (Shoulder & Wrist)
* **Power Isolation:** MB102 Power Supply Module (5V regulated)
* **Motor Driver:** ULN2003 Darlington Array

## Core Software Features
* **Non-Blocking Logic:** Replaced standard `delay()` functions with the `AccelStepper` library for continuous background execution.
* **Finite State Machine:** Cycle through Base, Shoulder, Wrist, and Standby modes using a single hardware button.
* **Signal Processing:** Custom hysteresis threshold (deadband filter) to prevent motor jitter and thermal overload from analog input noise.

## Files Included
* 3Degreearmcode.INO: The main C++ control logic for the Arduino UNO R3.
* 3DOFArmProject-Dandre.PDF: Full technical documentation, including kinematic layout, power routing, and FSM architecture.
* 3 DOF Robot Circuit.kicad_sch: The diagram for the Electronic circuit. Remember to read the notes I added.
