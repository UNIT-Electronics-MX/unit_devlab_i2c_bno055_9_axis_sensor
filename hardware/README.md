# **Schematic**

<div align="center">
  <a href="#"><img src="resources/Schematics_icon.jpg" width="450px" alt="Schematic"></a>
  <p>Schematic</p>
</div>

# **Pinout**

<div align="center">
  <a href="#"><img src="hardware/resources/touchdot.png" width="450px" alt="Pinout"></a>
  <p>Pinout</p>
</div>

### Qwiic Connector (SparkFun)
| Pin | Signal  |
|:---:|:--------|
| 1   | **VCC** (3.3 V) |
| 2   | **GND**         |
| 3   | **SDA**         |
| 4   | **SCL**         |

> **Note:** Qwiic operates at 3.3 V only.

| Pin       | Signal               | Description                                          |
|:---------:|:--------------------:|:-----------------------------------------------------|
| VCC       | Power                | 3.3 V                                                |
| GND       | Ground               | 0 V reference                                        |
| BOOT      | Boot Mode            | H = internal bootloader, L = normal application      |
| PS1       | Strap bit 1          | Interface/address selection (see DIP-switch table)   |
| PS0       | Strap bit 0          | Interface/address selection                          |
| BL-IND    | Boot LED             | Blinks in bootloader; power-on indicator             |
| RST       | Reset (active low)   | Hold low to reset the BNO055                         |
| INT       | Interrupt            | “Data ready” or other configurable interrupt output  |
| SCL ↔ RX  | I²C SCL or UART RX   | Depends on PS1/PS0 setting                           |
| SDA ↔ TX  | I²C SDA or UART TX   | Depends on PS1/PS0 setting                           |
| SWCLK     | SWD Clock            | Debug/program via Serial Wire Debug                  |
| SWDIO     | SWD Data             | Debug/program via Serial Wire Debug                  |

---

## **DIP-Switch: Interface & Address Selection**
 

---

## Connection Examples:

### A. I²C Mode (address 0x28)


### B. UART Mode (115 200 bps)

---

# **Dimensions**

<div align="center">
  <a href="#"><img src="hardware/resources/touchdot.png" width="450px" alt="Dimensions"></a>
  <p>Dimensions</p>
</div>