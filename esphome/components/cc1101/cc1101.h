#pragma once

#include "esphome/core/component.h"
#include "esphome/components/button/button.h"
#include "CC1101_ESP_Arduino.h"

namespace esphome {
namespace cc1101 {

class CC1101Button : public button::Button, public Component {
 public:
  
  void set_module(int sclk, int miso, int mosi, int cs, int gdo0, int gdo2, int bitrate, float frequency, TX_DBM txPower, unsigned long dataRate, MOD_FORMAT modulation, int repeat /*, int delayTime , uint8_t buffer[]*/){};

  void dump_config() override;

 protected:
  void press_action() override;

  int gpio_sclk;
  int gpio_miso;
  int gpio_mosi;
  int gpio_cs;
  int gpio_gdo0;
  int gpio_gdo2;
  int bitrate;
  float frequency;
  TX_DBM txPower;
  unsigned long dataRate;
  MOD_FORMAT modulation;
  int repeat;
  //int delayTime;
  //uint8_t buffer[];
};

}  // namespace cc1101
}  // namespace esphome

