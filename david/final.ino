
#include <Wire.h>
#include <SparkFunBME280.h>
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;


bool blinkState = false;
BME280 mySensor; //Uses I2C address 0x76 (jumper closed)

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  mySensor.setI2CAddress(0x76); //Connect to a second sensor
  if(mySensor.beginI2C() == false) Serial.println("BMP Sensor  connect failed");
  
    accelgyro.initialize();

    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop()
{
  Serial.println("====BMP280 Pressure====");
  Serial.print(" Humidity: ");
  Serial.print(mySensor.readFloatHumidity(), 0);

  Serial.print(" Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 0);

  Serial.print(" Temp: ");
  Serial.print(mySensor.readTempC(), 2);
  Serial.println();
  
  Serial.println("====MPU Gyro====");
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    Serial.print("a/g:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");
    Serial.print(gx); Serial.print("\t");
    Serial.print(gy); Serial.print("\t");
    Serial.println(gz);

  delay(100);
}
