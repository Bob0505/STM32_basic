/**
 * STM32F103C8T6 basic code
 *
 * @author Bob Chen (bob-0505@gotmail.com)
 * @date 25 November 2017
 * https://github.com/Bob0505/E32-TTL-100
 */
//https://github.com/JChristensen/Timer
#include <Timer.h>

#define LED_PIN           PC13
#define SERIAL_BAUD       115200

//Timer Task_1s;
Timer Task_500ms;

void UpdateLed()
{
  static bool LED_Status;

  digitalWrite(LED_PIN, LED_Status);	// turn the LED off by making the voltage HIGH
  LED_Status = !LED_Status;
}

void task_500ms()
{
	UpdateLed();
}

//The setup function is called once at startup of the sketch
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(SERIAL_BAUD);
  Serial.println("STM32 - Setup");

  Task_500ms.every(150, task_500ms);
}

// The loop function is called in an endless loop
void loop()
{
  Serial.println("STM32 - loop");
  Task_500ms.update();

}
