#define nem1 A2

int sensor1;

#define role 5

#include <Adafruit_NeoPixel.h>
#define led_pin 7
#define pixels 8
Adafruit_NeoPixel led = Adafruit_NeoPixel(pixels, led_pin, NEO_GRB + NEO_KHZ800);

int parlaklik;

int sayac;

void setup() {
led.begin();
pinMode(role,OUTPUT);
digitalWrite(role,HIGH);
sayac=0;
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensor1 = analogRead(nem1);
Serial.print("Nem: ");
Serial.println(sensor1);
parlaklik = analogRead(A0);
Serial.print("Parlaklık: ");
Serial.println(parlaklik);

if(parlaklik<150){
  for(int i=0; i<pixels; i++)
  {
    led.setPixelColor(i, led.Color(250,0,250));
    led.show();  //ledleri yak
  }
  if(sensor1<=140){
    digitalWrite(role,HIGH);
    delay(1000);
    sayac=0;
  }
   if(sensor1>=180){
    digitalWrite(role,LOW);
    delay(1000);
    sayac=1;
  }
}

if(parlaklik>150){
  for(int i=0; i<pixels; i++)
  {
    led.setPixelColor(i, led.Color(0,0,0));
    led.show();  //ledleri yak
  }
  if(sayac==1){
    digitalWrite(role,HIGH);
  }
  
 delay(1000);
}

}
