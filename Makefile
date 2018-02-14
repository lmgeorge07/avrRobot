
makeme:
	avr-gcc -Wall -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c $(in1).c
	avr-gcc -Wall -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c $(in2).c
	avr-gcc -Wall -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c $(in3).c
	avr-gcc -Wall -O0 -DF_CPU=16000000UL -mmcu=atmega328p -c $(in4).c
	avr-gcc -O0 -DF_CPU=16000000UL -mmcu=atmega328p -o $(out).elf $(in1).o $(in2).o $(in3).o $(in4).o
	avr-objcopy -O ihex -R .eeprom $(out).elf $(out).hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$(out).hex
