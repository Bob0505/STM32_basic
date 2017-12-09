/**
 * STM32F103C8T6 basic code
 *
 * @author Bob Chen (bob-0505@gotmail.com)
 * @date 25 November 2017
 * https://github.com/Bob0505/E32-TTL-100
 */

#define LED_PIN           PC13
#define SERIAL_BAUD       115200

//The setup function is called once at startup of the sketch
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(SERIAL_BAUD);
  Serial.println("STM32 - Setup");
}

// The loop function is called in an endless loop
void loop()
{
  Serial.println("STM32 - loop");

  digitalWrite(LED_PIN, HIGH);	// turn the LED off by making the voltage HIGH
  delay(1000);
  digitalWrite(LED_PIN, LOW);	// turn the LED on  by making the voltage LOW
  delay(500);
}
