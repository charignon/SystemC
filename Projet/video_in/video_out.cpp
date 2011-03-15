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
              image.pixel [line_number*720+column_number] = pixel_in;
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
              if (pixel_in < 200)
              image.pixel[line_number*720+column_number]=pixel_in+50;
              else
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
char name[2048];
line_number = 0; 
column_number = 0; 
sprintf(name,"%s%02d.png",base_name,current_image_number);
image_write(&image,name);
current_image_number++;
flush=false;
}
wait(1);
}
return;
}
