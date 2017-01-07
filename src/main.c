
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fractal.h"

int dimpx;
int dimpy;

long double cx;
long double cy;

long double dpi;

PPUNTO pp=NULL;


extern int calculaM(PPUNTO pp,long numiters);

void obtenDimensiones(void);
void inicializaP(void);

/**
*
*/
int main(int cargs, char ** cargs){

  long cantidad;
  long i;

  long numiters;

  if(cargs<3){
    fprintf(stderr,"No estan completos los argumentos: \n");

  }


  pp=(PPUNTO) malloc(sizeof(PUNTO)*cantidad);


  inicializaP();


  for(i=0;i<cantidad;i++){
    if(pp->terminado==0){
      calculaM(pp+i,numiters);
    }
  }



  if(pp!=NULL){
    free(pp);
  }

  return 0;
}


void obtenDimensiones(void){



}

void inicializaP(void){

}
