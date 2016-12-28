#ifndef MCP2515_PINS_H
#define MCP2515_PINS_H

//CAN CS pin
#define DDR_CAN_CS DDRB
#define PORT_CAN_CS PORTB
#define P_CAN_CS 2
#define CAN_CS_HIGH PORT_CAN_CS |= (1 << P_CAN_CS);
#define CAN_CS_LOW PORT_CAN_CS &= ~(1 << P_CAN_CS);

//TX0 Request to send pin
#define DDR_CAN_TX0RTS DDRD
#define PORT_CAN_TX0RTS PORTD
#define P_CAN_TX0RTS 5
#define CAN_TX0RTS_HIGH PORT_CAN_TX0RTS |= (1 << P_CAN_TX0RTS); //macro for turning pin on
#define CAN_TX0RTS_LOW PORT_CAN_TX0RTS &= ~(1 << P_CAN_TX0RTS); //macro for turning pin off

//TX1 Request to send pin
#define DDR_CAN_TX1RTS DDRD
#define PORT_CAN_TX1RTS PORTD
#define P_CAN_TX1RTS 6
#define CAN_TX1RTS_HIGH PORT_CAN_TX1RTS |= (1 << P_CAN_TX1RTS); //macro for turning pin on
#define CAN_TX1RTS_LOW PORT_CAN_TX1RTS &= ~(1 << P_CAN_TX1RTS); //macro for turning pin off

//TX0 Request to send pin
#define DDR_CAN_TX2RTS DDRD
#define PORT_CAN_TX2RTS PORTD
#define P_CAN_TX2RTS 7
#define CAN_TX2RTS_HIGH PORT_CAN_TX2RTS |= (1 << P_CAN_TX2RTS); //macro for turning pin on
#define CAN_TX2RTS_LOW PORT_CAN_TX2RTS &= ~(1 << P_CAN_TX2RTS); //macro for turning pin off

#define DDR_CAN_RX0BF DDRD
#define PIN_CAN_RX0BF PIND
#define P_CAN_RX0BF 3
#define READ_RX0BF (PIN_CAN_RX0BF & (1 << P_CAN_RX0BF)) //macro for reading pin

#define DDR_CAN_RX1BF DDRD
#define PIN_CAN_RX1BF PIND
#define P_CAN_RX1BF 4
#define READ_RX1BF (PIN_CAN_RX1BF & (1 << P_CAN_RX1BF)) //macro for reading pin

#define DDR_INT DDRD
#define PIN_CAN_INT PIND
#define P_CAN_INT 2
#define READ_CAN_INT (PIN_CAN_INT & (1 << P_CAN_INT)) //macro for reading pin

#endif
