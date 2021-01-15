#include <FastLED.h>


#define NUM_LEDS 24 
#define DATA_PIN 30

CRGB leds[NUM_LEDS];

void setup() { 
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(60);

  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);  

  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT); 
}


void loop() { 
  
  if (digitalRead(22) == HIGH) {
    digitalWrite(29,HIGH);
    lamps();
  } else { 
    digitalWrite(29,LOW);
    offlamps();  
  }

  if (digitalRead(24) == HIGH) digitalWrite(28,HIGH); else digitalWrite(28,LOW);
  if (digitalRead(23) == HIGH) digitalWrite(27,HIGH); else digitalWrite(27,LOW);
  if (digitalRead(25) == HIGH) digitalWrite(26,HIGH); else digitalWrite(26,LOW);    

 
}

void offlamps() { 
  for(int i = 0; i < NUM_LEDS; i++) { 
    leds[i] = CHSV(0, 0, 0); 
    FastLED.show();
    delay(20);
    } 
}


void lamps() {
    static uint8_t hue = 0; 
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show(); 
    fadeall();
    delay(20);
  }
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }
