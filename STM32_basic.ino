/**
 * STM32F103C8T6 basic code
 *
 * @author Bob Chen (bob-0505@gotmail.com)
 * @date 25 November 2017
 * https://github.com/Bob0505/E32-TTL-100
 */
//https://github.com/JChristensen/Timer
#include <Timer.h>
#include <SPI.h>
#include <Wire.h>

//https://github.com/adafruit/Adafruit-GFX-Library
//#define SSD1306_128_64
#include <Adafruit_GFX.h>
//https://github.com/adafruit/Adafruit_SSD1306
#include <Adafruit_SSD1306.h>

#define LED_PIN           PC13
#define SERIAL_BAUD       115200

// Uncomment this block to use hardware SPI
//#define BOARD_SPI1_SCK_PIN        PA5		@ board.h
//#define BOARD_SPI1_MOSI_PIN       PA7		@ board.h
#define OLED_RESET  PA3
#define OLED_DC     PA2
#define OLED_CS     0xFF
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

Timer Tasks;


#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void InvLed()
{
  static bool LED_Status = true;

  digitalWrite(LED_PIN, LED_Status);	// turn the LED off by making the voltage HIGH
  LED_Status = !LED_Status;
}

void InvOLED()
{
  static bool OLED_Inv_status = true;

  display.invertDisplay(OLED_Inv_status);
  OLED_Inv_status = !OLED_Inv_status;
}

void stopAfter3s()
{
  display.stopscroll();
}

void InvScroll(void)
{
  static bool Scroll_Inv_status = true;

  if(Scroll_Inv_status)
  {
    display.startscrollright(0x00, 0x0F);
  }
  else
  {
    display.startscrollleft(0x00, 0x0F);
  }

  Tasks.after(3000, stopAfter3s);

  Scroll_Inv_status = !Scroll_Inv_status;
}

void oled_setup()
{
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();

  display.setTextSize(2);  display.setTextColor(WHITE);  display.setCursor( 0, 0);
  display.clearDisplay();  display.println("scroll");

  // text display tests
  //*y += textsize * 8;
  display.setTextSize(1);  display.setTextColor(WHITE);  display.setCursor(0, 16);
  display.println("[Bob Kara]");
  display.println("AA BB");

  display.display();
}

void task_150ms()
{
  InvLed();
}

void task_1s()
{
  InvOLED();
}

void task_3500ms()
{
  InvScroll();
  Serial.println("B");
}

void task_setup()
{
  Tasks.every( 150, task_150ms);
  Tasks.every(1000, task_1s);
  Tasks.every(3500, task_3500ms);

  task_150ms();
  task_1s();
  task_3500ms();
}

//The setup function is called once at startup of the sketch
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(SERIAL_BAUD);
  Serial.println("STM32 - Setup");
  //SPI OLED Setup
  oled_setup();

  task_setup();
}

// The loop function is called in an endless loop
void loop()
{
  //Serial.println("STM32 - loop");
  Tasks.update();

}
