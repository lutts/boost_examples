// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#define LOG_TAG ModuleB

#include <iostream>  // NOLINT
#include "log/snail/moduleb.h"
#include "log/snail/log.h"

ModuleB::ModuleB() {
}

ModuleB::~ModuleB() {
}

void ModuleB::do_something() {
  ALOGV << "call ModuleB::do_something";
  std::cout << "moduleb do something" << std::endl;
}
