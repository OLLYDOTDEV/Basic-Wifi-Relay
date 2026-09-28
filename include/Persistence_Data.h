#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Preferences.h>
#include "UI.h"
#include "Hardware_Control.h"
#include "Persistence_Data.h"

#include "HardwareSerial.h"

bool SaveValueChar(const char* Key,char* Data, int Data_Size); 
bool LoadValueChar(const char* Key,char* Data, int Data_Size);
bool SaveValueBool(const char* Key,bool* Data, int Data_Size); 
bool LoadValueBool(const char* Key,bool* Data, int Data_Size);
void ClearState();
