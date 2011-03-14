////////////////////////////////////////////////////////////////////////////////
// File : video_out.h
// Author : Laurent Charignon
// Date : 14/03/2011
// This program is released under the GNU Public License
// Copyright : ENST
//
// Ce module modélise le fonctionnement d'un récepteur video.
// Il reçoit un flux au format ..... et crée les images png composant la vidéo.
// Inspiré dans l'agencement des éléments par le code de 
// video_in écrit pas Alexis Polti.
//////////////////////////////////////////////////////////////////////////




#ifndef VIDEO_OUT_H
#define VIDEO_OUT_H

#include "systemc.h"
#include "image.h"
#include <png.h>


#define OUT_BEGIN 0
#define OUT_MIDDLE 1
#define GATHERING 2










/////////////////////////////////////
// structure definition
/////////////////////////////////////

SC_MODULE(VIDEO_OUT)
{
// IO PORTS

  
    sc_in<bool>         clk;
    sc_in<bool>         reset_n;
    
    sc_in<bool>        href;
    sc_in<bool>        vref;
    
    sc_in<unsigned char> pixel_in;
    Image image;
    
////////////////////////////////////
// constructor
////////////////////////////////////

    SC_CTOR(VIDEO_OUT)
    {
      SC_THREAD(read_flow);
      sensitive << clk.pos();
      sensitive << reset_n.neg();
      SC_THREAD(write_image);
      sensitive << clk.pos();
      dont_initialize();
      flush=false;
      base_name = "output";
      current_image_number = 0;

      cout << "Successful Instanciation of VIDEO_OUT module" << endl; 

    }

  private: 
    void read_flow();
    void write_image();
    const char* base_name;
    int current_image_number;
    bool flush;
    int line_number;
    int column_number;
    int current_state;
    int next_state;
    };

#endif





