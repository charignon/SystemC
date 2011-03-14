//@Module : A simple 1 bit shift register
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"

SC_MODULE(shift_register)
{

  sc_in <bool> clk;
  sc_in<bool> in;
  sc_out<bool> out;

  void proceed();

  SC_CTOR(shift_register)
  {
    SC_METHOD(proceed);
    sensitive << clk.pos();
  }

};
