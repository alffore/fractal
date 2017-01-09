/**
*
* https://en.wikipedia.org/wiki/Mandelbrot_set
*/
#include "fractal.h"

long numiters;
long dimpx;
long dimpy;

double cx;
double cy;
double d;
double dx;
double dy;

long dpi;

double pasox;
double pasoy;

long cantidad;
PPUNTO pp=NULL;


extern int calculaM(PPUNTO pp,long numiters);
extern void imprimeS(void);

void obtenDimensiones(void);
void inicializaP(void);
long double obtenCx(long px);
long double obtenCy(long py);

/**
*
*/
int main(int cargs, char ** args){


  /*long i;*/



  if(cargs<5){
    fprintf(stderr,"No estan completos los argumentos: \n");


    return 1;
  }

  cx=atof(*(args+1));
  cy=atof(*(args+2));
  d=atof(*(args+3));

  numiters=atol(*(args+4));

  dpi=atol(*(args+5));

  dimpx=atol(*(args+6));
  dimpy=atol(*(args+7));

  obtenDimensiones();


  pp=(PPUNTO)malloc(sizeof(PUNTO)*cantidad);


  inicializaP();

  /*for(i=0;i<cantidad;i++){
    if(pp->terminado==0){
      calculaM(pp+i,numiters);
    }
  }*/

  imprimeS();

  if(pp!=NULL){
    free(pp);
  }

  return 0;
}


void obtenDimensiones(void){

  dx=dpi*dimpx;
  dy=dpi*dimpy;

  cantidad=(long)dx*dy;

  printf("Cantidad: %ld\n",cantidad);
}

/**
*
*/
void inicializaP(void){

  long i,j;
  long cantidad_ini=0;

  for(i=0;i<dx;i++){
    for(j=0;j<dy;j++){

     (pp+i+(long)dx*j)->x=obtenCx(i);
      (pp+i+(long)dx*j)->y=obtenCy(j);
      (pp+i+(long)dx*j)->n=0;
      (pp+i+(long)dx*j)->terminado=0;

      cantidad_ini++;
    }
  }

printf("Cantidad inicializada: %ld\n",cantidad_ini);

}

long double obtenCx(long px){
  return ((2*d*px)/(dx-1))+cx-d;
}

long double obtenCy(long py){
  return ((-2*d*py)/(dy-1))+cy+d;
}
