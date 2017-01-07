#include "fractal.h"

extern long double cx;
extern long double cy;


int calculaM(PPUNTO pp,long numiters);




int calculaM(PPUNTO pp,long numiters){

  long i=0;
  long double x=0;
  long double y=0;
  long double aux_x;

  for(i=0;i<numiters;i++){
    aux_x=x*x-y*y+pp->x;
    y=2*x*y+pp->y;
    x=aux_x;
    pp->n++;
    if(checaRadio(x,y)==1){
      pp->terminado=1;
      return i;
    }
  }

}

/**
*
*/
int checaRadioP(PUNTO pp){
  return ((pp->x*pp->x+pp->y*pp->y)>=2.0)?1:0;
}

int checaRadioC(long double x,long double y){
  return ((x*x+y*y)>=2.0)?1:0;
}
