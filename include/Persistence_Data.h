#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Preferences.h>
#include "UI.h"
#include "Hardware_Control.h"
#include "Persistence_Data.h"

#include "HardwareSerial.h"

bool SaveValue_Char(const char* Key,char* Data, int Data_Size); 
bool LoadValue_Char(const char* Key,char* Data, int Data_Size);
bool SaveValue_Bool(const char* Key,bool* Data, int Data_Size); 
bool LoadValue_Bool(const char* Key,bool* Data, int Data_Size);
bool SaveValue_Int(const char* Key,int Data); 
bool LoadValue_Int(const char* Key,int Data);
void ClearState();
