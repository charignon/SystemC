//@Module : Synchronous Ram
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"
#include "SRAM.h"

void next_cycle (sc_signal<bool> &signal_clk);

int sc_main(int argc, char *argv[])
{
    int i;
    sc_signal<bool> clk;
    sc_signal<sc_int<8> > addr;
    sc_signal_rv<16> data_in;
    sc_signal_rv<16> data_out;
    sc_signal<bool> write;

    sc_trace_file *my_trace_file;
    my_trace_file =
        sc_create_vcd_trace_file ("sram_trace");
    sc_trace(my_trace_file, clk, "clk");
    sc_trace(my_trace_file, addr, "addr");
    sc_trace(my_trace_file, data_in, "data_in");
    sc_trace(my_trace_file, data_out, "data_out");
    sc_trace(my_trace_file, write, "write");

    sram sram("Synchronous_RAM");
    sram.clk(clk);
    sram.addr(addr);
    sram.data_in(data_in);
    sram.data_out(data_out);
    sram.write(write);

    addr=22 ; write = 1; data_in=34;
    next_cycle (clk);
    addr=23 ; write = 1; data_in=42;
    next_cycle(clk); next_cycle(clk);
    write = 0; addr=25 ;
    next_cycle(clk);
    write = 0; addr=22 ;
    next_cycle(clk); next_cycle(clk);

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



