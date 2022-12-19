//*********************************************************************************
//
//  System:     HomeSpan Accessory Bridges
//  Component:  3x Mono-Color LED Strip Driver
//  Target:     Espressif ESP32 DevKit ESP32-WROOM
//
//  Author:     Andrew J Ressa
//  Contact:    aressa@angrykitten.com
//              @randyf@defcon.social
//
//  --- Dependencies ---
//  HomeSpan ESP32/Arduino Libraries
//
//  --- Version Info ---
//  Date      Ver   Init  Changes
//  20221219  0.0   AJR   Initial Draft
//  20221219  0.1   AJR   Identified IO Pins that work without horking up flashing
//                         or any other chip interfaces.
//
//*********************************************************************************
 
//=================================================================================
// Libraries and Other Files
//=================================================================================
#include "HomeSpan.h" 
#include "DEV_LED.h"     


//=================================================================================
// Pin Defines
//=================================================================================
// CONFIRMED LED DRIVE PINS
#define GPIO02  2
#define GPIO04  4
#define GPIO05  5
//#define GPIO12 12
#define GPIO13 13
#define GPIO14 14
#define GPIO15 15
#define GPIO18 18
#define GPIO19 19
#define GPIO21 21
#define GPIO22 22
#define GPIO23 23
#define GPIO25 25
#define GPIO26 26
#define GPIO27 27
#define GPIO32 32
#define GPIO33 33


//=================================================================================
// LED Strip IOs
//=================================================================================
#define STRIP_00_R  GPIO27
#define STRIP_00_G  GPIO14
#define STRIP_00_B  GPIO13

#define STRIP_01_R  GPIO33
#define STRIP_01_G  GPIO25
#define STRIP_01_B  GPIO26

#define STRIP_02_R  GPIO21
#define STRIP_02_G  GPIO19
#define STRIP_02_B  GPIO18


//=================================================================================
// Module Setup
//=================================================================================
void setup() {

  // Example 10 illustrates how to control an RGB LED to set any color and brightness.
  // The configuration below should look familiar by now.  We've created a new derived Service,
  // called DEV_RgbLED to house all the required logic.  You'll find all the code in DEV_LED.h.
  // For completeness, this configuration also contains an on/off LED and a dimmable LED as shown
  // in prior examples.
  
  Serial.begin(115200);

  //--------------------------------------------------------------------------------
  // HomeSpan Bridge Setup
  //--------------------------------------------------------------------------------
  homeSpan.begin(Category::Bridges,"LED Strip Bridge - 3x MonoColor");
  homeSpan.setLogLevel(1);                                // NEW - Sets Log Level to 1, which causes LOG1() messages to be output

  new SpanAccessory();  
    new Service::AccessoryInformation();
      new Characteristic::Identify();


  //--------------------------------------------------------------------------------
  // LED Strip Component 0
  //--------------------------------------------------------------------------------
  new SpanAccessory();                                                          
    new Service::AccessoryInformation();    
      new Characteristic::Identify();               
      new Characteristic::Name("MonoColor RGB LED Strip 00"); 
    new DEV_RgbLED( STRIP_00_R, STRIP_00_G, STRIP_00_B ); // Create an RGB LED

  //--------------------------------------------------------------------------------
  // LED Strip Component 1
  //--------------------------------------------------------------------------------
  new SpanAccessory();                                                          
    new Service::AccessoryInformation();    
      new Characteristic::Identify();               
      new Characteristic::Name("MonoColor RGB LED Strip 01"); 
    new DEV_RgbLED( STRIP_01_R, STRIP_01_G, STRIP_01_B ); // Create an RGB LED

  //--------------------------------------------------------------------------------
  // LED Strip Component 2
  //--------------------------------------------------------------------------------
  new SpanAccessory();                                                          
    new Service::AccessoryInformation();    
      new Characteristic::Identify();               
      new Characteristic::Name("MonoColor RGB LED Strip 02"); 
    new DEV_RgbLED( STRIP_02_R, STRIP_02_G, STRIP_02_B ); // Create an RGB LED

  //--------------------------------------------------------------------------------
  // Debugging Accessories
  //--------------------------------------------------------------------------------
  // new SpanAccessory();                                                          
  //   new Service::AccessoryInformation();
  //     new Characteristic::Identify();            
  //     new Characteristic::Name("Simple LED");
  //   new DEV_LED(32);                                                               // Create an On/Off LED attached to pin 16

  // new SpanAccessory();                                                          
  //   new Service::AccessoryInformation();    
  //     new Characteristic::Identify();               
  //     new Characteristic::Name("Dimmable LED"); 
  //   new DEV_DimmableLED(GPIO02);                                                       // Create a Dimmable (PWM-driven) LED using attached to pin 17  

} // end of setup()


//=================================================================================
// Primary Loop
//=================================================================================
void loop(){
  
  homeSpan.poll();
  
} // end of loop()



/*********************************************************************************
 *  MIT License
 *  
 *  Copyright (c) 2020-2022 Gregg E. Berman
 *  
 *  https://github.com/HomeSpan/HomeSpan
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *  
 ********************************************************************************/

////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: A HomeKit implementation for the ESP32    //
//    ------------------------------------------------    //
//                                                        //
// Example 10: Controlling a full-color RGB LED           //
//                                                        //
//                                                        //
////////////////////////////////////////////////////////////
