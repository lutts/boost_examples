// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include "log/snail/user_log_testspy.h"
#include "log/snail/log.h"

#include <vector>
#include <string>
#include <iostream>

bool checkLog(const std::vector<std::string>& expect_messages,
              const UserLogTestSpy& logSpy) {
  std::cout << "exp size = " << expect_messages.size()
            << ", actual size = " << logSpy.actual_messages.size()
            << std::endl;
  if (expect_messages.size() != logSpy.actual_messages.size())
    return false;

  for (size_t i = 0; i < expect_messages.size(); ++i) {
    std::cout << "compare <" << expect_messages[i]
              << "> with <" << logSpy.actual_messages[i] << ">"
              << std::endl;
    if (expect_messages[i] != logSpy.actual_messages[i])
      return false;
  }

  return true;
}

int main() {
  UserLogTestSpy logSpy;

  ALOGU << "test spy " << std::showbase << std::hex << 3;

  std::vector<std::string> expect_messages;
  expect_messages.emplace_back("test spy 0x3");

  if (checkLog(expect_messages, logSpy)) {
    std::cout << "test ok" << std::endl;;
  } else {
    std::cout << "test failed" << std::endl;;
  }
}
