//@Module : A module which gives the multiples of 2 and 3 as output
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "multiples.h"

void multiples::output_multiple(){

  if (rst==false)
  {
    last_2_multiple=0;
    last_3_multiple=0;
  }

  if(last_2_multiple+2<last_3_multiple+3)
  {
    last_2_multiple+=2;
    out=last_2_multiple;
  }
  else
  {
    if(last_3_multiple+3<last_2_multiple+2)
    {
      last_3_multiple+=3;
      out=last_3_multiple;
    }

    else
    {
      last_2_multiple+=2;
      last_3_multiple+=3;
      out=last_3_multiple;
    }

  }
}
