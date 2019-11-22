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
#include"Lista.h"

typedef Lista *TablaH;

//Generar tabla a partir de un tamaño de memoria dinamica
TablaH inicTablaH(int capacidad){
	TablaH th = (TablaH)malloc(sizeof(Lista)*capacidad);
	int i,j;
	for(i = 0; i < capacidad; i++)
		th[i]=vacia();
	return th;
}

//Generar llave/ numero hash para introducir en tabla
int creallave(int numPrim, char* llave){
	int hashClave;
	int l,i,res;
	for(i = 0; i < llave[i] != '\0' ;i++){
		l = (int)(llave[i]);
		res = res + l;
	}

	hashClave =(int)(res)%(numPrim);
	return hashClave;
}

//Insertar dato de llave en tabla hash
void insTablaH(TablaH t, char txt[], int key){
	char* in = (char*)malloc(sizeof(char) * 300);
	strcpy(in,txt);
	t[key] = cons(in,t[key]);
}

//ELiminar dato mediante la llave
void eliminaDato(TablaH t, int key, int capacidad){
	int i;
	for(i=0; i < capacidad ; i++){
		if(!esvacia(t[i])){
			if(i == key){
				t[i] = vacia();
			}
		}
	}
}

//RElacion con los numero primos
int primoMod(int n){
	int i,l;
	i = 1;
	l = 0;
	while(i<=n){
		if(n%i == 0){
			l++;	}
		i++; }
		if(l == 2){
		l = 0;
		return n;
	}else{
		l = 0;
		return primoMod(n+1);
	}
}
