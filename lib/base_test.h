#pragma once
#include <string>

namespace debug_brpc {
class BaseTest {
 public:
  BaseTest();
  virtual ~BaseTest();
  void PrintRecord();
 protected:
  virtual void Record(const std::string &record);
 private:
  std::string name_;
};
}

