//@Module : A module which gives the greatest common divider of two integers
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"

SC_MODULE(pgcd)
{

  sc_in <bool> clk;
  
  //inputs
  sc_in<unsigned char > x;
  sc_in<unsigned char > y;
  
  //output
  sc_out<unsigned char > out;

  //start the operation to determine the greatest common divider of x and y 
  sc_in <bool> start;

  //processing is done, pgcd contains the result
  sc_out <bool> done;

  //internal variables
  bool _done;
  unsigned char  inM;
  unsigned char  inm;
  unsigned char  inQ;
  unsigned char  inR;

  void proceed();

  SC_CTOR(pgcd)
  {
    _done=false;
    SC_METHOD(proceed);
    sensitive << clk.pos();
  }

};
