#ifdef USE_ARDUINO

#include "test.h"
#include "esphome/core/log.h"


namespace esphome {
namespace test {

static const char *const TAG = "test.button";

void TestButton::set_macaddr(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f) {
  macaddr_[0] = a;
  macaddr_[1] = b;
  macaddr_[2] = c;
  macaddr_[3] = d;
  macaddr_[4] = e;
  macaddr_[5] = f;
}

void TestButton::dump_config() {
  LOG_BUTTON("", "Tetst Button", this);
  ESP_LOGCONFIG(TAG, "Test");
}

void TestButton::press_action() {
  ESP_LOGI(TAG, "Test press_action()...");
}

}  // namespace test
}  // namespace esphome

#endif
