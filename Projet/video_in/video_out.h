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

#include <system.c>
#include "image.h"


/////////////////////////////////////
// structure definition
/////////////////////////////////////

SC_MODULE(VIDEO_OUT)

// IO PORTS

  
    sc_in<bool>         clk;
    sc_in<bool>         reset_n;
    
    sc_in<bool>        href;
    sc_in<bool>        vref;
    
    sc_in<unsigned char> pixel_in;
    
////////////////////////////////////
// constructor
////////////////////////////////////

    SC_CTOR(VIDEO_OUT)
    {
      SC_THREAD(gen_images);
      sensitive << clk.pos();
      sensitive << reset_n.neg();
      dont_initialize();

      base_name = "output";
      current_image_number = 0;
      image.pixel = NULL;
      
      cout << "Successful Instanciation of VIDEO_OUT module" << endl; 

    }

  private: 
  
    void gen_image();
    const char* base_name;
    int current_image_number;
    int line_number;
    int column_number;
    Image image;
    };

#endif








#endif





