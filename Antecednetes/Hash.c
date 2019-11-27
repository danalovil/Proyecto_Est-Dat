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


//PROGRAMA PRINCIPAL PARA GENERAR EL NUMERO HASH
#include "tabla_hash.h"

int main(){
	int cap = 100,numPrimo,key,k;
	numPrimo  = primoMod(cap);
	TablaH th = inicTablaH(numPrimo);

	char txt[300];
	char ans[300];
	char numero[300];
//Manda arrays a nulos para despues llenar
for(k = 0; k < 300; k++){
		txt[k] = '\n';
	}
	for(k = 0; k < 300; k++){
		numero[k] = '\n';
}

 //char condicion[3] = "si";

//Apertura del archivo txt
FILE * Figuras;
	Figuras = fopen("figura.txt","r");
	char buffer[300];

	while(fgets(buffer,300,Figuras)){
		sscanf(buffer,"%[^;];' ';%[^;]",txt,numero);


		char* num = (char*)malloc(sizeof(char) * 300);
		strcpy(num,txt);
		key = creallave(numPrimo,num);


		insTablaH(th,txt,key);
		insTablaH(th,numero,key);
		printf("%d\n",key);
		printf("%s\n",txt);
    }
        	fclose(Figuras);

  }
