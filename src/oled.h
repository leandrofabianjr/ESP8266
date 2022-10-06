#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI 13
#define OLED_CLK 14
#define OLED_DC 5
#define OLED_CS 15
#define OLED_RESET 4

class Oled {
 public:
  Adafruit_SSD1306 display;
  Oled() {
    display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK,
                               OLED_DC, OLED_RESET, OLED_CS);
  }

  bool begin() {
    if (!display.begin(SSD1306_SWITCHCAPVCC)) {
      return false;
    }

    display.clearDisplay();
    display.display();
    delay(100);
    return true;
  }

  void AllPixels() {
    int i;
    int j;
    display.clearDisplay();
    for (i = 0; i < 128; i++) {
      for (j = 0; j < 64; j++) {
        display.drawPixel(i, j, SSD1306_WHITE);
      }
      display.display();
      delay(20);
    }

    for (i = 0; i < 128; i++) {
      for (j = 0; j < 64; j++) {
        display.drawPixel(i, j, SSD1306_BLACK);
      }
      display.display();
      delay(20);
    }
  }

  void TextDisplay() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(5, 28);
    display.println("Electronics Hub");
    display.display();
    delay(3000);
  }

  void InvertedTextDisplay() {
    display.clearDisplay();
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    display.setCursor(5, 28);
    display.println("Electronics Hub");
    display.display();
    delay(3000);
  }

  void ScrollText() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.println("This is a");
    display.println("Scrolling");
    display.println("Text!");
    display.display();
    delay(100);
    display.startscrollright(0x00, 0x0F);
    delay(2000);
    // display.stopscroll();
    // delay(1000);
    display.startscrollleft(0x00, 0x0F);
    delay(2000);
    // display.stopscroll();
    // delay(1000);
    display.startscrolldiagright(0x00, 0x0F);
    delay(2000);
    display.startscrolldiagleft(0x00, 0x0F);
    delay(2000);
    display.stopscroll();
  }

  void DisplayChars() {
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.cp437(true);

    for (int16_t i = 0; i < 256; i++) {
      if (i == '\n') {
        display.write(' ');
      } else {
        display.write(i);
      }
    }

    display.display();
    delay(3000);
  }

  void TextSize() {
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Size: 1"));
    display.println(F("ABC"));

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println("Size: 2");
    display.println(F("ABC"));

    display.display();
    delay(3000);
  }
};