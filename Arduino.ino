
#include <RH_ASK.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
// Include dependant SPI Library 
#include <SPI.h> 
SoftwareSerial s(5,6); 
//SoftwareSerial p(9,10); 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
String str_out ;
String str_data ;
int data ;
int a ;
int b ;
int c ;
int val = 0; //value for storing moisture value 
int soilPin = A0;//Declare a variable for the soil moisture sensor 
int soilPower = 7;//Variable for Soil moisture Power

void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
    digitalWrite(soilPower, LOW); 
    // Setup Serial Monitor
    s.begin(9600);
    Serial.begin(9600);
}
 int readSoil()
   {
    digitalWrite(soilPower, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
   }
void loop()
{
    
    str_data = String(readSoil()) ;
    b = atoi(str_data.c_str());
    // Set buffer to size of expected message
    uint8_t buf[3];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      str_out = String((char*)buf);
      a = atoi(str_out.c_str());
      data = a+b;
      int c;
     Serial.println(data);
     c=(data>0 && data<50) ? -1 : ((data>50 && data<200) ? 10 : ((data>200 && data<500) ? 20 : 30));
     // c =70 ;
       s.write(c);    
//if((0<data)&&(data<50)){
//       c = 10;
//       s.write(c);}
//      else if((50<data)&&(data<200)){
//       c = 20;
//       s.write(c);}
//      else if((199<data)&&(data<500)){
//         c = 30;
//         s.write(c);}
//      else if((199<data)&&(data<500)){
//       c = 40 ;
//       s.write(c);}
     
         
    }
    //data = a+b;
    
    
//  if(s.available()>0)
//{
//}

}  

