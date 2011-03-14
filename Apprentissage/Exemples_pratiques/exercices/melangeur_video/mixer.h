//@Module : A module which mixes two pixels
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"


SC_MODULE(mixer){


  //Clock
  sc_in <bool> clk;

  //First Pixel
  sc_in<sc_int<8> > R1;
  sc_in<sc_int<8> > G1;
  sc_in<sc_int<8> > B1;
  sc_in<sc_int<8> > A1;

  //Second Pixel
  sc_in<sc_int<8> > R2;
  sc_in<sc_int<8> > G2;
  sc_in<sc_int<8> > B2;
  sc_in<sc_int<8> > A2;

  //Result
  sc_out<sc_int<8> > OR;
  sc_out<sc_int<8> > OG;
  sc_out<sc_int<8> > OB;

  void mix();

  SC_CTOR(mixer)
  {
    SC_METHOD(mix);
    sensitive << clk.pos();
  }



};
