#ifndef mcp2515_settings_H
#define mcp2515_settings_H

//baudrate defaults to 250000
//or you can set it to one of the values below
#ifndef CAN_BAUDRATE
#define CAN_BAUDRATE 500000
#endif

//I haven't double checked these values with the datasheet so they are probably way off
//double checked 250kbps setting (it wasn't close) now fixed (i hope)

//the following assume 16MHz clock. 
#if CAN_BAUDRATE==125000
#define CNF1_Setting  (3 << BRP0)
#define CNF2_Setting  ((1<<BTLMODE)|(6<<PHSEG10)|(1 << PRSEG0)) //PS1 = (6+1)TQ //PropSeg = (1+1)TQ
#define CNF3_Setting  (5<<PHSEG20) //PS2 = (5+1)TQ
//TQ = 0.5(10)^-7
//NBT = 1(TQ) + 2(TQ) + 7(TQ) + 6(TQ) = 4(10)^-6
//1/NBT = 125000
#endif

#if CAN_BAUDRATE==250000
#define CNF1_Setting (1 << BRP0)  //BPR = 1+1
#define CNF2_Setting  ((1<<BTLMODE)|(6<<PHSEG10)|(1 << PRSEG0)) //PS1 = (6+1)TQ //PropSeg = (1+1)TQ
#define CNF3_Setting  (5<<PHSEG20) //PS2 = (5+1)TQ
//TQ = 0.25(10)^-7
//NBT = 1(TQ) + 2(TQ) + 7(TQ) + 6(TQ) = 4(10)^-6
//1/NBT = 250000
#endif

#if CAN_BAUDRATE==500000
#define CNF1_Setting  0
#define CNF2_Setting  ((1<<BTLMODE)|(6<<PHSEG10)|(1 << PRSEG0)) //PS1 = (6+1)TQ //PropSeg = (1+1)TQ
#define CNF3_Setting  (5<<PHSEG20) //PS2 = (5+1)TQ
//TQ = 0.125(10)^-7
//NBT = 1(TQ) + 2(TQ) + 7(TQ) + 6(TQ) = 4(10)^-6
//1/NBT = 5000000
#endif


#define CANINTE_Setting ((1<<MERRE)|(1<<ERRIE))
//interrupt on send/recieve error and eflg errors

#define RXB0CTRL_Setting ((1 << RXM0)|(1<<RXM1)|(1 << BUKT))
//filters/masks set to receive anythin
//roll over to buffer 1 if buffer 0 is full

#define RXB1CTRL_Setting ((1 << RXM1)|(1<<RXM0))
//filters/masks set to receive anything
 
#define BFPCTRL_Setting ((1 << B0BFE)|(1 << B1BFE)|(1<<B1BFM)|(1<<B0BFM))
//RXnBF pins set to message recieved interrupt

#define TXRTSCTRL_Setting ((1<<B2RTSM)|(1<<B2RTSM)|(1<<B2RTSM))
//TXnRTS pins set to rts mode

//CANCTRL sets different modes:
//normal mode
#define NORMAL_MODE 0
//loop back mode
#define LOOPBACK_MODE 2
//listen only mode
#define LISTENONLY_MODE 3

//default to normal mode
#ifndef CANMODE
#define CANCTRL_Setting NORMAL_MODE
//Or you can define a different mode
#else CANCTRL_Setting CANMODE
#endif

#endif
