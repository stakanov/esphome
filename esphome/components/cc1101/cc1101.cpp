#include "cc1101.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"

namespace esphome {
namespace cc1101 {

static const char *const TAG = "cc1101";

void CC1101::setup() {
  ESP_LOGI(TAG, "Setup...");
}

void CC1101::dump_config() { 
  ESP_LOGI("", "Dump config...", this); 
}

void CC1101::send_data() {
  ESP_LOGI(TAG, "Send signal...");
}

float CC1101::get_setup_priority() const { return setup_priority::DATA; }

}  // namespace cc1101
}  // namespace esphome