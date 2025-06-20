# **Schematic**

<div align="center">
  <a href="#"><img src="resources/img/Schematics_icon.jpg" width="450px" alt="Schematic"></a>
  <p>Schematic</p>
</div>

# **Pinout**

<div align="center">
  <a href="#"><img src="resources/unit_pinout_v_0_0_1_ue0092_bno055_en.jpg" width="450px" alt="Pinout"></a>
  <p>Pinout</p>
</div>

### Qwiic Connector (SparkFun)

<div align="center">

| Pin | Signal  |
|:---:|:--------|
| 1   | **VCC** (3.3 V) |
| 2   | **GND**         |
| 3   | **SDA**         |
| 4   | **SCL**         |
</div>

> **Note:** Qwiic operates at 3.3 V only.

<div align="center">

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
</div>

---

## **DIP-Switch: Interface & Address Selection**
 

---

# **Dimensions**

<div align="center">
  <a href="#"><img src="resources/unit_dimension_v_0_0_1_ue0092_BNO055.png" width="450px" alt="Dimensions"></a>
  <p>Dimensions</p>
</div>

---

# **Topology**

<div align="center">
  <a href="#"><img src="./resources/unit_topology_v_0_0_1_ue0092_BNO055.png" width="450px" alt="Topology"></a>
  <p>Topology</p>
</div>

| Ref.  | Description                                                                 |
|-------|-----------------------------------------------------------------------------|
| IC1   | BNO055                                                                      |
| U1    | AP2112K 3.3V LDO voltage regulator                                          |
| L1    | Power-on LED                                                                |
| SW1   | Dip Switch for mode selection                                               |
| SB1   | Solder bridge to select I²C address                                         |
| J1    | Low-power I²C QWIIC JST connector                                           |
| JP1   | 2.54 mm pin header                                                          |
| JP2   | 2.54 mm pin header                                                          |
| JP3   | 2.54 mm pin header                                                          |