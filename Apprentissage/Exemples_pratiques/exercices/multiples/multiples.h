//@Module : A module which gives the multiples of 2 and 3 as output
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"

SC_MODULE(multiples)
{

  sc_in <bool> clk;
  sc_in <bool> rst;
  sc_out<sc_uint<8> > out;
  sc_uint<8> last_2_multiple;
  sc_uint<8> last_3_multiple;

  void output_multiple();

  SC_CTOR(multiples)
  {
    SC_METHOD(output_multiple);
    sensitive << clk.pos();

  }

};
