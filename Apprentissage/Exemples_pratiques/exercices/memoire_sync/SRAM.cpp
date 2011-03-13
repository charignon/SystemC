//@Module : Synchronous Ram
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "SRAM.h"


void sram::handle_request()
{
  if(write)
    ram_data[addr.read()]=data_in;
  else
    data_out=ram_data[addr.read()];

}
