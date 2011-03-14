//@Module : A module which gives the greatest common divider of two integers
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011


#include "systemc.h"
#include "pgcd_fsm.h"

void next_cycle (sc_signal<bool> &signal_clk);

int sc_main(int argc, char *argv[])
{
    int i,j,k;
    ofstream fichier("pgcd_fsm.csv", ios::out | ios::trunc);
    sc_signal<bool> clk;
    sc_signal<bool> start;
    sc_signal<bool> reset;
    sc_signal<bool> done;
    sc_signal<unsigned char> x;
    sc_signal<unsigned char> y;
    sc_signal<unsigned char> out;

    sc_trace_file *my_trace_file;
    my_trace_file =
   sc_create_vcd_trace_file ("pgcd_fsm_trace");
    sc_trace(my_trace_file,clk,"clk");
    sc_trace(my_trace_file,x,"x");
    sc_trace(my_trace_file,start,"start");
    sc_trace(my_trace_file,reset,"reset");
    sc_trace(my_trace_file,done,"done");
    sc_trace(my_trace_file,y,"y");
    sc_trace(my_trace_file,out,"out");

    pgcd_fsm pgcd("greatest_common_divider");
    pgcd.clk(clk);
    pgcd.x(x);
    pgcd.y(y);
    pgcd.reset(reset);
    pgcd.out(out);
    pgcd.start(start);
    pgcd.done(done);
    reset = 0;
    next_cycle(clk);
    reset = 1;
    next_cycle(clk);
    reset = 0;

for (i=1;i<256;i++)
{   
   for(j=1;j<256;j++)
   {
    printf("%d/65536\n",i*j);
    fichier  << i <<','<< j <<',';
    next_cycle(clk);
    x=i;y=j;start=0;
    next_cycle(clk);
    start=1;
    next_cycle(clk);
    start=0;
    next_cycle(clk);
    next_cycle(clk);
    k=out;
    fichier  << int (out.read()) <<endl;
    }
}
    

    sc_close_vcd_trace_file (my_trace_file);
    fichier.close();
    return EXIT_SUCCESS;

}





void next_cycle (sc_signal<bool> &signal_clk)
{
    signal_clk = false;
    sc_start (1, SC_NS);
    signal_clk = true;
    sc_start (1, SC_NS);
}
