/* Copyright 2022 Google LLC. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "third_party/array_record/cpp/thread_pool.h"

#include "third_party/absl/flags/flag.h"

ABSL_FLAG(uint32_t, array_record_global_pool_size, 64,
          "Number of threads for ArrayRecordGlobalPool");

namespace array_record {

ARThreadPool* ArrayRecordGlobalPool() {
  static ARThreadPool* pool_ = []() -> ARThreadPool* {
    ARThreadPool* pool = new
    Eigen::ThreadPool(absl::GetFlag(FLAGS_array_record_global_pool_size));
    return pool;
  }();
  return pool_;
}

}  // namespace array_record
