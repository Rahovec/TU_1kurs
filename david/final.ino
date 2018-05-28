#include <Wire.h>
#include <SparkFunBME280.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include <SoftwareSerial.h>
#include <TinyGPS.h>

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;


bool blinkState = false;
BME280 mySensor; //Uses I2C address 0x76 (jumper closed)

TinyGPS gps;
SoftwareSerial ss(1, 2); // RX|TX


void setup()
{
  Serial.begin(115200);
  Wire.begin();
  ss.begin(4800);

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

  Serial.println("====GPS====");
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 100;)
  {
    while (ss.available())
    {
      char c = ss.read();
      // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }

  gps.stats(&chars, &sentences, &failed);
  Serial.print(" CHARS=");
  Serial.print(chars);
  Serial.print(" SENTENCES=");
  Serial.print(sentences);
  Serial.print(" CSUM ERR=");
  Serial.println(failed);
  if (chars == 0)
    Serial.println("** No characters received from GPS: check wiring **");

  delay(1000);
}
