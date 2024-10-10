// Copyright 2024 Google LLC.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TENSORFLOW_LITE_EXPERIMENTAL_LRT_QNN_IR_QNN_OP_H_
#define TENSORFLOW_LITE_EXPERIMENTAL_LRT_QNN_IR_QNN_OP_H_

#include "third_party/qairt/include/QNN/QnnTypes.h"
#include "tensorflow/lite/experimental/lrt/c/lite_rt_common.h"
#include "tensorflow/lite/experimental/lrt/c/lite_rt_model.h"

namespace qnn {

//
// Initialize QNN Op.
//

// NOTE: Any referential data within a QNN Op
// is allocated with "new" and must be explicitly cleaned up with ResetOp.

// Construct a "blank" QNN Op.
Qnn_OpConfig_t BuildDefaultOp();

// Reset the given tensor, deallocating anything on the heap that it points to.
void ResetOp(Qnn_OpConfig_t& op);

//
// Legalize Lrt Op to Analogous QNN Construct.
//

// Map src op onto dest. Resets dest before doing anything. This only handles
// attribute-like info. It does not set edges (in/out tensors).
LrtStatus LegalizeOp(LrtOp src, Qnn_OpConfig_t& dest);

}  // namespace qnn

#endif  // TENSORFLOW_LITE_EXPERIMENTAL_LRT_QNN_IR_QNN_OP_H_
