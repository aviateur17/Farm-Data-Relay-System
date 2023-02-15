//  FARM DATA RELAY SYSTEM
//
//  GATEWAY 2.000 Configuration

#include <fdrs_globals.h>
#define FDRS_DEBUG     //Enable USB-Serial debugging
#define DEBUG_CONFIG   // Displays full config info on startup 

#define UNIT_MAC     0x01  // The address of this gateway

#define USE_ESPNOW  
//#define USE_LORA
//#define USE_WIFI

// Actions -- Define what happens when a packet arrives at each interface:
// sendESPNowNbr(1 or 2); sendESPNowPeers(); sendLoRaNbr(1 or 2); broadcastLoRa(); sendSerial(); sendMQTT();
#define ESPNOWG_ACT    sendSerial();
#define SERIAL_ACT     sendESPNowNbr(2); sendLoRaNbr(2); sendESPNowPeers(); broadcastLoRa(); 
#define MQTT_ACT          
#define LORAG_ACT      sendSerial();
// Neighbor Actions
#define ESPNOW1_ACT   
#define ESPNOW2_ACT                    
#define LORA1_ACT      sendSerial();
#define LORA2_ACT 

// 
// Neighboring gateway addresses
#define ESPNOW_NEIGHBOR_1  0x00  // ESPNOW1 Address 
#define ESPNOW_NEIGHBOR_2  0x02  // ESPNOW2 Address
#define LORA_NEIGHBOR_1    0x00  // LoRa1 Address
#define LORA_NEIGHBOR_2    0x03  // LoRa2 Address

// LoRa Configuration
// LoRa Configuration
#define RADIOLIB_MODULE SX1262 //Tested on SX1276
#define USE_SX126X
#define LORA_SS  8
#define LORA_RST 12
#define LORA_DIO 14
#define LORA_TXPWR 17   // LoRa TX power in dBm (: +2dBm - +17dBm (for SX1276-7) +20dBm (for SX1278))
#define LORA_ACK        // Request LoRa acknowledgment.

//#define CUSTOM_SPI
#define LORA_SPI_SCK 5
#define LORA_SPI_MISO 19
#define LORA_SPI_MOSI 27

//Pins for UART data interface (ESP32 only)
#define RXD2 14
#define TXD2 15

// WiFi and MQTT Credentials  -- These will override the global settings
//#define WIFI_SSID   "Your SSID"  
//#define WIFI_PASS   "Your Password"

//#define MQTT_ADDR   "192.168.0.8"
//#define MQTT_PORT   1883 // Default MQTT port is 1883
//#define MQTT_AUTH   //Enable MQTT authentication 
//#define MQTT_USER   "Your MQTT Username"
//#define MQTT_PASS   "Your MQTT Password"

//Logging settings  --  Logging will occur when MQTT is disconnected
//#define USE_SD_LOG        //Enable SD-card logging
//#define USE_FS_LOG        //Enable filesystem (flash) logging
#define LOGBUF_DELAY 10000  // Log Buffer Delay - in milliseconds
#define SD_SS 0             //SD card CS pin (Use different pins for LoRa and SD)
#define LOG_FILENAME "fdrs_log.csv"

///#define USE_OLED
#define OLED_HEADER "FDRS"
#define OLED_SDA 4
#define OLED_SCL 15
#define OLED_RST 16