import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import button
from esphome.const import (
    CONF_ID,
#    DEVICE_CLASS_RESTART,
#    ENTITY_CATEGORY_CONFIG,
)

cc1101_ns = cg.esphome_ns.namespace("cc1101")
CC1101Button = cc1101_ns.class_("CC1101Button", button.Button, cg.Component)

CONFIG_SCHEMA = button.button_schema(
    CC1101Button,
    device_class=DEVICE_CLASS_RESTART,
    entity_category=ENTITY_CATEGORY_CONFIG,
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await button.register_button(var, config)
