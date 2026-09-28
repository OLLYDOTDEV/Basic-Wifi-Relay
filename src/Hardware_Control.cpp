#include "Hardware_Control.h"
#include "HardwareSerial.h"
#include <algorithm>

inline int G_relay_status = 0;

void Initalize_Hardware(const int RelayPin){

  pinMode(RelayPin, OUTPUT);        // Set relay pin as output
  PinMode_Function(RelayPin, LOW);  // Initialize relay to off
  Serial.begin(115200);
  while (!Serial) {}; // Wait for setup to be ready
  Serial.println();
	delay(1000);
	Serial.println("Serial Port Started \n");
	Serial.flush();
	delay(1000);
}

void PinMode_Function(int pin, bool state) {

  if (G_relay_status != state) {
    G_relay_status = state;
    Serial.print("Pin State: ");
    Serial.println(state);
    //delay(1000);  // delays required to prevent watchdog timer
    // digitalWrite(pin, state);
    //delay(4000);
  }
}


void TimedRestart(int Hour, int Minutes){
  if (Hour == 11 && Minutes == 59) {  // reboot at 11:59 am
    //pinMode_function(relayPin, LOW);
    Serial.println("Automatic Reboot in 60 seconds");
    delay(1200000);  // ensure wont reboot twice in the same minute
    ESP.restart();   //
  }
}

void GetInput(const char* InputMsg,char* Array){
  Serial.println(InputMsg); 
  int InputAccepted = false;
  while (InputAccepted == false){
    if (Serial.available() > 0){
        int bytesRead = Serial.readBytesUntil('\r', Array, 99); // cant use size of due to decay-to-pointer
        Serial.read(); // clear buffer
        Array[bytesRead] = '\0';  // Null-terminate the string
        Serial.print("Buffer Value received: ");
        Serial.println(Array);
        Serial.println("Confirm Input? (Y/N)");
        while (Serial.available() == 0 ){}
        char ShortBuff[1];
        Serial.readBytes(ShortBuff,1);

        InputAccepted = (ShortBuff[0] == 'y' || ShortBuff[0] == 'Y') ? true : false;
        if (InputAccepted == false){
          Serial.println("Input rejected by user, Wait for input prompt to repeat user input. \n");
          delay(2500);
          while (Serial.available() != 0) {
            Serial.read();  // Read and discard one byte of data from the buffer
          }  
        Serial.println(InputMsg); 
        }
    }
    yield();
  }
  delay(200);  
  Serial.println("Input Confirmed.\n\n\n");
}


