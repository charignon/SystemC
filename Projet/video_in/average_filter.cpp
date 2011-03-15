////////////////////////////////////////////////////////////////////////////////
// File : average_filter.h
// Author : Laurent Charignon
// Date : 14/03/2011
// This program is released under the GNU Public License
// Copyright : ENST
//
// Ce module applique à la volée un lissage aux image d'un flux vidéo.
//////////////////////////////////////////////////////////////////////////


#include <math.h>
#include "average_filter.h"




void AVERAGE_FILTER::filter()
{
  while(1)
  {
    if (reset_n == false)
    {
      current_state=BEGIN;
      next_state=BEGIN;
      wait();
    } 
    else
    {
      //Bound the pointer in the right size
      cursor=cursor%(TOTALSIZE);
      reader=reader%(TOTALSIZE);
      
      switch(current_state){
        
        //state before the start of the emission delayed by 1 line and 3 pixels
        case BEGIN:{  
                     //Generation of the outputs
                      pixel_out   =0;
                      href        =0;
                      vref        =0;



                     if(_href)
                     {
                       buffer[reader]=pixel_in;
                       reader++;
                     }
                    
                     if (reader>=TOTALSIZE)
                        next_state=SEND;
                     else
                        next_state=BEGIN;
                     break;
                   }

        case SEND:
                  {   href=1;
                      line < 3 ? vref=1: vref=0;//If we are in the 3 first line of a frame set the vref signal
                      pixel_out=  (buffer[(cursor-1)%TOTALSIZE]+
                                  buffer[(cursor)%TOTALSIZE]+
                                  buffer[(cursor+1)%TOTALSIZE]+
                                  buffer[(NCOL + cursor+1)%TOTALSIZE]+
                                  buffer[(NCOL + cursor)%TOTALSIZE]+
                                  buffer[(NCOL + cursor-1)%TOTALSIZE]+
                                  buffer[(-NCOL + cursor+1+TOTALSIZE)%TOTALSIZE]+
                                  buffer[(-NCOL + cursor+TOTALSIZE)%TOTALSIZE]+
                                  buffer[(-NCOL + cursor-1+TOTALSIZE)%TOTALSIZE])/9;
                      cursor ++;
                      if(_href)
                      {
                       buffer[reader]=pixel_in;
                       reader++;
                       next_state=SEND;
                      }
                   //   else
                    //  {
                      else{
                        col++;
                        if (col==3){col=0;
                        next_state=HOLD;}
                       
                      else 
                        next_state=SEND;  
                      }
                      //  }
                      break;
                   }
        case HOLD:{
                    href=0;
                    line < 3 ? vref=1: vref=0;//If we are in the 3 first line of a frame set the vref signal
                    pixel_out=0;

                    if(_href)
                    {
                     buffer[reader]=pixel_in;
                     col++;
                     reader++;
                    
                    if(col==3)
                    {
                        col=0;
                        line++;
                        next_state=SEND;
                    }

                    }
                        else
                         next_state=HOLD;
                    if(line==575)
                    {
                    cout << "new image" <<endl;
                      for (cursor= 0; cursor<NCOL; cursor ++)
                      buffer[cursor]=0;
                    reader=NCOL;
                    col=0;
                    line=0;
                    next_state=BEGIN;
                    }
                    break;
                  }

      }
                   current_state=next_state;
                   wait();
      }

    }





















  }




























