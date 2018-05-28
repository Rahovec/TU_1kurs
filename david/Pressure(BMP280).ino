
#include <Wire.h>

#include <SparkFunBME280.h>
BME280 mySensor; //Uses I2C address 0x76 (jumper closed)

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  mySensor.setI2CAddress(0x76); //Connect to a second sensor
  if(mySensor.beginI2C() == false) Serial.println("BMP Sensor  connect failed");
}

void loop()
{
  Serial.print(" Humidity: ");
  Serial.print(mySensor.readFloatHumidity(), 0);

  Serial.print(" Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 0);

  Serial.print(" Temp: ");
  Serial.print(mySensor.readTempC(), 2);

  Serial.println();

  delay(50);
}
