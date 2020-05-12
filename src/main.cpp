/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

static const int DELAY_VALUE = 1400;

#include <Arduino.h>
int main()
{

  /*init();

  Serial.begin(115200);
  pinMode(13, OUTPUT);
  int pin = HIGH;
  for(;;)
  {
    Serial.println("Hello");
    digitalWrite(13, pin);
    (pin == HIGH) ? (pin = LOW) : (pin = HIGH);
    delay(1000);
  }
  return 0;*/

  init();

  setup();
  while (true) {
    loop();
  }
}

#define LED1 13
#define LED2 SCL
#define LED3 10

// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(115200);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
  Serial.println("Hello");

  digitalWrite(LED1, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(LED2, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(LED3, LOW);// turn the LED off by making the voltage LOW
  delay(DELAY_VALUE);// wait for a second
  //  for (int i = 0; i < 100000; ++i) {
  //    __asm__ __volatile__ ("nop\n\t");
  //  }
  digitalWrite(LED1, LOW);// turn the LED off by making the voltage LOW
  digitalWrite(LED2, LOW);// turn the LED off by making the voltage LOW
  digitalWrite(LED3, HIGH);// turn the LED on (HIGH is the voltage level)
  delay(DELAY_VALUE);// wait for a second
  //  for (int i = 0; i < 100000; ++i) {
  //    __asm__ __volatile__ ("nop\n\t");
  //  }
}