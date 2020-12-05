/* Modified code by ScottyD www.youtube.com/channel/UCLx3Gi9s_5uvVwURRIsWXKg
 * 
 * Carbon Dioxide Parts Per Million Meter
 * CO2PPM
 
 * Original code by www.youtube.com/c/learnelectronics
/*
 * Atmospheric CO2 Level..............400ppm
 * Average indoor co2.............350-450ppm
 * Maxiumum acceptable co2...........1000ppm
 * Dangerous co2 levels.............>2000ppm
 */
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define anInput     A0                        //analog feed from MQ135
#define co2Zero     -307                        //calibrated CO2 0 level - outside the reading was ~105 when this is set to zero, this is value required to bring it to the average for my area on the date tested, which was 412 ppm
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 7 on the Arduino 
#define ONE_WIRE_BUS 9 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() 
{
  pinMode(anInput,INPUT);                     //MQ135 analog feed set for input
  Serial.begin(9600); 
  sensors.begin();                            //this is required to begin taking data from the temp sensor

  lcd.begin(2, 2);
  lcd.print("let's brew!");

 


}
  
void loop() 
{
  ////this code is all for co2 measuring/////
  int co2now[10];                               //int array for co2 readings
  int co2raw = 0;                               //int for raw value of co2
  int co2ppm = 0;                               //int for calculated ppm
  int zzz = 0;                                  //int for averaging


  for (int x = 0;x<10;x++)  //samplpe co2 10x over 2 seconds
  {                   
    co2now[x]=analogRead(A0);
    delay(200);
  }

  for (int x = 0;x<10;x++)  //add samples together
  {                     
    zzz=zzz + co2now[x];  
  }
  
  co2raw = zzz/10;                            //divide samples by 10
  co2ppm = co2raw - co2Zero;                 //get calculated ppm

  Serial.print("CO2 ppm =");
  Serial.print(co2ppm);  // prints the value read
  Serial.println(" PPM");
  lcd.setCursor(0, 0);
  lcd.print("CO2:  ");
  lcd.print(co2ppm);
  lcd.print(" PPM");
  

////now temp sensing////


  // request to all devices on the bus 
/********************************************************************/
 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 Serial.println("DONE"); 
/********************************************************************/
 Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
lcd.setCursor(0, 1);
lcd.print("Temp: ");
lcd.print(sensors.getTempCByIndex(0));
lcd.print(" C");
 
  delay(1000);    

  

}
