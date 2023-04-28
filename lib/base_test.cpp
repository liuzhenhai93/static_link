//
// Created by liuzhenhai on 28.4.23.
//

#include "lib/base_test.h"

#include <map>
#include <memory>
#include <pthread.h>
#include <iostream>

namespace debug_brpc {
static pthread_once_t s_record_store_once = PTHREAD_ONCE_INIT;
static std::map<std::string, std::string>* s_record_store = nullptr;

static void init_record_store() {
  s_record_store = new std::map<std::string, std::string>;
}

inline std::map<std::string, std::string>* get_record_store() {
  pthread_once(&s_record_store_once, init_record_store);
  return s_record_store;
}

BaseTest::~BaseTest() {
  PrintRecord();
}

BaseTest::BaseTest() {}

void BaseTest::PrintRecord() {
  auto &record_store = *get_record_store();
  if (record_store.count(name_)) {
    record_store.erase(name_);
  } else {
    std::cout << name_ << " not exist \n";
  }

}

void BaseTest::Record(const std::string &record) {
  name_ = record;
  auto &record_store = *get_record_store();
  if (record_store.count(name_)) {
    std::cout << name_ << " exist \n";
  } else {
    std::cout << "record " << name_ << "\n";
    record_store[name_] = name_;
  }
}

}