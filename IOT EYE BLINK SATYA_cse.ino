#define BLYNK_TEMPLATE_ID           "TMPL3TDlksDO0"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "p73Ks-DkHEIX9Op0ft23mBuzARTRdtX3"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Project";
char pass[] = "project123";
int flag=0;
int t1=0;
int t2=0;
int count=0;
BlynkTimer timer;


void myTimerEvent()
  
  {
     Blynk.virtualWrite(V2,"IoT Based Eye  blynk Detection");
   Blynk.virtualWrite(V3,"Satyajeet,Akash,Suraj");
   Blynk.virtualWrite(V4," Dr.A.J.Shikalgar");
 int x=analogRead(A0);
   if(x<400 && flag==0)
    {
    flag=1;
    t1=millis();
   }
 else if(x>400 && flag==1)
   {
    flag=0;
    t2=millis();
      int rohan=(t2-t1);
    Serial.println(rohan);
  if(rohan>1000)
    {
      count=count+1;
      
      digitalWrite(D1,HIGH);
      Serial.println("Alert2!!!!!!!!!!!!!!!!!");
      delay(1000);
      digitalWrite(D1,LOW);
       delay(1000);
       Blynk.virtualWrite(V0,count);
       Blynk.virtualWrite(V1,rohan/1000);
       Blynk.logEvent("aleart", "Driver is Sleeping");
       delay(2000);
    }
    else
    {
     } 
}
  
  } 


void setup()
{
  // Debug console
  Serial.begin(115200);
 pinMode(D1,OUTPUT);
  pinMode(A0,INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  
}
