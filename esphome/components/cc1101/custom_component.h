#pragma once

#include "esphome/core/component.h"
#include "esphome/core/application.h"

#include <vector>

namespace esphome {
namespace cc1101 {

class CC1101Component {
 public:
  CC1101Component(const std::function<std::vector<Component *>()> &init) {
    this->components_ = init();

    for (auto *comp : this->components_) {
      App.register_component(comp);
    }
  }

  Component *get_component(int i) const { return this->components_[i]; }

 protected:
  std::vector<Component *> components_;
};

}  // namespace cc1101
}  // namespace esphome
