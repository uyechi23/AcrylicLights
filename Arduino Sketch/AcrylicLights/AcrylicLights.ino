// include colors.h
#include "colors.h"

// the pins on the Arduino that control the light strips (connected to data pin on strips)
#define LED_PIN_1   3
#define LED_PIN_2   9
#define LED_PIN_3   10
#define LED_PIN_4   11

// the pins on the Arduino that control the buttons to change color palettes
#define BUTTON_1    4
#define BUTTON_2    5
#define BUTTON_3    6
#define BUTTON_4    7

// the number of LEDs on your strip
#define NUM_LEDS    35

// the brightness of the LED strip - max current draw is 60 mA per LED (20 per color)
// IMPORTANT -  sum the total number of lights in the #define statements above and multiply
//              that by 60 mA. That number is the max current draw of your entire LED strip,
//              and should not exceed 90% of your power supply's max current supply
#define BRIGHTNESS  255

// the type of LED strip; you can leave this as-is
#define LED_TYPE    WS2812

// the order of the three colored LEDs on each light; leave this as-is
#define COLOR_ORDER GRB

// the array of LEDs on your strip
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];

// how many updates per second should the strip go through
#define UPDATES_PER_SECOND 100

// this determines what colors are on your LED strip
CRGBPalette16 palette1;
CRGBPalette16 palette2;
CRGBPalette16 palette3;
CRGBPalette16 palette4;
TBlendType    currentBlending;

// an index that increments in the program; this will make the LEDs "breathe"
int colorIndex1 = 0;
int colorIndex2 = 0;
int colorIndex3 = 0;
int colorIndex4 = 0;

// palette index to store the current pattern
int paletteIndex1 = 0;
int paletteIndex2 = 0;
int paletteIndex3 = 0;
int paletteIndex4 = 0;

// palette storage array
#define PALETTE_COUNT   12
CRGBPalette16 palettes[] = {
    White_p, Red_p, Gold_p, Blue_p, Purple_p,
    Sakura_p, Kitsune_p, Japan_p,
    LavaColors_p, OceanColors_p,
    ForestColors_p, RainbowColors_p
};

void setup() {
    // delay for safety
    delay( 1500 );
    // this allows the computer to recognize the LED strip. Sort of like the pinMode() function
    FastLED.addLeds<LED_TYPE, LED_PIN_1, COLOR_ORDER>(leds1, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN_2, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN_3, COLOR_ORDER>(leds3, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN_4, COLOR_ORDER>(leds4, NUM_LEDS).setCorrection( TypicalLEDStrip );
    // sets the brightness of the LEDs
    FastLED.setBrightness( BRIGHTNESS );

    // sets the blending of the LED strip
    currentBlending = LINEARBLEND;

    // set up buttons
    pinMode(BUTTON_1, INPUT);
    pinMode(BUTTON_2, INPUT);
    pinMode(BUTTON_3, INPUT);
    pinMode(BUTTON_4, INPUT);
}


void loop()
{   
    // button check to increment color palettes
    if(digitalRead(BUTTON_1)==HIGH){
      paletteIndex1 = ((paletteIndex1 + 1) % PALETTE_COUNT);
      delay(200);
    }
    if(digitalRead(BUTTON_2)==HIGH){
      paletteIndex2 = ((paletteIndex2 + 1) % PALETTE_COUNT);
      delay(200);
    }
    if(digitalRead(BUTTON_3)==HIGH){
      paletteIndex3 = ((paletteIndex3 + 1) % PALETTE_COUNT);
      delay(200);
    }
    if(digitalRead(BUTTON_4)==HIGH){
      paletteIndex4 = ((paletteIndex4 + 1) % PALETTE_COUNT);
      delay(200);
    }
    
    // fills the LED strip with colors from the palette
    FillLEDs(1, colorIndex1, paletteIndex1);
    FillLEDs(2, colorIndex2, paletteIndex2);
    FillLEDs(3, colorIndex3, paletteIndex3);
    FillLEDs(4, colorIndex4, paletteIndex4);
    
    // increments the index so the next time, the strip color seems to move
    colorIndex1++;
    colorIndex2++;
    colorIndex3++;
    colorIndex4++;

    // shows the LEDs; if you don't have this, the LEDs will update,
    // but the new colors will not appear on the strip
    FastLED.show();

    // delay for a bit; can make the change faster by modifying UPDATES_PER_SECOND
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}


// separate function to fill the LED strip with colors
void FillLEDs( uint8_t stripIndex, uint8_t colorIndex, int paletteIndex )
{
  // sets the brightness of the LEDs
  uint8_t brightness = BRIGHTNESS;

  // change all of the LEDs in the strip one-by-one
  for(int i = 0; i < NUM_LEDS; i++) {
    // leds[i] is a single LED in the strip; 
    if(stripIndex == 1){
      leds1[i] = ColorFromPalette(palettes[paletteIndex], colorIndex, brightness, currentBlending);
    }else if(stripIndex == 2){
      leds2[i] = ColorFromPalette(palettes[paletteIndex], colorIndex, brightness, currentBlending);
    }else if(stripIndex == 3){
      leds3[i] = ColorFromPalette(palettes[paletteIndex], colorIndex, brightness, currentBlending);
    }else if(stripIndex == 4){
      leds4[i] = ColorFromPalette(palettes[paletteIndex], colorIndex, brightness, currentBlending);
    }
    
    // shift the colorIndex so the next LED will be a different color in the palette
    colorIndex += 3;
  }
}
