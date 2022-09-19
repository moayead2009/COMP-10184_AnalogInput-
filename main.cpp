//"I Mouaiad Hejazi,001220081 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else."

#include <Arduino.h>

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
 
  int temp = (50/3.3)*(iVal*3.3/1024);
  // print value to the USB port 

  String status = "";

  if(temp < 10){
    status = "Cold!";
  }else if(temp >= 10 && temp < 15){
    status = "Cool!";
  }else if(temp >= 15 && temp < 25){
    status = "Perfect!";
  }else if(temp >= 25 && temp < 30){
    status = "Warm!";
  }else if(temp >= 30 && temp < 35){
    status = "Hot!";
  }else{
    status = "Too Hot!!";
  }


  Serial.println("Digitized output of " + String(iVal) + 
                " is equivalent to a temperature input of " + 
                temp + " deg. C, which is " + status);




  // wait 0.5 seconds (500 ms) 
  delay(500); 
} 