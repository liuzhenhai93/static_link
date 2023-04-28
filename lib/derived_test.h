//
// Created by liuzhenhai on 28.4.23.
//
#include "lib/base_test.h"

namespace debug_brpc {
class DerivedTest: public BaseTest {
 public:
  DerivedTest(const std::string& name){
    Record(name);
  };
  virtual ~DerivedTest() = default;
};
}

