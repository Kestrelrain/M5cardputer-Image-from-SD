#include <SD.h>
#include <M5GFX.h>
#include <SPI.h>
#include "M5Cardputer.h"

void setup(void) {
    auto cfg = M5.config();
    M5Cardputer.begin(cfg);
  
    SPI.begin(
      M5.getPin(m5::pin_name_t::sd_spi_sclk),
      M5.getPin(m5::pin_name_t::sd_spi_miso),
      M5.getPin(m5::pin_name_t::sd_spi_mosi),
      M5.getPin(m5::pin_name_t::sd_spi_ss));
    while (false == SD.begin(M5.getPin(m5::pin_name_t::sd_spi_ss), SPI)) {
      delay(1);
    }
    
    M5.Lcd.setRotation(1);
    // Draw the jpeg file "p2.jpg" from TF(SD) card
    M5.Lcd.setBrightness(200);
    
    M5.Lcd.drawPngFile(SD, "/filename.png");
    
    // M5.Lcd.drawJpgFile(SD, "/p1.jpg", 20, 30, 40, 50);

    
    // M5.Lcd.drawJpgFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y,
    // uint16_t maxWidth, uint16_t maxHeight, uint16_t offX, uint16_t offY,
    // jpeg_div_t scale);
}

void loop() {
   //M5.Lcd.drawBmpFile(SD, "/filename.bmp");
   //M5.Lcd.drawJpgFile(SD, "/filename.jpg");
   M5.Lcd.drawPngFile(SD, "/filename.png");
}
