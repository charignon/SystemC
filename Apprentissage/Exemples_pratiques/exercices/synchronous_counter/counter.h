//@Module : Synchronous eight bits counter (mod 127)
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"

SC_MODULE(count8mod127)
{
  sc_in <bool> clk;
  sc_in <bool> rst;
  sc_out<sc_uint<8> > out;
  sc_uint<8> value;

  void count();

  SC_CTOR(count8mod127)
  {
    SC_METHOD(count);
    sensitive <<clk.pos();
  }
};



