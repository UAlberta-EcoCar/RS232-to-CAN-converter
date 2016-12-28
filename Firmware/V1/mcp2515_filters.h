#ifndef MCP2515_FILTER_SETTINGS_H
#define MCP2515_FILTER_SETTINGS_H


//filter mask sets which bits the filter cares about
#define LISTEN_ALL_FILTER_MASK 0x000
#define EXACT_FILTER_MASK 0x7ff
#define TYPE_MASK (0b111)
#define DEVICE_MASK (0b11 << 3)
#define MESSAGE_MASK (0b1111 << 5)
#define PRIORITY_LEVEL_MASK (0b11 << 9)


#endif