#include "cc1101.h"
#include "esphome/core/application.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome {
namespace cc1101 {

static const char *const TAG = "cc1101.button";

void CC1101Button::press_action() {
  ESP_LOGI(TAG, "Created CC1101 device");
}

void CC1101Button::dump_config() { LOG_BUTTON("", "CC1101 Button", this); }

}  // namespace cc1101
}  // namespace esphome
