#define CUSTOM_SETTINGS
#define INCLUDE_CAMERA_SHIELD
#define INCLUDE_EMAIL_SHIELD
#define trigPin 6 
#define echoPin 5
#include <OneSheeld.h>
int led = 13;
int led2 = 12;
int led3 = 11;
//const int trigPin = 6;
//const int echoPin = 5;
int duration, distance;//declare distance and duration as integers;


void setup() 
{
  // put your setup code here, to run once:
  //serial monitor and pin setup. 
  Serial.begin(9600);
  OneSheeld.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Scheduler.startLoop(loop2);

}

void loop() 
{

  ultrasonic();
  if(distance > 0 && distance <= 30.0 )
  {
    Serial.print("Trigger at :");
    Serial.println(distance);
    digitalWrite(led, HIGH);
    delay(100);               // wait for a second
   digitalWrite(led, LOW);
   delay(100);
   
  digitalWrite(led2, HIGH);
  delay(100);               // wait for a second
   digitalWrite(led2, LOW);
   delay(100);
  digitalWrite(led3, HIGH);
  delay(100);               // wait for a second
   digitalWrite(led3, LOW);
   delay(100);
    Camera.setFlash(ON);
    Camera.rearCapture();
    delay(5000);
    Camera.setFlash(OFF);
    //recipient, subject, message
    Email.attachLastPicture("onughachimobi@gmail.com","Presence detected","Intruder Alert");
    delay(30000);
   
  }

}
//void loop2() {
 // digitalWrite(led2, HIGH);
 // delay(100);
 // digitalWrite(led2, LOW);
 // delay(100);
//}
void ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);// trigin send out signal
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);// then goes low

  duration = pulseIn(echoPin, HIGH);
  distance=(duration/2)/29.1; //  the 29.1 is used to convert the distance to cm, the value varies for other units.
  Serial.println(distance);
}
