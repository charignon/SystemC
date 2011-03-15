////////////////////////////////////////////////////////////////////////////////
// File : average_filter.h
// Author : Laurent Charignon
// Date : 14/03/2011
// This program is released under the GNU Public License
// Copyright : ENST
//
// Ce module applique à la volée un lissage aux image d'un flux vidéo.
//////////////////////////////////////////////////////////////////////////



#include "average_filter.h"




void AVERAGE_FILTER::filter()
{
  while(1)
  {
    if (reset_n == false)
    {
      current_state=OUT_BEGIN;
      next_state=OUT_BEGIN;
      wait();
    } 
    else
    {


      switch(current_state){

        case OUT_BEGIN:{
            href=0;
            vref=0;

                         if(_vref)
            {buffer[loaded]=pixel_in;
              loaded++;
              next_state=LOADING;
            }
            else{
              next_state=OUT_BEGIN;
            }
          break;
        }

        case LOADING:
          {
            href=0;
            vref=0;
            if(_href)
            {
              buffer[loaded]=pixel_in;
              loaded++;
              if(loaded==READY)
              {
                loaded=0;
                next_state=PROCESSING;
              }
                else next_state=LOADING;
            }
            else
            {
              next_state=LOADING;
            }            
            break;
          }
        
        
        
        
        case SEND:
          {
            href=1;
            vref=1;
              if (cursor == 0 )
              {

              }

              else{
              pixel.out=buffer[cursor-1]+
                        buffer[cursor]+
                        buffer[cursor+1]+
                        buffer[NCOL+cursor+1]+
                        buffer[NCOL+cursor+1]+
                        buffer[NCOL+cursor+1]+
                        buffer[2*NCOL+cursor-1]+
                        buffer[2*NCOL+cursor]+
                        buffer[2*NCOL+cursor+1]+
            }



          break;}
          



      }

      current_state=next_state;
      wait();
    }














  }





















}




























