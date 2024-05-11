# UNO-ESP8266-COM
This repository contains all the files required for establishing and communicating data transfer between Arduino UNO and ESP8266.

## Master Code:

- In this project, ESP8266 acts a master device for I2C communication.
- The pins used for I2C communication are SDA pin 4 and SCl pin 5 
- Master sends String "Hello" to the slave device and requests the acknowledge from the slave device
- Master requests the Device Name from the slave device

## Slave Code:

Arduino is used as Slave device
### Function receiveEvent(): 
- This function is executed whenever there is a data sent from the master device
- Checks for the data on the I2C wire, if there is any data on the wire stores it in the variable recvinfo
- When it gets the string "Hello" from the Master device, executes a function requestEvent() 

### Function requestEvent():
- Upon receiving string "Hello", slave writes srting "UNO" to the Master Device


This way the handshake between Master and Slave is implemented. Master sends string "Hello" to the slave and expects the acknowledge from the slave with its device name. 