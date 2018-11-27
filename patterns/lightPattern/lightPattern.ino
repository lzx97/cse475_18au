

#include <Adafruit_NeoPixel_ZeroDMA.h>
#define PIXEL_PIN    19    // Digital IO pin connected to the NeoPixels.
#define VBATPIN A7

#define PIXEL_COUNT 16.
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_FeatherOLED.h>


Adafruit_SSD1306 display = Adafruit_SSD1306();

Adafruit_NeoPixel_ZeroDMA strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRBW);


void setup() {
  // put your setup code here, to run once:
  delay(100);


  strip.begin();
  strip.setBrightness(24);
  strip.show(); // Initialize all pixels to 'off'
  colorWipe(strip.Color(0, 0, 0), 5);    // Black/off

  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Active 3");
  display.setCursor(0, 0);
  display.display();
  for (int i = 0; i < 20; i++) {
    RunningLights(0xff, 0xff, 0x0, 70);
  }
/*
  // active;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Active 1");
  display.setCursor(0, 0);
  display.display();
  theaterChaseRainbow(50);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Active 2");
  display.setCursor(0, 0);
  display.display();
  for (int i = 0; i < 20; i++) {
    CylonBounce(0x6f, 0xff, 0xf3, 2, 25, 50);
  }


  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Active 3");
  display.setCursor(0, 0);
  display.display();
  for (int i = 0; i < 20; i++) {
    RunningLights(0x14, 0xff, 0x72, 30);
  }


  // amibient
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Ambient 1");
  display.setCursor(0, 0);
  display.display();
  for (int i = 0; i < 10; i++) { 
    meteorRain(0x95, 0xff, 0x44, 5, 128, true, 100);
  }

  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Ambient 2");
  display.setCursor(0, 0);
  display.display();
  for (int i = 0; i < 20; i++) {
    RGBLoop();
  }
  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Ambient 3");
  display.setCursor(0, 0);
  display.display();
  for (int i = 0; i < 20; i++) {
    Twinkle(0, 0xff, 0, 8, 250, false);
  } 

  // startle
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Startle");
  display.setCursor(0, 0);
  display.display();
  for (int i = 0; i < 10; i++) {
    Strobe(0xff, 0x00, 0x00, 10, 50, 1000);
  }
  */
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void setAll(uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < strip.numPixels(); i++ ) {
    strip.setPixelColor(i, strip.Color(red, green, blue));
  }
  strip.show();
}


void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {

  for (int i = 0; i < strip.numPixels() - EyeSize - 2; i++) {
    setAll(0, 0, 0);
    strip.setPixelColor(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      strip.setPixelColor(i + j, red, green, blue);
    }
    strip.setPixelColor(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    strip.show();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for (int i = strip.numPixels() - EyeSize - 2; i > 0; i--) {
    setAll(0, 0, 0);
    strip.setPixelColor(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++) {
      strip.setPixelColor(i + j, red, green, blue);
    }
    strip.setPixelColor(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    strip.show();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);
}

void theaterChaseRainbow(int SpeedDelay) {
  byte *c;

  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        c = Wheel( (i + j) % 255);
        strip.setPixelColor(i + q, *c, *(c + 1), *(c + 2)); //turn every third pixel on
      }
      strip.show();

      delay(SpeedDelay);

      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0, 0, 0);    //turn every third pixel off
      }
    }
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];

  if (WheelPos < 85) {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  } else {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }

  return c;
}






void meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
  setAll(0, 0, 0);

  for (int i = 0; i < strip.numPixels() + strip.numPixels(); i++) {


    // fade brightness all LEDs one step
    for (int j = 0; j < strip.numPixels(); j++) {
      if ( (!meteorRandomDecay) || (random(10) > 5) ) {
        fadeToBlack(j, meteorTrailDecay );
      }
    }

    // draw meteor
    for (int j = 0; j < meteorSize; j++) {
      if ( ( i - j < strip.numPixels()) && (i - j >= 0) ) {
        strip.setPixelColor(i - j, red, green, blue);
      }
    }

    strip.show();
    delay(SpeedDelay);
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
  uint32_t oldColor;
  uint8_t r, g, b;
  int value;

  oldColor = strip.getPixelColor(ledNo);
  r = (oldColor & 0x00ff0000UL) >> 16;
  g = (oldColor & 0x0000ff00UL) >> 8;
  b = (oldColor & 0x000000ffUL);

  r = (r <= 10) ? 0 : (int) r - (r * fadeValue / 256);
  g = (g <= 10) ? 0 : (int) g - (g * fadeValue / 256);
  b = (b <= 10) ? 0 : (int) b - (b * fadeValue / 256);

  strip.setPixelColor(ledNo, r, g, b);

}


void RGBLoop() {
  for (int j = 0; j < 3; j++ ) {
    // Fade IN
    for (int k = 0; k < 256; k++) {
      switch (j) {
        case 0: setAll(k, 0, 0); break;
        case 1: setAll(0, k, 0); break;
        case 2: setAll(0, 0, k); break;
      }
      strip.show();
      delay(3);
    }
    // Fade OUT
    for (int k = 255; k >= 0; k--) {
      switch (j) {
        case 0: setAll(k, 0, 0); break;
        case 1: setAll(0, k, 0); break;
        case 2: setAll(0, 0, k); break;
      }
      strip.show();
      delay(3);
    }
  }
}

void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause) {
  for (int j = 0; j < StrobeCount; j++) {
    setAll(red, green, blue);
    strip.show();
    delay(FlashDelay);
    setAll(0, 0, 0);
    strip.show();
    delay(FlashDelay);
  }

  delay(EndPause);
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int j = 0; j < strip.numPixels() * 2; j++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < strip.numPixels(); i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      strip.setPixelColor(i, ((sin(i + Position) * 127 + 128) / 255)*red,
                          ((sin(i + Position) * 127 + 128) / 255)*green,
                          ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    strip.show();
    delay(WaveDelay);
  }
}

void Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0, 0, 0);

  for (int i = 0; i < Count; i++) {
    strip.setPixelColor(random(strip.numPixels()), red, green, blue);
    strip.show();
    delay(SpeedDelay);
    if (OnlyOne) {
      setAll(0, 0, 0);
    }
  }

  delay(SpeedDelay);
}
