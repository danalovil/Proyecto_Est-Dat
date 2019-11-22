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

//Apertura del archivo txt
FILE * Figuras;
	Figuras = fopen("figura.txt","r");
	char buffer[300];

	while(fgets(buffer,300,Figuras)){
		sscanf(buffer,"%[^;] ;%[^;]",txt,numero);


		char* num = (char*)malloc(sizeof(char) * 300);
		strcpy(num,txt);
		key = creallave(numPrimo,num);


		insTablaH(th,txt,key);
		insTablaH(th,numero,key);
		//printf("%d\n",key);
		//printf("%s\n",txt);
    }
        	fclose(Figuras);

FILE * adivinador;
	adivinador = fopen("figura.txt","r");
	int res;
	char linea1[80];
    char linea2[80];
    char linea3[80];

	 while(fgets(linea1, 80,adivinador)) {{
		sscanf(linea1,"%[^;];\n",txt);
		printf("%s",txt);
        scanf("%d",&res);
        while (res == 0){
            while(fgets(linea2, 80,adivinador)) {
            sscanf(linea2,"%[^;]\n",txt);
            printf("%s",txt);
        }
        fclose(adivinador);
    }


   }

   fclose(adivinador);

}}
