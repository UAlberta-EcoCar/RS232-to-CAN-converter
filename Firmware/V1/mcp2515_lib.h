
#ifndef MCP2515_LIB_H
#define MCP2515_LIB_H

#include <arduino.h>
#include "mcp2515_pins.h"

//this function can modify single bits in a register
//can only be used on certain registers
//ex mcp2515_bit_modify(CANINTF,(1 << RX0IF),0) clears receive buffer 0 full interrupt flag
void mcp2515_bit_modify ( unsigned char address, unsigned char mask, unsigned char data );

//this function returns the value of a register
//ex "int val = mcp2515_read_register(CANINTF);" reads interrupt flags
unsigned char mcp2515_read_register(unsigned char adress);

// Reads the rx status register
unsigned char mcp2515_read_rx_status ( void ); 

//sets up the mcp2515
// also configures spi
unsigned int can_init(uint16_t MASK0, uint16_t FILTER0, uint16_t FILTER1, uint16_t MASK1, uint16_t FILTER2, uint16_t FILTER3, uint16_t FILTER4, uint16_t FILTER5);


//writes to a register
void mcp2515_write_register( unsigned char address, unsigned char data ) ;

// a few macros for using the general io pins
#define read_TXnRTS_pins (7 & (mcp2515_read_register(TXRTSCTRL) >> 3))
#define RXnBF_pins_on mcp2515_write_register(BFPCTRL,BFPCTRL_Setting|(1<<B1BFS)|(1<<B0BFS));
#define RXnBF_pins_off mcp2515_write_register(BFPCTRL,BFPCTRL_Setting);


//structure for building can messages to send to can_send_message()
typedef struct 
{ 
    uint16_t   id = 0;
    uint32_t   extended_id = 0;
    bool    RTransR = 0;
    uint8_t    length = 0;
	  uint8_t    data [8] = {0,0,0,0,0,0,0,0};
} CanMessage; 


//sends can message
unsigned char can_send_message ( CanMessage *p_message );

bool check_for_errors();

bool check_for_message();

//receive can message
CanMessage can_get_message ( void ) ;

#endif
