////////////////////////////////////////////////////////////////////////////////
// File : average_filter.h
// Author : Laurent Charignon
// Date : 14/03/2011
// This program is released under the GNU Public License
// Copyright : ENST
//
// Ce module applique à la volée un lissage aux image d'un flux vidéo.
//////////////////////////////////////////////////////////////////////////
#ifndef AVERAGE_FILTER_H
#define AVERAGE_FILTER_H
#include "systemc.h"
#include "image.h"
#include <png.h>
#define NCOL 576
#define TOTALSIZE 2*576+1
#define BEGIN   0
#define SEND    1
#define HOLD    2

/////////////////////////////////////
// structure definition
/////////////////////////////////////

SC_MODULE(AVERAGE_FILTER)
{
// IO PORTS

  
    sc_in<bool>         clk;
    sc_in<bool>         reset_n;
    
    sc_in<bool>        _href;
    sc_out<bool>        href;
    sc_in<bool>        _vref;
    sc_out<bool>        vref;
    
    sc_in<unsigned char> pixel_in;
    sc_out<unsigned char> pixel_out;

    
////////////////////////////////////
// constructor
////////////////////////////////////

    SC_CTOR(AVERAGE_FILTER)
    {
      SC_THREAD(filter);
      sensitive << clk.pos();
      sensitive << reset_n.neg();
      dont_initialize();
      current_state=OUT_BEGIN;
      next_state=OUT_BEGIN;
      image.pixel = (unsigned char *)malloc(TOTALSIZE * sizeof(unsigned char));
      cout << "Successful Instanciation of AVERAGE FILTER module" << endl; 
      reader=0;
      cursors=0;
      line=0;
      buffer = (unsigned char * ) malloc (sizeof(unsigned char) * NCOL + 3;
    }

  private: 
    void filter();
    int current_state;
    int next_state;
    int reader;       
    int line;       
    int cursor;       
    unsigned char* buffer; 
    };

#endif














































