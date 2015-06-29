// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#define LOG_TAG ModuleC

#include <iostream>  // NOLINT
#include "log/snail/modulec.h"
#include "log/snail/log.h"

ModuleC::ModuleC() {
}

ModuleC::~ModuleC() {
}

void ModuleC::do_something() {
  ALOGV << "Call ModuleC::do_something";
  std::cout << "modulec do something" << std::endl;
}
