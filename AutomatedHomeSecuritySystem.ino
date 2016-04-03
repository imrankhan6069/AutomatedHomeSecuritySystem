#define CUSTOM_SETTINGS
#define INCLUDE_BUZZER_SHIELD  // Calling of library classes for 
#define INCLUDE_CAMERA_SHIELD //the functions needed for the  
#define INCLUDE_EMAIL_SHIELD // virtualization of shields on the 1sheeld android app

#define trigPin 6 
#define echoPin 5
#include <OneSheeld.h>
//declaration of varibles for leds
int led = 13;
int led2 = 12;
int led3 = 11;
int duration, distance;//declare distance and duration as integers;

void setup() 
{
  // put your setup code here, to run once:
  //serial monitor and pin setup. 
  Serial.begin(115200);
  OneSheeld.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  //Scheduler.startLoop(loop2);

}

void loop() 
{

  ultrasonic();
  if(distance > 0 && distance <= 30.0 )// We have chosen to use 30 cm as the distance to trigger the system. This can be increased to desired distance
  {
    Serial.print("Trigger at :");
    Serial.println(distance);

    
    Camera.setFlash(ON);
    Camera.rearCapture();
    delay(5000);
    Camera.setFlash(OFF);
    //recipient, subject, message
    Email.attachLastPicture("gets83hit@photos.flickr.com","Presence detected","Intruder Alert");
    
    Buzzer.buzzOn();

      for (int i=1; i<=10; i++)
      {
        blinktimer();
       delay(1000);  
      }
    
    Buzzer.buzzOff();
    delay(30000);
    //turns off leds, 
    //ultrasonic sensor and buzzer for 30seconds. 
    //After this, the ultrasonic sensor is turned on and 
    //stays on until it is triggered again
   
  }

}

void ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);// send out signal
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);// then goes low

  duration = pulseIn(echoPin, HIGH);
  distance=(duration/2)/29.1; //  the 29.1 is used to convert the distance to cm, the value varies for other units.
  Serial.println(distance);
}


void blinktimer()//Method to make led blink when ultasonic sensor is triggered
{
    digitalWrite(led, HIGH); //blink
    delay(100);               // wait for a second
    digitalWrite(led, LOW);
    delay(100);
   
    digitalWrite(led2, HIGH);//blink
    delay(100);               // wait for a second
    digitalWrite(led2, LOW);
    delay(100);
    
    digitalWrite(led3, HIGH); //blink
    delay(100);               // wait for a second
    digitalWrite(led3, LOW);
    delay(100);
  
}
