// FastLED - generates PWM signals for LED strips
#include <FastLED.h>

// white palette
CRGBPalette16 White_p(
  CRGB::White,CRGB::White,CRGB::White,CRGB::White,
  CRGB::White,CRGB::White,CRGB::White,CRGB::White,
  CRGB::White,CRGB::White,CRGB::White,CRGB::White,
  CRGB::White,CRGB::White,CRGB::White,CRGB::White
);

// red palette
CRGBPalette16 Red_p(
  CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,
  CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,
  CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,
  CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red
);

// gold palette
CRGBPalette16 Gold_p(
  CRGB::Gold,CRGB::Gold,CRGB::Gold,CRGB::Gold,
  CRGB::Gold,CRGB::Gold,CRGB::Gold,CRGB::Gold,
  CRGB::Gold,CRGB::Gold,CRGB::Gold,CRGB::Gold,
  CRGB::Gold,CRGB::Gold,CRGB::Gold,CRGB::Gold
);

// blue palette
CRGBPalette16 Blue_p(
  CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue,
  CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue,
  CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue,
  CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue
);

// purple palette
CRGBPalette16 Purple_p(
  0xFF00FF,0xFF00FF,0xFF00FF,0xFF00FF,
  0xFF00FF,0xFF00FF,0xFF00FF,0xFF00FF,
  0xFF00FF,0xFF00FF,0xFF00FF,0xFF00FF,
  0xFF00FF,0xFF00FF,0xFF00FF,0xFF00FF
);

// sakurairo palette
CRGBPalette16 Sakura_p(
  0xE44B8D,0xE44B8D,0xE44B8D,0xE44B8D,
  0xE44B8D,0xE44B8D,0xE44B8D,0xE44B8D,
  0xE44B8D,0xE44B8D,0xE44B8D,0xE44B8D,
  0xE44B8D,0xE44B8D,0xE44B8D,0xE44B8D
);

// sakura-purple palette
CRGBPalette16 SakuraPurple_p(
  0xFF00FF,0xE44B8D,0xFF00FF,0xE44B8D,
  0xFF00FF,0xE44B8D,0xFF00FF,0xE44B8D,
  0xFF00FF,0xE44B8D,0xFF00FF,0xE44B8D,
  0xFF00FF,0xE44B8D,0xFF00FF,0xE44B8D
);

// kitsune palette
CRGBPalette16 Kitsune_p(
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::Gold,
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::Gold,
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::Gold,
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::Gold
);

// japanese flag palette
CRGBPalette16 Japan_p(
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::White,
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::White,
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::White,
  CRGB::Red,CRGB::Red,CRGB::White,CRGB::White
);