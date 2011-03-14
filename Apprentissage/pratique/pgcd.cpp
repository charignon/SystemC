//@Module : A module which gives the greatest common divider of two integers
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011

#include "pgcd.h"

void pgcd::proceed(){

  //If the processing hasn't been done and the module is told to start the operation
  if (!start)
  {
    _done ? done=true : done =false;
    _done=false;
  }
  else
  {
    //ends up quickly if the two numbers are equals
    if(x.read()==y.read())
      inm =x.read();//trick to spare a variable which stocks temporarly the pgcd
    else
    { 
      //get the maximum of x and y
      if(x.read()>y.read())      
      {inM=x.read(); inm=y.read();}
      else                       
      {inM=y.read(); inm=x.read();}
      do{
      inQ= (inM/inm);
      inR=inM-inQ*inm;
      if(inR!=0)
      {
      inM=inm;
      inm=inR;
      }
      }while(inR!=0);
    }
    out=(unsigned char) inm;
    _done=true;
  }
  return ;

}
