#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>

#define LED_PIN 3
#define NUM_LEDS 150
#define BRIGHTNESS 50
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];


void setup() {
  //Power up safety
  delay( 3000 );
  //Server for Visual Studios
  Serial.begin(9600);
  Serial.println("STARTING");
  //Fast Leds
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  
  
}

void loop() {
int colourType;
int dataValue;
String dataString;
String data = Serial.readString();
if (data != ""){
  colourType = data.charAt(0);
  Serial.println(colourType);
  dataString = data.substring(1,4);
  Serial.println(dataString);
  dataValue = dataString.toInt();
  Serial.println(dataString);

  
  if (dataValue > 255){dataValue = 255;}
  
  }
  //DATA != 0 END

  if (colourType == 82){    for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(dataValue, 0, 0);
    //Serial.println("RED");
  }}

  if (colourType == 71){    for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, dataValue, 0);
    //Serial.println("GREEN");
  }}

  if (colourType == 66){    for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, dataValue);
    //Serial.println("BLUE");
  }}
  
  FastLED.show();
}
//END OF LOOP


  /*
  String data = String(Serial.readString());
  Serial.println(data);
  if (String(data) == String("ass")){
Serial.println("RUSH B");
for(int i = 0; i < NUM_LEDS; i++)
  {
    Serial.println("What even");
    leds[i] = CRGB(0, 100, 100);
  }
  FastLED.show();

 }*/


  /*
    if (colourPass == "G"){    for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 100, 0);
  }
  FastLED.show(); }
  if (colourPass == "B"){    for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 100);
  }
  FastLED.show(); }
  if (colourPass == "G"){    for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 100, 0);
  }
  FastLED.show(); }




  
  int red = 0;int blue = 0;int green = 0;
  data.remove(0,0);

  if (data > 255){data = 255;}
  
  if (colourPass == "G"){green = data.toInt();}
  if (colourPass == "B"){blue = data.toInt();}
  if (colourPass == "R"){red = data.toInt();}
  
    for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show(); 
  */
