#include "cc1101.h"
#include "esphome/core/log.h"

namespace esphome {
namespace cc1101 {

static const char *TAG = "cc1101.component";

void CC1101::setup() {
  ESP_LOGI(TAG, "Setup...");
}

void CC1101::loop() {
  //ESP_LOGI(TAG, "Inside the LOOP...");
}

void CC1101::dump_config() { 
  ESP_LOGI(TAG,"Dump config..."); 
}

}  // namespace cc1101
}  // namespace esphome