# nrf24-bt-jammer

Bluetooth jammer based on NRF24L01 module and Arduino Raspberry Pico RP2040

This is a variation of orignial project from Smoochie : https://github.com/smoochiee/Bluetooth-jammer-esp32

If you intend to use RP2040 arduino module please add URL in board manager - Menu / Preferences / settings / Additional Board Manager URL : https://github.com/earlephilhower/arduino-pico/releases/download/4.0.2/package_rp2040_index.json

Then go to the Development Board > Board Manager > Search for Pico, selec Waveshare RP2040-One board , select Port 

You have to also install RF24 library - Go to Sketch / Add library / Manage Libraries / select RF24 from TMRh20 / Install

When everything configured, code uploaded - works like in this video : https://youtu.be/fDVAxKkB4yw?si=ka-PlECdjAus9C9j

