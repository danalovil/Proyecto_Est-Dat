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

//GUARDAR LOS NUMEROS HASH EN LISTA
//Defincion de nodos
typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
	}*Lista;

//Lista apunta al NULL
Lista vacia(){return NULL;}

//Creacion de listas
Lista cons(Elem e, Lista l){
	Lista t=(Lista)malloc(sizeof(struct Nodo));
	t->dato=e; t->sig=l;
	return t;
	}

//COmprobar que esta vacia
int esvacia(Lista l){return l==NULL;}

//Mostrar elemento de cabecera
Elem cabeza(Lista l){return l->dato;}

//Mostrar datos siguientes a cabecera
Lista resto(Lista l){return l->sig;}

//Iprimir lista
void ImpLista(Lista l,char* num,int cond,int cont){
	if(!esvacia(l)){
		if(cabeza(l) != NULL){
			if(strcmp(cabeza(l),num) == 0){
				cond = 1;
			}}
		if(cond == 1){
			ImpElem(cabeza(l));
			cont++;
		}
		if(cont > 2){
			cond = 0;
		}
		ImpLista(resto(l),num,cond,cont);
 }
}

//Concateacion de listas
Lista concat(Lista l, Lista m){
    if(esvacia(l))
        return m;
    else
        return cons(cabeza(l), concat(resto(l),m));
}

//Invertir lista
Lista Invierte(Lista l){
    if(esvacia(l))
        return l;
    else
        return concat(Invierte(resto(l)),cons(cabeza(l), vacia()));
}

//Obtener poscicion de elemnto en lista
int NumElem(Lista l){
    if(esvacia(l))
        return 0;
    else
        return 1 + NumElem(resto(l));
}

//Insertar datos en orden
Lista InsOrd(Elem e, Lista l){
	if(esvacia(l))
		return cons(e,vacia());
	else if(EsMoI(e,cabeza(l)))
		return cons(e,l);
	else
		return cons(cabeza(l),InsOrd(e,resto(l)));
}

//Mostar lista en orden
Lista OrdList(Lista l){
	if (esvacia(l))
		return l;
	else
		return InsOrd(cabeza(l),OrdList(resto(l)));
}

//Imprimir lista desde archivo
void ImpListaArch(Lista l, FILE *out){
	if(!esvacia(l)){
        ImpElemArch(cabeza(l),out);
        ImpListaArch(resto(l),out);
    }
}
