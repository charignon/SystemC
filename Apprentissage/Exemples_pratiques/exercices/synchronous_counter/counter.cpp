//@Module : Synchronous eight bits counter (mod 127)
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "counter.h"

void count8mod127::count()
{
  if(rst==false)
  {value=0;}
  else
  {
    if (value!=127)
      value++;
    else
      value=0;
  }
    out=value;
};

