#include "Globals.h"
#include <Arduino.h>
#include "HardwareSerial.h"
#include "UI.h"
#include "Networking.h"
#include "Hardware_Control.h"



void setup() {

Initalize_Hardware(5);

  // ClearState();  // Keep commented unless required [will clear set NVM keys]
  Initalize_ExistingNetwork();

  // LoadValue("Schedule",G_Timer_Schedule,sizeof(G_Timer_Schedule));
  LoadValue_Int("Mode",G_CurrentMode); // check functions supports int's

  delay(5000);



Initialize_UI();

}

// PinMode_Function digital write is commented out while testing.

void loop() {
WebserverSubroutine();

  // Check the webserver is still working and also helps to save CPU cycles
  // if (currentMinutes == 40) {
  //   WebServerTest();
  //   checkWiFi();
  // }

  // if (WebErrorCount == 1 and millis() == 60000) {
  //   ESP.restart();
  // }






// Network connection

// Set current time


timestring(G_DateSting);

G_TimeHours = GetHours();

G_TimeMinutes = GetMinutes();

// web server 

//WebserverSubroutine();


// checkWiFi(); // 

TimedRestart(G_TimeHours, G_TimeMinutes);


// Relay control


    switch (G_CurrentMode) {
      case 1:
        Mode_1();
        break;
      case 2:
        Mode_2();
       break;
      case 3:
        Mode_3();
        break;
      case 4:
        Mode_4();
        break;
    }




yield();

}

