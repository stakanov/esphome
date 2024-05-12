import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import button
from esphome.components import spi
from esphome.const import (CONF_ID)

DEPENDENCIES = ["spi"]

cc1101_ns = cg.esphome_ns.namespace("cc1101")
CC1101 = cc1101_ns.class_("CC1101", button.Button, cg.Component, spi.SPIDevice)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(CC1101),
    }
).extend(spi.spi_device_schema())

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await spi.register_spi_device(var, config)
    await button.register_button(var, config)


####################################################################################################

