# nrf24-bt-jammer

Bluetooth jammer based on NRF24L01 module and Arduino Raspberry Pico RP2040

This is a variation of orignial project from Smoochie : https://github.com/smoochiee/Bluetooth-jammer-esp32

If you intend to use RP2040 arduino module ( RP2040-one or EP2040-Zero module)  please add URL in board manager - Menu / Preferences / settings / Additional Board Manager URL : https://github.com/earlephilhower/arduino-pico/releases/download/4.0.2/package_rp2040_index.json

Then go to the Development Board > Board Manager > Search for Pico, select :  Waveshare RP2040-One board , select Port 

You have to also install RF24 library - Go to Sketch / Add library / Manage Libraries / select RF24 from TMRh20 / Install

When everything configured, code uploaded - works like in this video : https://youtu.be/fDVAxKkB4yw?si=ka-PlECdjAus9C9j

ATTENTION - for better jamming range please use EBYTE NRF24L01 modules like E01-ML01DP5 (100mW) or E01-2G4M27S (27dBm = 0,5 W)  



