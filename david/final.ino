#include <Wire.h>
#include <SparkFunBME280.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include <SoftwareSerial.h>
#include <TinyGPS.h>

MPU6050 accelgyro; //suzdava obekt ot tip MPU6050

int16_t ax, ay, az;
int16_t gx, gy, gz;


bool blinkState = false;
BME280 mySensor; //Uses I2C address 0x76 (jumper closed)

TinyGPS gps; //suzdava obekt ot tip TinyGPS
SoftwareSerial ss(1, 2); // RX|TX


void setup()
{
  Serial.begin(115200);
  Wire.begin();
  ss.begin(4800);

  mySensor.setI2CAddress(0x76); //Zadava adresa na BMP senzora
  if(mySensor.beginI2C() == false) Serial.println("BMP Sensor  connect failed");
  
    accelgyro.initialize();// inicializira MPU6050 sensora

    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop()
{
  Serial.println("====BMP280 Pressure====");
  Serial.print(" Humidity: ");
  Serial.print(mySensor.readFloatHumidity(), 0);//4ete stoinostta na vlajnostta i q printira

  Serial.print(" Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 0);// 4ete stoinostta na nalqganeto i q printira

  Serial.print(" Temp: ");
  Serial.print(mySensor.readTempC(), 2);// 4ete stoinostta na temperaturata i q printira 
  Serial.println();
  
  Serial.println("====MPU Gyro====");
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);// vzima stoinostite na razli4nite uskoreniq po razli4nite osi

    Serial.print("a/g:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");
    Serial.print(gx); Serial.print("\t");
    Serial.print(gy); Serial.print("\t");
    Serial.println(gz);

  Serial.println("====GPS===="); 
  bool newData = false; // buleva promenliva koqto sledi dali ima danni ili ne
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 100;) //cikul koito se izpalnqva 100 milisekundi
  {
    while (ss.available())
    {
      char c = ss.read(); //4ete bufera na ustroistvoto
      // Serial.write(c); 
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;// ako ima nova informaciq bulevata promenliva stava istina
    }
  }

  gps.stats(&chars, &sentences, &failed); //vzima infoto ot gps-a
  Serial.print(" CHARS=");
  Serial.print(chars);
  Serial.print(" SENTENCES=");
  Serial.print(sentences);
  Serial.print(" CSUM ERR=");
  Serial.println(failed);
  if (chars == 0) //proverqva dali ima polu4ena informaciq. ako nqma izpisva dolnata greshka
    Serial.println("** No characters received from GPS: check wiring **");

  delay(1000);
}
