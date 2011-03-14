//@Module : A module which gives the multiples of 2 and 3 as output
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"
#include "multiples.h"

void next_cycle (sc_signal<bool> &signal_clk);

int sc_main(int argc, char *argv[])
{
    int i;
    sc_signal<bool> clk;
    sc_signal<bool> reset;
    sc_signal<sc_uint<8> > data;

    sc_trace_file *my_trace_file;
    my_trace_file =
        sc_create_vcd_trace_file ("multiples_trace");
    sc_trace(my_trace_file, clk, "clk");
    sc_trace(my_trace_file, reset, "reset");
    sc_trace(my_trace_file, data, "data");

    multiples multiples("2/3_multiples_display");
    multiples.clk(clk);
    multiples.rst(reset);
    multiples.out(data);

    reset=0;
    next_cycle (clk);
    reset=1;
    next_cycle(clk); next_cycle(clk);
    reset=0;
    next_cycle(clk);
    reset=1;
    next_cycle(clk); next_cycle(clk);

    for(i=0; i<150; i++)
        next_cycle(clk);

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



