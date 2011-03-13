//@Module : Synchronous Ram
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"

SC_MODULE(sram)
{
  
  sc_in<sc_int<8> > addr;
  sc_in<bool>      write;
  sc_out_rv<16>    data_out;
  sc_in_rv<16>     data_in;
  sc_in<bool>      clk;

  void handle_request(); //Handle the request synchronously
  
  //Inner data
  sc_lv<16> ram_data[256];


  SC_CTOR(sram)
  {
    SC_METHOD(handle_request);
    sensitive << clk.pos();
  }

};







