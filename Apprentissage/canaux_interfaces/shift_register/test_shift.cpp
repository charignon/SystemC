//@Module : A module which gives the multiples of 2 and 3 as output
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"
#include "shift_register.h"

void next_cycle (sc_signal<bool> &signal_clk);

int sc_main(int argc, char *argv[])
{
    int i;
    sc_signal<bool> clk;
    sc_signal<bool> in;
    sc_signal<bool> in2;
    sc_signal<bool> in3;
    sc_signal<bool> in4;
    sc_signal<bool> out;

    sc_trace_file *my_trace_file;
    my_trace_file =
        sc_create_vcd_trace_file ("shifter_trace");
    sc_trace(my_trace_file, clk, "clk");
    sc_trace(my_trace_file, in, "in");
    sc_trace(my_trace_file, in2, "in2");
    sc_trace(my_trace_file, in3, "in3");
    sc_trace(my_trace_file, in4, "in4");
    sc_trace(my_trace_file, out, "out");


    shift_register sh1("1rst_shifter");
    shift_register sh2("2nd_shifter");
    shift_register sh3("3rd_shifter");
    shift_register sh4("4th_shifter");

    sh1.clk(clk);
    sh2.clk(clk);
    sh3.clk(clk);
    sh4.clk(clk);
    
    sh1.in(in);
    sh2.in(in2);
    sh3.in(in3);
    sh4.in(in4);
  
    sh1.out(in2);
    sh2.out(in3);
    sh3.out(in4);


    sh4.out(out);


    in=0;
    next_cycle (clk);
    in=1;
    next_cycle(clk); next_cycle(clk);
    in=0;
    next_cycle(clk);
    in=1;
    next_cycle(clk); next_cycle(clk);

    for(i=0; i<90000; i++)
      {
        in=!in;
      next_cycle(clk);
      }
    sc_close_vcd_trace_file (my_trace_file);

    return EXIT_SUCCESS;

}

void next_cycle (sc_signal<bool> &signal_clk)
{
    signal_clk = false;
    sc_start (1, SC_NS);
    signal_clk = true;
    sc_start (1, SC_NS);
}



