////////////////////////////////////////////////////////////////////////////////
// File : video_out.h
// Author : Laurent Charignon
// Date : 14/03/2011
// This program is released under the GNU Public License
// Copyright : ENST
//
// This component models a video output source : it generates png files from a standardised flow.
// 
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <png.h>
#include "video_out.h"



void VIDEO_OUT::read_flow()
{
  while(1)
  {

    if(reset_n ==false)
    {
    reset : //reset label, used later on as a goto target 
//      flush=false;
      line_number = 0; 
      column_number = 0; 
      if(current_image_number !=0)
      {
        current_image_number = 0;
          //TODO add a code to handle reset at halfway
      }
    image.pixel = (unsigned char *)malloc(TOTALSIZE * sizeof(unsigned char));
    current_state=OUT_BEGIN;
      next_state=OUT_BEGIN;
      wait();
    }
    else{

      switch(current_state){
        case OUT_BEGIN:
          {
            if(href.read())
            {
              image.pixel [line_number*720+column_number] = 2;//int(pixel_in.read());
              column_number++;
              next_state=GATHERING;
            }
            else
            {
      line_number = 0; 
      column_number = 0; 
              /*if(href || vref)
                cout <<"erreur de format";
              else*/
                next_state=OUT_BEGIN;
            }
            break;
          }

        case GATHERING:
          {
            if(href.read())
            {
              image.pixel[line_number*720+column_number]=pixel_in;
              column_number++;
              next_state=GATHERING;
            }
            else
            {

              column_number=0;
              if(line_number==576)
              {
                flush=true;
                next_state=OUT_BEGIN;
              }
              else{
                line_number ++;
                next_state=OUT_MIDDLE;
              }

            }
            break;
          }

        case OUT_MIDDLE:
          {   
            if(href.read())
            {
              image.pixel[line_number*720+column_number]=pixel_in;
              column_number++;
              next_state=GATHERING;
            }
            else
            {
              next_state=OUT_MIDDLE;
            }
            break;}
      }
      current_state=next_state;
      wait();
    }
  }
}   



void VIDEO_OUT::write_image()
{
while(1)
{
if(flush)
{
line_number = 0; 
column_number = 0; 
image_write(&image,"salut.png");
flush=false;
}
wait(1);
}
return;
}
