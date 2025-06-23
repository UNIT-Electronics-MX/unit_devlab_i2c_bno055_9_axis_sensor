---
title: "UNIT BNO055 Module"
version: "1.0"
modified: "2025-06-23"
output: "unit_bno055_module"
subtitle: "9-DOF Absolute Orientation Sensor Module with Selectable UART/I²C Interface"
---

<!--
# README_TEMPLATE.md
Este archivo sirve como entrada para generar un PDF técnico estilo datasheet.
Edita las secciones respetando el orden, sin eliminar los encabezados.
-->

<!-- logo -->

# UNIT BNO055 Module

![product](images/top.png)

## Introduction

The UNIT BNO055 Module integrates a 9-axis absolute orientation sensor into a compact, ready-to-use form factor. It combines an accelerometer, gyroscope, and magnetometer with an onboard microcontroller running sensor fusion algorithms, delivering orientation data such as quaternions, Euler angles, and gravity vectors directly via serial or I²C communication.

This version includes a built-in DIP switch for selecting between **I²C and UART interfaces** by configuring the BNO055's `PS0` and `PS1` pins without the need for jumpers or solder bridges.

The module is ideal for robotics, drones, VR/AR, and IoT systems requiring accurate orientation tracking with minimal software overhead.

## Functional Description

The BNO055 sensor provides complete 9-DOF sensing with onboard sensor fusion, freeing the host microcontroller from complex processing tasks. The communication protocol can be toggled between I²C and UART using an onboard DIP switch connected to `PS0` and `PS1`.

The board includes labeled pins and a QWIIC-compatible JST-SH connector for quick connection to development platforms. An interrupt output (INT) can be used to signal motion or orientation events to the host MCU.

## Electrical Characteristics & Signal Overview

- Operating voltage: 3.3 V (typical)
- Logic compatibility: 3.3 V
- Interfaces: I²C or UART (selectable via PS0/PS1 DIP switch)
- Accelerometer ranges: ±2g, ±4g, ±8g, ±16g
- Gyroscope ranges: ±125 to ±2000 deg/s
- Magnetometer range: ±1.3 to ±8.1 gauss
- Output data: Euler angles, quaternions, linear acceleration, gravity vector
- Interrupt output: configurable for orientation or motion events

## Applications

- Robotics orientation and balancing
- Wearable motion tracking
- VR/AR head tracking
- Gesture interfaces
- Autonomous navigation systems
- Motion-activated devices

## Features

- BNO055 with onboard sensor fusion
- DIP-switch interface selection (I²C/UART)
- Breadboard-friendly pin headers
- QWIIC-compatible connector
- Interrupt pin for event signaling
- Compact, labeled module for easy integration

## Pin & Connector Layout

| PIN     | Description                         |
|---------|-------------------------------------|
| VCC     | Power supply input (3.3 V)          |
| GND     | Ground                              |
| SDA     | I2C data / UART TX (configurable)   |
| SCL     | I2C clock / UART RX (configurable)  |
| PS0     | Protocol select bit 0 (via DIP)     |
| PS1     | Protocol select bit 1 (via DIP)     |
| INT     | BNO055 interrupt output             |

## Settings

### Interface Overview

| Interface  | Signals / Pins        | Typical Use                                |
|------------|-----------------------|--------------------------------------------|
| I2C        | SDA, SCL              | Default communication with microcontroller |
| UART       | TX, RX (via SDA, SCL) | Alternative communication protocol         |
| GPIO       | PS0, PS1              | Protocol selection (via onboard DIP switch)|
| Interrupt  | INT                   | Orientation or motion event signaling      |

### Supports

| Symbol  | I/O | Description                                |
|---------|-----|--------------------------------------------|
| SDA     | I/O | I2C data / UART TX (shared)                |
| SCL     | I/O | I2C clock / UART RX (shared)               |
| PS0     | I   | BNO055 protocol select (bit 0, via DIP)    |
| PS1     | I   | BNO055 protocol select (bit 1, via DIP)    |
| INT     | O   | Motion/interrupt signal output             |

## Block Diagram

![Function Diagram](./images/pinout.png)

## Dimensions

![Dimensions](./images/dimension.png)

## Usage

Works with:

- Arduino (Nano, Mega, Due)
- ESP32, ESP8266
- Raspberry Pi (via I²C)
- Unity or Processing (3D visualization)

## Downloads

- [Schematic PDF](../hardware/unit_sch_V_0_0_1_BNO055.pdf)

## Purchase

- [Buy from UNIT Electronics](https://www.uelectronics.com)
