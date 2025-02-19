/*
 * Copyright(c) 2021 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this software except as stipulated in the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/** @file tna_defs.hpp
 *
 *  @brief Contains TNA specific common defs like Target
 */
#ifndef _TNA_DEFS_HPP_
#define _TNA_DEFS_HPP_

#include <functional>
#include <memory>
#include <mutex>

#include <tdi/common/tdi_defs.h>
#include <tdi/common/tdi_target.hpp>

// tna include
#include <tdi/arch/tna/tna_defs.h>
#include <tdi/arch/tna/tna_init.hpp>

namespace tdi {
namespace tna {

class Device;

/**
 * @brief Can be constructed by \ref tna::Device::createTarget()
 */
class Target : public tdi::Target {
 public:
  virtual ~Target() = default;
  virtual tdi_status_t setValue(const tdi_target_e & /*target*/,
                                const uint32_t & /*value*/) override;
  virtual tdi_status_t getValue(const tdi_target_e & /*target*/,
                                uint32_t * /*value*/) const override;

 protected:
  Target(tdi_dev_id_t dev_id, tna_pipe_id_t pipe_id, tna_direction_e direction)
      : tdi::Target(dev_id), pipe_id_(pipe_id), direction_(direction){};
  tna_pipe_id_t pipe_id_;
  tna_direction_e direction_;

  friend class tdi::tna::Device;
};

}  // namespace tna
}  // namespace tdi

#endif  // _TNA_DEFS_HPP_
