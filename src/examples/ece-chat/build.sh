#!/bin/bash
make clean && rm -rf f obj*
make all TARGET=avr-atmega128rfa1
avr-objcopy -O ihex -R .eeprom -R .fuse -R .signature ece-chat.avr-atmega128rfa1 ece-chat.hex
