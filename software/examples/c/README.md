# BNO055 Sensor Data Logger

This file provides a detailed explanation of an C++ sketch that uses the **UNIT BNO055** sensor to collect multiple types of sensor data (orientation, acceleration, gyroscope, magnetometer, temperature, gravity, etc.) and transmits them over the serial port in **JSON** format.

> ⚠️ **Important:** Make sure **PS0** and **PS1** pins are set to **0** (connected to GND) to enable **I2C mode** on the BNO055 sensor.  
> Your module includes a **DIP switch**, you can use it to set **PS0** and **PS1** to `0` easily for I2C operation.


## Included Libraries

```cpp
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
```
These libraries are used for:

- I2C communication (Wire)

- Abstract sensor interfaces (Adafruit_Sensor)

- BNO055 functions (Adafruit_BNO055)

- Vector/matrix math (imumaths)

## Setup Section

```cpp
Adafruit_BNO055 bno(55, 0x28, &Wire);
```

Initializes the BNO055 object at I2C address 0x28.

```cpp
Serial.begin(115200);
while (!Serial);
```

Starts serial communication and waits for the port to be ready.

```cpp
if (!bno.begin()) {
  Serial.println("Error: BNO055 not detected");
  while (1);
}

```
Checks if the sensor is detected. If not, halts execution.

## Sensor Data Collection

Reads all supported vectors:

```cpp
bno.getEvent(&orientation,    Adafruit_BNO055::VECTOR_EULER);
bno.getEvent(&gyro,           Adafruit_BNO055::VECTOR_GYROSCOPE);
bno.getEvent(&linearAccel,    Adafruit_BNO055::VECTOR_LINEARACCEL);
bno.getEvent(&magnetometer,   Adafruit_BNO055::VECTOR_MAGNETOMETER);
bno.getEvent(&accel,          Adafruit_BNO055::VECTOR_ACCELEROMETER);
bno.getEvent(&gravity,        Adafruit_BNO055::VECTOR_GRAVITY);

```
Also retrieves:

- Temperature using bno.getTemp()

- Calibration data via bno.getCalibration()

## JSON Output

```cpp
Serial.print("{\"orientation\":{\"x\":...}, ... }");
```

Generates a JSON object with the following fields:

- `orientation`

- `gyroscope`

- `linear_accel`

- `magnetometer`

- `acceleration`

- `gravity`

- `temperature`

- `calibration` (`sys`, `gyro`, `accel`, `mag`)

This makes it easy to parse in external applications like Processing, Python, or web dashboards.

## Sampling Frequency

```cpp
const uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;
```
The loop runs every 100 milliseconds → 10 Hz sampling rate.

## Aplications 

Telemetry for robotics and drones 

Orientation tracking in AR/VR headsets 

Motion sensing for prosthetics and biomechanics 

Stability control in educational rockets 

Inertial navigation for autonomous vehicles 

## Sample Serial Output

```json
{
  "orientation":{"x":12.34,"y":0.56,"z":179.89},
  "gyroscope":{"x":0.01,"y":-0.02,"z":0.00},
  "linear_accel":{"x":0.00,"y":0.01,"z":9.80},
  "magnetometer":{"x":12.00,"y":-35.00,"z":-5.00},
  "acceleration":{"x":0.01,"y":0.00,"z":9.81},
  "gravity":{"x":0.00,"y":0.00,"z":9.81},
  "temperature":27,
  "calibration":{"sys":3,"gyro":3,"accel":3,"mag":3}
}

```