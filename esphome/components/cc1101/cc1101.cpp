#include "cc1101.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"

namespace esphome {
namespace cc1101 {

static const char *const TAG = "cc1101.button";

static const uint8_t SCK_PIN = 18;
static const uint8_t MISO_PIN = 19;
static const uint8_t MOSI_PIN = 23;
static const uint8_t CS_PIN = 5;

void CC1101::setup() {
  ESP_LOGI(TAG, "Setup...");
}

void CC1101::dump_config() { 
  LOG_BUTTON("", "Dump config...", this); 
}

void CC1101::press_action() {
  ESP_LOGI(TAG, "Send signal...");
}

float CC1101::get_setup_priority() const { return setup_priority::DATA; }

}  // namespace cc1101
}  // namespace esphome