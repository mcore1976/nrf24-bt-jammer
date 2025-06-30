#include <SPI.h>
#include <RF24.h>

// Wiring:
// RPI2040-ONE 3V3  pin            <-> VCC  pin #1 NRF24L01
// RPI2040-ONE GND  pin            <-> GND  pin #2 NRF24L01
// RPI2040-ONE pin #29 GP29        <-> CE   pin #3 NRF24L01 
// RPI2040-ONE SPI0 CS  pin #1 GP1 <-> CNS  pin #4 NRF24L01
// RPI2040-ONE SPI0 SCK pin #2 GP2 <-> SCK  pin #5 NRF24L01
// RPI2040-ONE SPI0 TX  pin #3 GP3 <-> MOSI pin #6 NRF24L01
// RPI2040-ONE SPI0 RX  pin #0 GP0 <-> MISO pin #7 NRF24L01

uint8_t i;

// defining CE pin number,  CSN pin number on Arduino, and SPI speed to 16Mbps
RF24 radio(29, 1, 16000000);  

void setup(void) {
  Serial.begin(115200);
  Serial.println(F("Serial port initialized!!"));
  
 // here you set your Arduino board SPI pins
 // For Raspberry RP2040-ONE pin #0 is MISO, pin #1 is CSN, pin #2 is SCK, pin #3 is MOSI, pin #29 is CE of NRF24L01 
  SPI.setRX(0);
  SPI.setCS(1);
  SPI.setSCK(2);
  SPI.setTX(3);

  delay(1000);  
  Serial.println(F("SPI pins set!!"));
  
  SPI.begin();
  Serial.println(F("SPI initialized!!"));
  
  delay(1000);  
  RF();
  Serial.println(F("NRF initialized!!"));
}

void RF() {
  if (!radio.begin(&SPI)) {
    Serial.println(F("radio hardware not responding!!"));
    while (1) {} // hold program in infinite loop to prevent subsequent errors
  }

    delay(200);
    radio.setAutoAck(false);
    radio.stopListening();
    radio.setRetries(0, 0);
    radio.setPayloadSize(5);   ////SET VALUE ON RF24.CPP
    radio.setAddressWidth(3);  ////SET VALUE ON RF24.CPP
    radio.setPALevel(RF24_PA_MAX, true);
    radio.setDataRate(RF24_2MBPS);
    radio.setCRCLength(RF24_CRC_DISABLED);   
    radio.startConstCarrier(RF24_PA_MAX, 45);                                                
    radio.printPrettyDetails(); 
}

void loop(void) 
 { // JUST SWIPE THROUGH ALL 40 BLE CHANNELS
  for (i = 1; i < 80; i = i + 2) {  radio.setChannel(i); };
  }

  
