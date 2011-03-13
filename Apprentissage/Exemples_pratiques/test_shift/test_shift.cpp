
#include "systemc.h"
#include "shift.h"

void next_cycle (sc_signal<bool> &signal_clk);

int sc_main(int argc, char *argv[])
{
    int i;
    
    sc_signal<bool> clk;
    sc_signal<bool> in;
    sc_signal<bool> out;

    sc_trace_file *my_trace_file;
    my_trace_file =
        sc_create_vcd_trace_file ("shift_trace");
    sc_trace(my_trace_file, clk, "clk");
    sc_trace(my_trace_file, in, "in");
    sc_trace(my_trace_file, out, "out");

    shifter shifter("reg_decalage");
    shifter.clk(clk);
    shifter.din(in);
    shifter.dout(out);

    in = 0;
    next_cycle (clk);
    in = 1;
    next_cycle(clk); next_cycle(clk);
    in = 0;
    next_cycle(clk);
    in = 1;
    next_cycle(clk); next_cycle(clk);
    in=0;

    for(i=0; i<17; i++)
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



