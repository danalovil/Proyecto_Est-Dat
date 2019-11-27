/*
INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO

ESTRUCTURA DE DATOS

GRUPO:1CV7
ALUMNOS:
-Angeles Hernandez Jesus Eduardo
-Alonso Villegas Daniel
-Sanchez Olvera Odra Andrea

PROYECTO FINAL*/
/////////////////////////////////////////////////////////////////////
#include "elemento.h"

//ORDENAR EL NUMERO GENERADO EN HASH
typedef char* Elem;

//Imprimir el elemento
void ImpElem(Elem e){printf("%s\n",e);}

//EL numero a guardar es mayor al segundo
int EsMoI(Elem e1, Elem e2){return e1>=e2;}

//EL numero 1 es mayor al segundo
int EsMayor(Elem e1, Elem e2){return e1>e2;}

//EL segundo numero es mayor
int EsMenor(Elem e1, Elem e2){return e1<e2;}

//Los elementos son iguales
int EsIgual(Elem e1, Elem e2){return e1==e2;}

//Implementar en archivo
void ImpElemArch(Elem e, FILE *out){fprintf(out,"%s\n",e);}

int max(int n1, int n2){
  if(n1>=n2){
    return n1;
  }
  else return n2;
}
