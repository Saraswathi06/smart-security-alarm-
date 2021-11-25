#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "fhYZ1X4c52NHIpJAIQIyHOf5GJUf0t63"; //Auth code sent via Email
char ssid[] = "DMR"; //Wifi name
char pass[] = "dmr@2021";  //Wifi Password
int flag=0;
void notifyOnThings()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println(" Intruder Detected");
    Blynk.notify("Alert : Intruder Detected");
    flag=1;
  }
  else if (isButtonPressed==0)
  { 
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass); 
pinMode(D1,INPUT_PULLUP);
timer.setInterval(1000,notifyOnThings); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
