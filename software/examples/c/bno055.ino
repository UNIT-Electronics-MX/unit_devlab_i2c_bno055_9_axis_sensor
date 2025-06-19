#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

const uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;
Adafruit_BNO055 bno(55, 0x28, &Wire);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!bno.begin()) {
    Serial.println("Error: BNO055 not detected");
    while (1);
  }

  delay(1000);
}

void loop() {
  sensors_event_t orientation, gyro, linearAccel, magnetometer, accel, gravity;

  bno.getEvent(&orientation,    Adafruit_BNO055::VECTOR_EULER);
  bno.getEvent(&gyro,           Adafruit_BNO055::VECTOR_GYROSCOPE);
  bno.getEvent(&linearAccel,    Adafruit_BNO055::VECTOR_LINEARACCEL);
  bno.getEvent(&magnetometer,   Adafruit_BNO055::VECTOR_MAGNETOMETER);
  bno.getEvent(&accel,          Adafruit_BNO055::VECTOR_ACCELEROMETER);
  bno.getEvent(&gravity,        Adafruit_BNO055::VECTOR_GRAVITY);

  int8_t temperature = bno.getTemp();
  uint8_t sys, gyroCal, accelCal, magCal;
  bno.getCalibration(&sys, &gyroCal, &accelCal, &magCal);

  Serial.print("{");

  // Orientation
  Serial.print("\"orientation\":{\"x\":"); Serial.print(orientation.orientation.x, 2);
  Serial.print(",\"y\":"); Serial.print(orientation.orientation.y, 2);
  Serial.print(",\"z\":"); Serial.print(orientation.orientation.z, 2); Serial.print("},");

  // Gyroscope
  Serial.print("\"gyroscope\":{\"x\":"); Serial.print(gyro.gyro.x, 2);
  Serial.print(",\"y\":"); Serial.print(gyro.gyro.y, 2);
  Serial.print(",\"z\":"); Serial.print(gyro.gyro.z, 2); Serial.print("},");

  // Linear acceleration
  Serial.print("\"linear_accel\":{\"x\":"); Serial.print(linearAccel.acceleration.x, 2);
  Serial.print(",\"y\":"); Serial.print(linearAccel.acceleration.y, 2);
  Serial.print(",\"z\":"); Serial.print(linearAccel.acceleration.z, 2); Serial.print("},");

  // Magnetometer
  Serial.print("\"magnetometer\":{\"x\":"); Serial.print(magnetometer.magnetic.x, 2);
  Serial.print(",\"y\":"); Serial.print(magnetometer.magnetic.y, 2);
  Serial.print(",\"z\":"); Serial.print(magnetometer.magnetic.z, 2); Serial.print("},");

  // Raw acceleration
  Serial.print("\"acceleration\":{\"x\":"); Serial.print(accel.acceleration.x, 2);
  Serial.print(",\"y\":"); Serial.print(accel.acceleration.y, 2);
  Serial.print(",\"z\":"); Serial.print(accel.acceleration.z, 2); Serial.print("},");

  // Gravity vector
  Serial.print("\"gravity\":{\"x\":"); Serial.print(gravity.acceleration.x, 2);
  Serial.print(",\"y\":"); Serial.print(gravity.acceleration.y, 2);
  Serial.print(",\"z\":"); Serial.print(gravity.acceleration.z, 2); Serial.print("},");

  // Temperature and calibration
  Serial.print("\"temperature\":"); Serial.print(temperature); Serial.print(",");
  Serial.print("\"calibration\":{\"sys\":"); Serial.print(sys);
  Serial.print(",\"gyro\":"); Serial.print(gyroCal);
  Serial.print(",\"accel\":"); Serial.print(accelCal);
  Serial.print(",\"mag\":"); Serial.print(magCal); Serial.print("}");

  Serial.println("}");
  delay(BNO055_SAMPLERATE_DELAY_MS);
}