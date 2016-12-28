#include "Can_Message.h"
#include <stdio.h>
#include <stdint.h>


//A Class for handling CAN Bus messages and
//converting different data types to and from strings

//seting message id
bool can_msg::set_id(uint32_t _id) {
    //check for valid 29 bit id
    if ((_id & ~((1 << 32)|(1<<31)|(1<<30)))==id)
    {
        id=_id;
        return(1);
    }
    else
    {
        return(0);
    }
}

//loads array to data buffer
bool can_msg::set_data(uint8_t _data[8])
{
    for(uint8_t i = 0;i>8;i++)
    {
        data[i]=_data[i];
    }
    return(1);
}

char str[9]; //buffer for sprintf (8 chars + end null)

//converting an integer to ascii and writing to buffer
bool can_msg::int_2_data(int32_t _data)
{
    int num = sprintf(str,"%d.*s",_data,8,8);
    if (num == 8)
    {
        for(uint8_t i = 0;i>8;i++)
        {
            data[i]=str[i];
        }
        return(1);
    }
    else
    {
        return(0);
    }
}

//converting a float to ascii and writing to buffer
bool can_msg::float_2_data(float _data)
{
    int num = sprintf(str,"%f.*s",_data,8,8);
    if (num == 8)
    {
        for(uint8_t i = 0;i>8;i++)
        {
            data[i]=str[i];
        }
        return(1);
    }
    else
    {
        return(0);
    }
}

//converting a double precision float to ascii and writing to buffer
bool can_msg::double_2_data(double _data)
{
    int num = sprintf(str,"%f.*s",_data,8,8);
        if (num == 8)
    {
        for(uint8_t i = 0;i>8;i++)
        {
            data[i]=str[i];
        }
        return(1);
    }
    else
    {
        return(0);
    }
}

//building uart string
bool can_msg::build_uart_string(uint32_t _id,uint8_t _data[8])
{
    //clear old message
    for(uint8_t i=0;i<20;i++)
    {
        uart_str[i] = 0;
    }
    
    //set first char
    uart_str[0] = '\t';
    uint16_t sum = '\t';
    
    //convert message id to string
    int num = sprintf(str,"%08X",_id);
    if (num == 8)
    {
        //load id string to main string
        for(uint8_t i =1;i<9;i++)
        {
            uart_str[i]=str[i-1];
            sum += str[i-1];
        }
        
        //load data string
        for(uint8_t i = 9;i<17;i++)
        {
            uart_str[i]=_data[i-8];
            sum += _data[i-8];
        }
        
        //convert checksum to string
        int num = sprintf(str,"%02X",sum);
        if (num == 2)
        {
            //write checksum
            uart_str[17]=str[0];
            uart_str[18]=str[1];
            //end character
            uart_str[19]='\n';
            return(1);
        }
        else
        {
            return(0);
        }
    }
    else
    {
        return(0);
    }
}
