#include "spi_lib.h"
#include <avr/io.h>
#include <avr/delay.h>


void spi_init(void) 
{ 
    // Enable pins for the SPI interface
    DDR_SPI |= ( 1 << P_SCK ) | ( 1 << P_MOSI ) ; 
    PORT_SPI &= ~( ( 1 << P_SCK ) | ( 1 << P_MOSI ) | ( 1 << P_MISO ) ) ;
    //CS pin has to be set to out put even if you're using another pin for actual CS function
    DDR_CS |= ( 1 << P_CS ) ;
    CS_HIGH
    // Enable the SPI master interfaces, fosc = fclk /  2 == fast :)
    SPCR = ( 1 << SPE ) | ( 1 << MSTR );
    SPSR = ( 1 << SPI2X ) ; 
}

unsigned char spi_putc ( unsigned char data ) 
{ 
    // Sends a byte
    SPDR = data; 
    // Waits for byte to send 
    while ( ! ( SPSR & ( 1 << SPIF ) ) ); 
    // Return received data
    return SPDR; 
}
