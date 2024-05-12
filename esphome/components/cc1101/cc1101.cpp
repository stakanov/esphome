#include "cc1101.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"

namespace esphome {
namespace cc1101 {

static const char *const TAG = "cc1101.button";

void XPT2046Component::setup() {
  this->spi_setup();
}

void CC1101::dump_config() { 
    LOG_BUTTON("", "CC1101 Button", this); 
}

void CC1101::press_action() {
  ESP_LOGI(TAG, "Send signal...");
}

float CC1101::get_setup_priority() const { return setup_priority::DATA; }

}  // namespace cc1101
}  // namespace esphome