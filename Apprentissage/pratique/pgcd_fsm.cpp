//@Module : A module which gives the greatest common divider of two integers
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011
#include "pgcd_fsm.h"

void pgcd_fsm::run(){

  //If the processing hasn't been done and the module is told to start the operation
  if (reset)
  {
  current_state=IDLE;
  next_state=IDLE;
  }
  while(1)
  {
    wait();
    current_state=next_state;

    switch(current_state)
    {

      case IDLE:
        {
        done=false;
        if(start)
          next_state=PROCEED;
        else 
          next_state=IDLE;
        break;
        }

      case PROCEED:
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
        done=true;
        next_state=HOLD;
        break;
        }
        
      case HOLD:
        {
        done=true;
        next_state=IDLE;
        break;
        }


    }




  }
  return ;

}
