# Examples

This example shows how to stream Yaw, Pitch, Roll from a BNO055 over Serial and render a 3D cube in Processing that follows the sensor’s orientation.

Important: Close the Arduino Serial Monitor before running Processing. Only one app can use the serial port at a time.



<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=arduino,processing&theme=light" />
  </a>
</p>


## 1.  Arduino — Send yaw, roll, pitch over Serial

Copy & paste into the Arduino IDE, upload to your board (BNO055 via I2C), and make sure the baud rate matches (115200).


## 2) Processing — 3D Viewer (cube follows the sensor)

Close the Arduino Serial Monitor now.

Open Processing 4.x, create a new sketch, and copy & paste the code below.
Change COM54 to your serial port if needed (macOS/Linux: /dev/tty.usbmodem..., /dev/ttyUSB0, etc.).

## Quick Notes

Close the Arduino Serial Monitor before running Processing (otherwise the port is busy).

Baud rate must match: 115200 in both Arduino and Processing.

Find your port: check the list printed by printArray(Serial.list()) in Processing’s console.

If you see NaN values, it usually means:

Wrong baud rate (mismatched), or

Non-numeric lines were read at startup → handled by warmup, or restart Processing.

That’s it—copy, paste, and you’re up and running.