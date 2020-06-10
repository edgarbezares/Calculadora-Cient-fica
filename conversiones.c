#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void binario(float resultado);
void octal(float resultado);
void hexa(float resultado);
void sexa(float resultado);
int main(){
    char hexadecimal;
    float resultado;
    printf("Introduzca el resultado: \n");
    scanf("%f", &resultado);
    binario(resultado);
    octal(resultado);
    hexa(resultado);
    sexa(resultado);
     system("pause");
}

void binario(float resultado){
    int bin[30],res,i;
    float div;
    printf("Binario: \n");
    res=trunc(resultado);
    i=0;
    while (res>0){
    bin[i]=res %2;
    res=res/2;
    i++;
    }
    i--;
      while (i>=0)
    {
          printf("%i",bin[i]);
          i--;
    }
}


void octal(float resultado){
    int oct[30],res,i;
    float div;
    printf("\nOctal: \n");
    res=trunc(resultado);
    i=0;
    while (res>0){
    oct[i]=res %8;
    res=res/8;
    i++;
    }
    i--;
      while (i>=0)
    {
          printf("%i",oct[i]);
          i--;
    }
}

void hexa(float resultado){
    int res,i;
    char hexa[30];
    float div;
    printf("\Hexa: \n");
    res=trunc(resultado);
     ltoa(resultado, hexa, 16);
     printf("Hexadecimal: %s \n",hexa);
}

void sexa(float resultado){
    float dec,ope1,ope2;
    int num,grados,minutos,segundos;
    grados=trunc(resultado);
    dec=resultado-grados;
    ope1=dec*60;
    minutos=trunc(ope1);
    ope2=ope1-minutos;
    segundos=ope2*60;
    printf("Sexagesimal: \n");
    printf("%d° %d´%d´´",grados,minutos,segundos);

}

