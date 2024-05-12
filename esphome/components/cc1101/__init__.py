import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import spi
from esphome.const import (CONF_ID)

DEPENDENCIES = ["spi"]

cc1101_ns = cg.esphome_ns.namespace("cc1101")
CC1101 = cc1101_ns.class_("CC1101", cg.Component, spi.SPIDevice)

CONFIG_SCHEMA = cv.Schema(
    {   
        cv.GenerateID(): cv.declare_id(CC1101),
    }
).extend(spi.spi_device_schema(cs_pin_required=True))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])   
    await cg.register_component(var, config)
    await spi.register_spi_device(var, config)

####################################################################################################
"""
 CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(ADS1118),
    }
).extend(spi.spi_device_schema(cs_pin_required=True))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await spi.register_spi_device(var, config)

"""