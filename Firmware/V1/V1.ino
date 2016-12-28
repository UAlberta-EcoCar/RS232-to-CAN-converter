#include <Arduino.h>

#include "spi_lib.h"

#include "Can_Message.h"
#include "mcp2515_defs.h"
#include "mcp2515_filters.h"
#include "mcp2515_settings.h"
#include "mcp2515_lib.h"


void setup ()
{
  Serial.begin(9600);
  can_init(0,0,0,0,0,0,0,0);
}

CanMessage message;

void loop ()
{
  if(check_for_errors())
  {
    
  }

  if(check_for_message())
  {
    message = can_get_message();
  }
}
