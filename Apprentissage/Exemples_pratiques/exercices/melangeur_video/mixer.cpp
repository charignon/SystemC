//@Module : A module which mixes two pixels
//@Author : Laurent Charignon
//@Course : System C athens week, Telecom ParisTech 2001
//@Date   : 13/03/2011


#include "mixer.h"

void mixer::mix(){
  //Mean of the two pixels based on their transparency value
  OR = (A1.read()*R1.read() + A2.read()*R2.read())/(A1.read()+A2.read());
  OG = (A1.read()*G1.read() + A2.read()*G2.read())/(A1.read()+A2.read());
  OB = (A1.read()*B1.read() + A2.read()*B2.read())/(A1.read()+A2.read());
  return ;

}




