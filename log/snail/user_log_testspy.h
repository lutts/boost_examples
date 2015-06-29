// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#ifndef USER_LOG_TESTSPY_H_
#define USER_LOG_TESTSPY_H_

#include <vector>
#include <string>

class UserLogTestSpy {
 public:
  UserLogTestSpy();
  virtual ~UserLogTestSpy();

  std::vector<std::string> actual_messages;

 private:
  UserLogTestSpy(const UserLogTestSpy& other) = delete;
  UserLogTestSpy& operator=(const UserLogTestSpy& other) = delete;
};


#endif  // USER_LOG_TESTSPY_H_
