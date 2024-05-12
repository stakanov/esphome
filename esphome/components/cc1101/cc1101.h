#pragma once

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace cc1101 {

class CC1101 : public Component,
               public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING, spi::DATA_RATE_10MHZ> {
  public:
    void setup() override;
    void dump_config() override;
    float get_setup_priority() const override;
    void send_data();
  //protected:
  // void press_action() override;
};

}  // namespace cc1101
}  // namespace esphome
