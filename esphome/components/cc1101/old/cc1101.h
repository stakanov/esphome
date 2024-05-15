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

  int gpio_sclk;              // definito in componente SPI
  int gpio_miso;              // definito in componente SPI
  int gpio_mosi;              // definito in componente SPI
  int gpio_cs;                // definito in componente CC1101
  int gpio_gdo0;              // non definito
  int gpio_gdo2;              // non definito
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

