import esphome.codegen as cg
from esphome.components import button
import esphome.config_validation as cv
from esphome.const import CONF_ID

CONF_GPIO_SCLK = "gpio_sclk"
CONF_GPIO_MISO = "gpio_miso"
CONF_GPIO_MOSI = "gpio_mosi"
CONF_GPIO_CS   = "gpio_cs"
CONF_GPIO_GDO0 = "gpio_gdo0"
CONF_GPIO_GDO2 = "gpio_gdo2"
CONF_BITRATE   = "bitrate"
CONF_FREQUENCY = "frequency"
CONF_TX_POWER  = "tx_power"
CONF_DATARATE  = "datarate"
CONF_MODULATION= "modulation"
CONF_REPEAT    = "repeat"


cc1101_ns = cg.esphome_ns.namespace("cc1101")

CC1101Button = cc1101_ns.class_("CC1101Button", button.Button, cg.Component)

# DEPENDENCIES = []


CONFIG_SCHEMA = cv.All(
    button.button_schema(CC1101Button)
    .extend(cv.COMPONENT_SCHEMA)
    .extend(
        cv.Schema(
            {
                cv.Required(CONF_GPIO_SCLK ): cv.int_,
                cv.Required(CONF_GPIO_MISO ): cv.int_,
                cv.Required(CONF_GPIO_MOSI ): cv.int_,
                cv.Required(CONF_GPIO_CS   ): cv.int_,
                cv.Required(CONF_GPIO_GDO0 ): cv.int_,
                cv.Required(CONF_GPIO_GDO2 ): cv.int_,
                cv.Required(CONF_BITRATE   ): cv.uint8_t,
                cv.Required(CONF_FREQUENCY ): cv.float_,
                cv.Required(CONF_TX_POWER  ): cv.int_,
                cv.Required(CONF_DATARATE  ): cv.float_,
                cv.Required(CONF_MODULATION): cv.int_,
                cv.Required(CONF_REPEAT    ): cv.int,
            }
        ),
    ),
    cv.only_with_arduino,
)


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    #await cg.register_component(var, config)
    #await button.register_button(var, config)    
    yield cg.add(var.set_module(
        config[CONF_GPIO_SCLK],
        config[CONF_GPIO_MISO], 
        config[CONF_GPIO_MOSI], 
        config[CONF_GPIO_CS],   
        config[CONF_GPIO_GDO0], 
        config[CONF_GPIO_GDO2], 
        config[CONF_BITRATE],   
        config[CONF_FREQUENCY], 
        config[CONF_TX_POWER],  
        config[CONF_DATARATE],
        config[CONF_MODULATION],
        config[CONF_REPEAT],   
            ))
    yield cg.register_component(var, config)
    yield button.register_button(var, config)