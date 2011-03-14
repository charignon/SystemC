//@Module : A module which gives the greatest common divider of two integers
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#define IDLE 0
#define PROCEED 1
#define HOLD 2
#include "systemc.h"

SC_MODULE(pgcd_fsm)
{

  sc_in <bool> clk;
  
  //inputs
  sc_in<unsigned char > x;
  sc_in<unsigned char > y;
  
  //output
  sc_out<unsigned char > out;

  //start the operation to determine the greatest common divider of x and y 
  sc_in <bool> start;
  sc_in <bool> reset;

  //processing is done, pgcd contains the result
  sc_out <bool> done;

  //internal variables
  bool _done;
  unsigned char  inM;
  unsigned char  inm;
  unsigned char  inQ;
  unsigned char  inR;
  unsigned char  current_state;
  unsigned char  next_state;

  void run();

  SC_CTOR(pgcd_fsm)
  {
    _done=false;
    SC_CTHREAD(run,clk.pos());
    reset_signal_is(reset,true);
  }

};
