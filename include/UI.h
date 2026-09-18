#pragma once

#include "Globals.h"
#include <Arduino.h>
#include <EmbAJAX.h>
#include <EmbAJAXScriptedSpan.h>
#include <Persistence_Data.h>

void updateUI();
void selectMode();
void Initialize_UI();
void WebserverSubroutine();

void Mode_1();  // Relay output Override off
void Mode_2();  // Relay output Override on
void Mode_3();  // Relay output on automatic schedule
void Mode_4();  // Relay output on Timer off based schedule