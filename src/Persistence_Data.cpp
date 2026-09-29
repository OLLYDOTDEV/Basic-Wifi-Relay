#include <Persistence_Data.h>
#include "UI.h"
#include "esp8266_peri.h"
Preferences preferences;

// consider refactoring to a single save and load function with more inputs to control the namescope

// Rewrite with EEPROM libary, https://www.techrm.com/how-to-use-the-eeprom-memory-on-the-nodemcu-esp8266/
bool SaveValue_Char(const char* Key,char* Data, int Data_Size) { // Store Char array to NVM
    Serial.println("Storing Key pair to NVM storage");  
    Serial.print(Key);  
    Serial.print(" : ");  
    Serial.println(Data); 
  preferences.begin("ProgramData", false);                          // Open namespace "schedule"
  preferences.putBytes(Key, Data,Data_Size);  // Save schedule array
  if(preferences.isKey(Key) == false){
    preferences.end();
    Serial.println("Key failed to save");
    return false;
  }
  preferences.end();
  Serial.println("Key pair saved\n\n\n");
  return true;
}

bool LoadValue_Char(const char* Key,char* Data, int Data_Size) { // Retrieve Char array to NVM
  preferences.begin("ProgramData", true);  // Open namespace "schedule" (read-only)
  if (preferences.isKey(Key)) {
    // Load schedule array from flash memory
    preferences.getBytes(Key, Data,Data_Size);
    Serial.println("Key pair found and restored");  
    Serial.print(Key);  
    // Serial.print(" : ");  
    // Serial.println(Data);  // Keep commented to prevent leaking password on boot.
  } else {
    Serial.print("Failed to load key ( ");
    Serial.print(Key);
    Serial.println(" ) from EEPROM, key missing\n");
    preferences.end();  // Close namespace
    return false;
  }
preferences.end();  // Close namespace
return true;
}

// Rewrite with EEPROM libary, https://www.techrm.com/how-to-use-the-eeprom-memory-on-the-nodemcu-esp8266/
bool SaveValue_Bool(const char* Key,bool* Data, int Data_Size) { // Store Char array to NVM
    Serial.println("Storing Key pair to NVM storage");  
    Serial.print(Key);  
    Serial.print(" : ");  
    Serial.print(*Data); 
  preferences.begin("ProgramData", false);                          // Open namespace "schedule"
  preferences.putBytes(Key, Data,Data_Size);  // Save schedule array
  if(preferences.isKey(Key) == false){
    preferences.end();
    Serial.println("Key failed to save");
    return false;
  }
  preferences.end();
  Serial.println("Key pair saved\n\n\n");
  return true;
}

bool LoadValue_Bool(const char* Key,bool* Data, int Data_Size) { // Retrieve Char array to NVM
  preferences.begin("ProgramData", true);  // Open namespace "schedule" (read-only)
  if (preferences.isKey(Key)) {
    // Load schedule array from flash memory
    preferences.getBytes(Key, Data,Data_Size);
    Serial.println("Key pair found and restored");  
    Serial.print(Key);  
    // Serial.print(" : ");  
    // Serial.println(Data);  // Keep commented to prevent leaking password on boot.
  } else {
    Serial.print("Failed to load key ( ");
    Serial.print(Key);
    Serial.println(" ) from EEPROM, key missing\n");
    preferences.end();  // Close namespace
    return false;
  }
preferences.end();  // Close namespace
return true;
}

// Rewrite with EEPROM libary, https://www.techrm.com/how-to-use-the-eeprom-memory-on-the-nodemcu-esp8266/
bool SaveValue_Int(const char* Key,int Data) { // Store Char array to NVM
    Serial.println("Storing Key pair to NVM storage");  
    Serial.print(Key);  
    Serial.print(" : ");  
    Serial.println(Data); 
  preferences.begin("ProgramData", false);                          // Open namespace "schedule"
  preferences.putInt(Key, Data);  // Save schedule array
  if(preferences.isKey(Key) == false){
    preferences.end();
    Serial.println("Key failed to save");
    return false;
  }
  preferences.end();
  Serial.println("Key pair saved\n\n\n");
  return true;
}

bool LoadValue_Int(const char* Key,int Data) { // Retrieve Char array to NVM
  preferences.begin("ProgramData", true);  // Open namespace "schedule" (read-only)
  if (preferences.isKey(Key)) {
    // Load schedule array from flash memory
    preferences.getInt(Key, Data);
    Serial.println("Key pair found and restored");  
    Serial.print(Key);  
    // Serial.print(" : ");  
    // Serial.println(Data);  // Keep commented to prevent leaking password on boot.
  } else {
    Serial.print("Failed to load key ( ");
    Serial.print(Key);
    Serial.println(" ) from EEPROM, key missing\n");
    preferences.end();  // Close namespace
    return false;
  }
preferences.end();  // Close namespace
return true;
}




// void saveSchedule(int* schedule) {
//   preferences.begin("schedule", false);                          // Open namespace "schedule"
//   preferences.putBytes("schedule", schedule, sizeof(schedule));  // Save schedule array
//   preferences.end();
//   delay(250);  // Close namespace
// }

// void loadSchedule(int* schedule) {
//   preferences.begin("schedule", true);  // Open namespace "schedule" (read-only)

//   if (preferences.isKey("schedule")) {
//     // Load schedule array from flash memory
//     preferences.getBytes("schedule", schedule, sizeof(schedule));
//   } else {
//     Serial.println("Failed to load from EEPROM");
//   }
//   preferences.end();  // Close namespace
//   delay(250);
// }



// void saveMode(int CurrentMode) {
//   preferences.begin("mode", false);
//   preferences.putInt("CurrentMode", CurrentMode);
//   preferences.end();
//   Serial.println("Mode saved");
//   delay(250);
// }

// void loadMode(int CurrentMode) {
//   preferences.begin("mode", true);
//   if (preferences.isKey("CurrentMode")) {
//     CurrentMode = preferences.getInt("CurrentMode", 0);
//     selectMode();
//   } else {
//     Serial.println("Failed to load from EEPROM");
//     CurrentMode = 0;  // Set a default value
//   }
//   preferences.end();
//   delay(250);
// }

void ClearState() {
  Serial.println("Clearing Saved keys");
  preferences.begin("ProgramData", false);
  preferences.clear();
  preferences.end();
}