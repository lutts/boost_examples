// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#define LOG_TAG ModuleA

#include <iostream>  // NOLINT
#include "log/snail/modulea.h"
#include "log/snail/log.h"

ModuleA::ModuleA() { }
ModuleA::~ModuleA() { }

void ModuleA::do_something() {
  ALOGV << "enter ModuleA::do_something";
  std::cout << "modulea do something" << std::endl;
}
