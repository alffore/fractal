#include "fractal.h"

extern long cantidad;
extern PPUNTO pp;

void imprimeS(void);



void imprimeS(void){

  long i;

for(i=0;i<cantidad; i++){

  printf("%Lf,%Lf,%ld,%d\n",(pp+i)->x,(pp+i)->y,(pp+i)->n,(pp+i)->terminado);

}


}
