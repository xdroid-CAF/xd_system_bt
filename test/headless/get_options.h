/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <cstddef>
#include <list>
#include "types/bluetooth/uuid.h"
#include "types/raw_address.h"

namespace bluetooth {
namespace test {
namespace headless {

class GetOpt {
 public:
  GetOpt(int argc, char** arv);
  virtual ~GetOpt() = default;

  virtual void Usage() const;
  virtual bool IsValid() const { return valid_; };

  std::list<RawAddress> device_;
  std::list<bluetooth::Uuid> uuid_;
  int loop_;

 private:
  void ParseValue(char* optarg, std::list<std::string>& my_list);
  void ProcessOption(int option_index, char* optarg);
  const char* name_{nullptr};
  bool valid_{true};
};

}  // namespace headless
}  // namespace test
}  // namespace bluetooth
