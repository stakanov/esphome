#include "./cc1101.h"
#include "esphome/core/log.h"
#include "./EspBitBanger/EspBitBanger.h"

namespace esphome {
namespace cc1101 {

static const char *const TAG = "cc1101.button";
CC1101 cc1101;
EspBitBanger bitBanger;
uint32_t 		bitRate;
float		 	frequency;
TX_DBM 			txPower;
unsigned long 	dataRate;
MOD_FORMAT 		modulation;
//uint8_t			buffer[];

void CC1101Button::set_module(int sclk, int miso, int mosi, int cs, int gdo0, int gdo2, uint32_t bitrate, float frequency, TX_DBM txPower, unsigned long dataRate, MOD_FORMAT modulation, int repeat  /*, int delayTime, uint8_t buffer[]*/){
	//SPI_SCK 			= sclk;	//board or mcu specific
	//SPI_MISO 			= miso; //board or mcu specific
	//SPI_MOSI 			= mosi; //board or mcu specific
	//SPI_CS 				= cs; 	//select any pin
	//RADIO_INPUT_PIN 	= gdo0; //select any pin, this is the TX-PIN
	//RADIO_OUTPUT_PIN 	= gdo2; //select any pin, this is the RX-PIN
	CC1101 cc1101(sclk, miso, mosi, cs, gdo0, gdo2);
	bitBanger.begin(bitRate, -1, gdo0); //2666
	cc1101.init();
	cc1101.setMHZ(frequency);
	cc1101.setTXPwr(txPower);
	cc1101.setDataRate(dataRate);      
	cc1101.setModulation(modulation);	
	//buffer = buffer;
}

void CC1101Button::dump_config() {
  LOG_BUTTON("", "CC1101 Component", this);
  ESP_LOGCONFIG(TAG, "  CC1101 configuration: ");
}

void CC1101Button::press_action() {
  ESP_LOGI(TAG, "Sending Buffer...");
  uint8_t buffer[] = {0b11111100, 0b10010010, 0b01001001, 0b01101101, 0b10110110, 0b01011001, 0b00100100, 0b10010010, 0b11001011, 0b01100100, 0b10110010, 0b01011001, 0b00100101, 0b10010010, 0b01001001, 0b01100100, 0b10110010, 0b01011001, 0b01100100, 0b10010010, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};

	cc1101.setTx();

	for(int i = 0; i < repeat; i++){
		bitBanger.write(buffer, sizeof(buffer) / sizeof(buffer[0]));
	}

  	cc1101.setIdle();
  }


/*
//https://github.com/wladimir-computin/CC1101-ESP-Arduino
#include "./CC1101_ESP_Arduino/CC1101_ESP_Arduino.h"

//https://github.com/wladimir-computin/espBitBanger
#include "./EspBitBanger/EspBitBanger.h"

// ESP32 PINs
const int SPI_SCK 			= 18;	//board or mcu specific
const int SPI_MISO 			= 19; 	//board or mcu specific
const int SPI_MOSI 			= 23; 	//board or mcu specific
const int SPI_CS 			= 5; 	//select any pin
const int RADIO_INPUT_PIN 	= 15; 	//select any pin, this is the TX-PIN
const int RADIO_OUTPUT_PIN 	= 13; 	//select any pin, this is the RX-PIN

// CC1101 settings
uint32_t 		bitRate 	= 2341;
float		 	frequency 	= 868.35;
TX_DBM 			txPower 	= TX_PLUS_10_DBM;
unsigned long 	dataRate 	= 10000;
MOD_FORMAT 		modulation 	= ASK_OOK;

// Transmission settings
int 	repeat 		= 10;	// Number of signals to send
int		delayTime 	= 10000;	// Time (ms) between signal repetition
//uint8_t buffer[] 	= {0b00000011, 0b11110010, 0b01001001, 0b00100101, 0b10110110, 0b11011001, 0b01100100, 0b10010010, 0b01001011, 0b00101101, 0b10010010, 0b11001001, 0b01100100, 0b10010110, 0b01001001, 0b00101101, 0b10010110, 0b01001011, 0b01101100, 0b10010010, 0b01011011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
uint8_t buffer[] 	= {0b11111100, 0b10010010, 0b01001001, 0b01101101, 0b10110110, 0b01011001, 0b00100100, 0b10010010, 0b11001011, 0b01100100, 0b10110010, 0b01011001, 0b00100101, 0b10010010, 0b01001001, 0b01100100, 0b10110010, 0b01011001, 0b01100100, 0b10010010, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};

EspBitBanger bitBanger;
CC1101 cc1101(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS, RADIO_INPUT_PIN, RADIO_OUTPUT_PIN);


	bitBanger.begin(bitRate, -1, RADIO_INPUT_PIN); //2666
	cc1101.init();
	cc1101.setMHZ(frequency);
	cc1101.setTXPwr(txPower);
	cc1101.setDataRate(dataRate);      
	cc1101.setModulation(modulation);


void loop() {
   	cc1101.setTx();
	for(int i = 0; i < repeat; i++){
		bitBanger.write(buffer, sizeof(buffer) / sizeof(buffer[0]));
	}
  	cc1101.setIdle();
	delay(delayTime);
}

*/
