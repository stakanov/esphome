#pragma once

#ifdef USE_ARDUINO

#include "esphome/components/button/button.h"
#include "esphome/core/component.h"

namespace esphome {
namespace test {

class TestButton : public button::Button, public Component {
 public:
  void set_macaddr(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f);

  void dump_config() override;

 protected:
  void press_action() override;
  uint8_t macaddr_[6];
};

}  // namespace test
}  // namespace esphome

#endif
