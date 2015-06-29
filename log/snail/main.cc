// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#define LOG_TAG main

#include <stdio.h>
#include <string>
#include <iostream>  // NOLINT

#include "log/snail/modulea.h"
#include "log/snail/moduleb.h"
#include "log/snail/modulec.h"
#include "log/snail/moduleaa.h"

#include "log/snail/log.h"

volatile unsigned int ui2 = 2;

void test() {
  std::cout << "------------------------" << std::endl;

  ALOGV << "create Module A";
  ModuleA ma;
  ALOGD << "let ma do something";
  ma.do_something();

  ALOGI << "create Module B";
  ModuleB mb;
  ALOGW << "let mb do something";
  mb.do_something();

  ALOGE << "create Module C";
  ModuleC mc;
  ALOGV << "let mc do something";
  mc.do_something();

  ALOGU << "User ModuleAA do something";
  ModuleAA maa;
  maa.do_something();

  ALOGE << 10;

  std::string str { "all is good but string" };
  ALOGE << str;

  unsigned int ui  = 0x80000000;

  printf("=================>ui = %d\n", ui);
  ALOGE << std::showbase << std::hex << ui << " " << std::dec << ui2;

  ALOGW_IF(ui2 > 1) << "ui2 > 1!!!";
  ALOGE_IF(ui2 < 100) << "ui2 < 100!!!";

  if (IF_ALOGI) {
    std::cout << "hahahahaha" << std::endl;
  }

  ALOGE << ui;

  ALOGE << "all done!";
}

int main() {
  initLog();

  setLogLevel(LogSeverityLevel::verbose);
  test();

  setLogLevel(LogSeverityLevel::debug);
  test();

  setLogLevel(LogSeverityLevel::info);
  test();

  setLogLevel(LogSeverityLevel::warning);
  test();

  setLogLevel(LogSeverityLevel::error);
  test();

  setLogLevel(LogSeverityLevel::user);
  test();

  enableDisableLog(false);
  test();


#if 0
  for (int i = 0; i < 400 * 1024; ++i) {
    ALOGI << "a";
    ALOGU << "u";
  }

  setDebugLevel(LogSeverityLevel::debug);

  for (int i = 0; i < 100 * 1024; ++i) {
    ALOGI << "a";
    ALOGU << "u";
  }
#endif

  enableDisableLog(true);
  ALOGV << "haha";

  cleanupLog();
}
