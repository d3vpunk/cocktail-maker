#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Fonts/FreeSans12pt7b.h>


#define TFT_SCK    18
#define TFT_MOSI   23
#define TFT_MISO   19
#define TFT_CS     22
#define TFT_DC     21
#define TFT_RESET  17

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RESET);

void renderNavigationText(); // Declare the function
void renderStop();
void renderNavigationBar();

void setup() {
  tft.begin();
  tft.setRotation(1);
  //tft.fillScreen(ILI9341_WHITE); // Set background color to white
  tft.fillScreen(ILI9341_BLACK); // Set background color to black
  renderStop();
  renderNavigationBar();
  renderNavigationText();
}

void renderNavigationText() {
  
  tft.setFont(&FreeSans12pt7b);
  tft.setTextColor(ILI9341_WHITE);  

  tft.setCursor(60, 38);           
  tft.println("Osborne-Cola!!");

  tft.setTextColor(0xBDF6);  

  tft.setCursor(60, 74);           
  tft.println("Cuba-Libre");      

  tft.setCursor(60, 110);            
  tft.println("Tequila-Sunrise");      

  tft.setCursor(60, 146);            
  tft.println("Caipirinha");     

  tft.setCursor(60, 186);            
  tft.println("Pina Colada");      

}

void renderStop() {
  int centerX = 290; 
  int centerY = 210; 
  int outerRadius = 20; 
  int innerRadius = 14;  
  int rectWidth = 10;    
  int rectHeight = 10;  
  int cornerRadius = 2; 

  tft.fillCircle(centerX, centerY, outerRadius, 0xA000);

  tft.fillCircle(centerX, centerY, innerRadius, ILI9341_BLACK);

  int rectX = centerX - rectWidth / 2;
  int rectY = centerY - rectHeight / 2;

  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, 0xA000);
}

void renderNavigationBar() {
  int bodyX = 0;
  int bodyY = 10; 
  int bodyWidth = 40; 
  int bodyHeight = 220;
  int bodyCornerRadius = 50;
  
  // schwarzer kreis
  int circleCenterX = bodyX + bodyWidth / 2; 
  int circleCenterY = bodyY + 20; 
  int circleRadius = 15; 

  // icon im kreis
  int iconWidth = 20; 
  int iconHeight = 10; 
  int iconCornerRadius = 2; 
  int iconX = circleCenterX - iconWidth / 2;
  int iconY = circleCenterY - iconHeight / 2;

  tft.fillRoundRect(bodyX, bodyY, bodyWidth, bodyHeight, bodyCornerRadius, ILI9341_WHITE);
  tft.fillCircle(circleCenterX, circleCenterY, circleRadius, ILI9341_BLACK);
  tft.fillRoundRect(iconX, iconY, iconWidth, iconHeight, iconCornerRadius, ILI9341_WHITE);
}

void loop() {
}



