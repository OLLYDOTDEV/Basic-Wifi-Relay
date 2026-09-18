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

  // LoadValue(Schedule,G_Timer_Schedule)
  // LoadValue(Mode,G_CurrentMode) // check functions supports int's

  
delay(5000);



Initialize_UI();

}


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

// Get time

// web server 

//WebserverSubroutine();


// checkWiFi(); // 

//TimedRestart(int CurrentMode, int currentMinutes)
//HeartBeat(G_HeartBeat,G_date_str);





// Relay control







yield();

}

