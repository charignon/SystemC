//@Module : A module which mixes two pixels
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "systemc.h"
#include "mixer.h"

void next_cycle (sc_signal<bool> &signal_clk);

int sc_main(int argc, char *argv[])
{
    int i;
    
    //clock
    sc_signal<bool> clk;
    
    //first pixel
    sc_signal<sc_int<8> > R1;
    sc_signal<sc_int<8> > G1;
    sc_signal<sc_int<8> > B1;
    sc_signal<sc_int<8> > A1;
    
    //second pixel
    sc_signal<sc_int<8> > R2;
    sc_signal<sc_int<8> > B2;
    sc_signal<sc_int<8> > G2;
    sc_signal<sc_int<8> > A2;

    //result of the mix
    sc_signal<sc_int<8> > OR;
    sc_signal<sc_int<8> > OB;
    sc_signal<sc_int<8> > OG;




    sc_trace_file *my_trace_file;
    my_trace_file =
    sc_create_vcd_trace_file ("mixer_trace");
    sc_trace(my_trace_file, clk, "clk");
    sc_trace(my_trace_file, R1, "Pixel1_red");
    sc_trace(my_trace_file, B1, "Pixel1_blue");
    sc_trace(my_trace_file, G1, "Pixel1_green");
    sc_trace(my_trace_file, A1, "Pixel1_transparency");
    sc_trace(my_trace_file, R2, "Pixel2_red");
    sc_trace(my_trace_file, G2, "Pixel2_green");
    sc_trace(my_trace_file, B2, "Pixel2_blue");
    sc_trace(my_trace_file, A2, "Pixel2_transparency");
    sc_trace(my_trace_file, OR, "Output_red");
    sc_trace(my_trace_file, OG, "Output_green");
    sc_trace(my_trace_file, OB, "Output_blue");
    mixer mixer("Pixel_Mixer");
    mixer.clk(clk);
    mixer.R1(R1);
    mixer.R2(R2);
    mixer.OR(OR);
    mixer.G1(G1);
    mixer.G2(G2);
    mixer.OG(OG);
    mixer.B1(B1);
    mixer.B2(B2);
    mixer.OB(OB);
    mixer.A1(A1);
    mixer.A2(A2);

    R1=200;
    B1=100;
    G1=50;
    R2=0;
    B2=0;
    G2=200;




    A1=200; A2=100;
    next_cycle (clk);
    A1=0; A2=100;
    next_cycle(clk); next_cycle(clk);
    A1=200; A2=0;
    next_cycle(clk);
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



