#ifndef CAN_MESSAGE_H
#define CAN_MESSAGE_H

#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>

//A class for handling simplified CAN Bus messages
//and converting different data types to and from strings

class can_msg {
  public:
    //CAN message structure//
    uint32_t id; //variable for storing 29 bit extended id
    uint8_t data[8]; //8 data bytes
        
    //represting can message in uart string using ascii
      //HT representing start of message
      //8 chars representing id in hex
      //8 data characters
      //2 chars representing checksum in hex
      //NL representing end of message
    uint8_t uart_str[20];
        
    bool set_id(uint32_t); //sets message id
    bool set_data(uint8_t _data[8]); //sets message data
        
    //converting numbers to ascii data
          bool int_2_data(int32_t _data);
          bool float_2_data(float data);
          bool double_2_data(double data);
        
          //building uart string
          bool build_uart_string(uint32_t id,uint8_t _data[8]);
        
      private:
          uint8_t length = 8;
          bool extended_id = 1;
          bool rts = 0;
};




#endif
