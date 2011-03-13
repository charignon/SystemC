#include "systemc.h"

SC_MODULE(and3)
{
  sc_in<bool> e1;
  sc_in<bool> e2;
  sc_in<bool> e3;
  sc_out<bool> s;

  void compute_and()
  {
    s = e1 & e2 & e3;
  }

   SC_CTOR(and3)
    {
      SC_METHOD(compute_and);
//      sensistive << e1 << e2 <<e3;
      sensitive(e1);
      sensitive(e2);
      sensitive(e3);
    };
};
