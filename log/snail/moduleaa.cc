// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#define LOG_TAG ModuleA

#include "log/snail/moduleaa.h"
#include "log/snail/log.h"

ModuleAA::ModuleAA() { }
ModuleAA::~ModuleAA() { }

void ModuleAA::do_something() {
  ALOGV << "ModuleAA do something";
}
