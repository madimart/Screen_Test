
#include <Wire.h>                // I2C
#include <Adafruit_GFX.h>        // SCREEN 
#include <Adafruit_SSD1306.h>    // SCREEN 

#define   SCREEN_WIDTH      128  // SSD1306 Width  (Pixels)
#define   SCREEN_HEIGHT     64   // SSD1306 Height (Pixels)
#define   OLED_RESET        -1   // Reset pin #, -1 if sharing reset pin
#define   SCREEN_ADDRESS    0x3C // 

// SERIAL
      void SERIAL_Setup(){
        Serial.begin(115200);
        Serial.println("Serial connection enabled.");
      }
// SCREEN
      Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

      void SCREEN_Setup(){
        if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
          Serial.println(F("SSD1306 allocation failed"));
          while (1) delay(10);
        }
        Serial.println("SSD1306 Found");
      }
      
void setup() {
    SERIAL_Setup();
    SCREEN_Setup();
}

void loop() {
  test_Print();
  Serial.println("Sent test_Print to screen.");
  delay(2000);
}

void test_Print(){
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(2);
      display.setCursor(0,0);
      display.println("SSD1306");
      display.setTextSize(1);
      display.println(" ");
      display.println("Hopefully this works!");
      display.println(" ");
      display.println("Is this thing on?");
      display.println(" ");
      display.println("Good Luck!");
      display.display();
}
