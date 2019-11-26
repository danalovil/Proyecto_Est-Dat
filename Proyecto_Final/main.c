#include"adivinador.h"
#define TRUE 1
#define FALSE 0
/* Funcion principal, cuerpo de programa */
int main ()
{
  struct ArbolAdivinador *Raiz;	/* struct ArbolAdivinador raiz del arbol */
  struct ArbolAdivinador *Q, *P;
  int Salir = FALSE;		/* Mientras Salir sea FALSE continua jugando */
  int Resp1;			/* Almacena respuestas basicas (Si/No, True/False) */
  int Resp2;			/* Almacena respuestas para añadir nodos al arbol */
  char Nuevo[80];		/* Nombre de animal nuevo */
  char Pregunta[80];		/* Pregunta para distinguir animal nuevo */
  Raiz = Cargar ();		/* Leer el arbol desde archivo */

  do
    {
      /* Inicio del juego */
      printf ("Piensa en un animal y yo intentare adivinarlo.\n");
      printf ("Pulsa la tecla Enter para comenzar.\n");
      Respuesta ();
      P = Raiz;			/* P apunta al nodo raiz, P = nodo actual */

      do			/* Bucle, hasta obtener una respuesta (hoja) */
	{
	  Q = P;		/* Guardamos un puntero a P, para preguntar en el do-while */
	  if (P->Si)		/* Si existen nodos en cualquiera de las ramas
				   se trata de una pregunta, si no, es una respuesta */
	    printf ("%s?\n", P->Texto);	/* Muestra la pregunta al jugador */
	  else
	    printf ("Se trata de: %s\n", P->Texto);	/* Muestra la posible respuesta */
	  Resp1 = Respuesta ();	/* Lee la respuesta del jugador */
	  if (P->Si)		/* Si aun hay nodos, moverse a la rama adecuada */
	    if (Resp1)
	      P = P->Si;
	    else
	      P = P->No;	/* Dependiendo de la respuesta */
	}
/* Agregar faltante, como lo comentamos, quitar comentario cuando ingresen codigo */
return 0;
}
