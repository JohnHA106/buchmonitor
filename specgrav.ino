/*
 *  Mandatory includes
 */
#include <Arduino.h>
#include <TinyMPU6050.h>

/*
 *  Constructing MPU-6050
 */
MPU6050 mpu (Wire);

/*
 *  Method that prints everything
 */
void PrintGets () {
  // Shows offsets
  Serial.println("--- Offsets:");
  Serial.print("GyroX Offset = ");
  Serial.println(mpu.GetGyroXOffset());
  Serial.print("GyroY Offset = ");
  Serial.println(mpu.GetGyroYOffset());
  Serial.print("GyroZ Offset = ");
  Serial.println(mpu.GetGyroZOffset());
  // Shows raw data
  Serial.println("--- Raw data:");
  Serial.print("Raw AccX = ");
  Serial.println(mpu.GetRawAccX());
  Serial.print("Raw AccY = ");
  Serial.println(mpu.GetRawAccY());
  Serial.print("Raw AccZ = ");
  Serial.println(mpu.GetRawAccZ());
  Serial.print("Raw GyroX = ");
  Serial.println(mpu.GetRawGyroX());
  Serial.print("Raw GyroY = ");
  Serial.println(mpu.GetRawGyroY());
  Serial.print("Raw GyroZ = ");
  Serial.println(mpu.GetRawGyroZ());
  // Show readable data
  Serial.println("--- Readable data:");
  Serial.print("AccX = ");
  Serial.print(mpu.GetAccX());
  Serial.println(" m/s²");
  Serial.print("AccY = ");
  Serial.print(mpu.GetAccY());
  Serial.println(" m/s²");
  Serial.print("AccZ = ");
  Serial.print(mpu.GetAccZ());
  Serial.println(" m/s²");
  Serial.print("GyroX = ");
  Serial.print(mpu.GetGyroX());
  Serial.println(" degrees/second");
  Serial.print("GyroY = ");
  Serial.print(mpu.GetGyroY());
  Serial.println(" degrees/second");
  Serial.print("GyroZ = ");
  Serial.print(mpu.GetGyroZ());
  Serial.println(" degrees/second");
  // Show angles based on accelerometer only
  Serial.println("--- Accel angles:");
  Serial.print("AccelAngX = ");
  Serial.println(mpu.GetAngAccX());
  Serial.print("AccelAngY = ");
  Serial.println(mpu.GetAngAccY());
  // Show angles based on gyroscope only
  Serial.println("--- Gyro angles:");
  Serial.print("GyroAngX = ");
  Serial.println(mpu.GetAngGyroX());
  Serial.print("GyroAngY = ");
  Serial.println(mpu.GetAngGyroY());
  Serial.print("GyroAngZ = ");
  Serial.println(mpu.GetAngGyroZ());
  // Show angles based on both gyroscope and accelerometer
  Serial.println("--- Filtered angles:");
  Serial.print("FilteredAngX = ");
  Serial.println(mpu.GetAngX());
  Serial.print("FilteredAngY = ");
  Serial.println(mpu.GetAngY());
  Serial.print("FilteredAngZ = ");
  Serial.println(mpu.GetAngZ());
  // Show filter coefficients
  Serial.println("--- Angle filter coefficients:");
  Serial.print("Accelerometer percentage = ");
  Serial.print(mpu.GetFilterAccCoeff());
  Serial.println('%');
  Serial.print("Gyroscope percentage = ");
  Serial.print(mpu.GetFilterGyroCoeff());
  Serial.println('%');
}

void calculateSG() { ///this borrows heavily from https://github.com/s60sc/ESP32_SpecificGravity/blob/master/ESP32_SpecificGravity.ino#L1
  double AngXYZ = sqrt(pow(mpu.GetAngX(),2)+ pow(mpu.GetAngY(),2) + pow(mpu.GetAngZ(),2));
  Serial.println("AngXYZ");
  double specGrav = (mpu.GetAngX() / AngXYZ);
  Serial.println("Specific Gravity Tilt Angle =");
  Serial.print(specGrav);
}


/*
 *  Setup
 */
void setup() {

  // Initialization
  mpu.Initialize();

  // Calibration
  Serial.begin(9600);
  Serial.println("=====================================");
  Serial.println("Starting calibration...");
  mpu.Calibrate();
  Serial.println("Calibration complete!");
}

/*
 *  Loop
 */
void loop() {
  
  mpu.Execute();
  PrintGets();
  Serial.println("Specific Gravity Tilt Angle =");
  Serial.print(mpu.GetAngX() / (sqrt(pow(mpu.GetAngX(),2)+ pow(mpu.GetAngY(),2) + pow(mpu.GetAngZ(),2))));
  delay(10000); // 10 sec delay

}
