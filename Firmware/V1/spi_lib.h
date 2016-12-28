#ifndef SPI_LIB_H
#define SPI_LIB_H


//atmega 328p spi port is on port b
#define DDR_SPI DDRB 
#define PORT_SPI PORTB
//miso is pin 4
#define P_MISO 4 
//mosi is pin 3
#define P_MOSI 3 
//sck is pin 5
#define P_SCK 5

//SC is on port B
#define DDR_CS DDRB
#define PORT_CS PORTB
//pin 2
#define P_CS 2

//define macros for turning CS line on and off with less typing
#define CS_HIGH PORT_CS |= (1 << P_CS);
#define CS_LOW PORT_CS &= (1 << P_CS);

//sets up spi bus
void spi_init(void);

//sends/receives data over spi
unsigned char spi_putc ( unsigned char data );


#endif
