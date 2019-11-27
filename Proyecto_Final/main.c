#include"adivinador.h"
#define TRUE 1
#define FALSE 0
/* Funcion principal, cuerpo de programa */
int
main ()
{
  struct ArbolAdivinador *Raiz=NULL;	/* struct ArbolAdivinador raiz del arbol */
  struct ArbolAdivinador *Q=NULL, *P=NULL;
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
      printf ("Instrucciones: \n Para Si = S|s \n No = *Cualquier tecla*\n");
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
      while (Q->Si);		/* do...while, miestras haya preguntas por hacer */
      if (Resp1)		/* Si la ultima respuesta fue Si, el programa ha adivinado el animal */
	printf ("Lo he adivinado!!!\n");
      else			/* En caso contrario, es que no lo conoce */
	{
	  printf ("No conozco este animal, pero si me respondes a unas\n");
	  printf ("preguntas lo incluire en mi lista.\n");

	  do			/* Este bucle asegura que no se añadiran nodos con errores */
	    {
	      printf ("\nDe que animal se trata?\n");
	      fgets (Nuevo, 80, stdin);	/* Lee el nombre del animal */
	      while (Nuevo[strlen (Nuevo) - 1] < ' ')
		Nuevo[strlen (Nuevo) - 1] = 0;	/* Elimina retorno de linea */
	      printf ("Dame una pregunta que sirva para distinguir un/a\n");
	      printf ("%s\nde un/a\n%s\n", P->Texto, Nuevo);
	      printf ("a la que se pueda contestar si o no:\n");
	      fgets (Pregunta, 80, stdin);	/* Lee la progunta para distinguir el nuevo animal */
	      while (Pregunta[strlen (Pregunta) - 1] < ' ')
		Pregunta[strlen (Pregunta) - 1] = 0;	/* Elimina retorno de linea */
	      printf ("Que respuesta se ha de dar a esta pregunta:\n");
	      printf ("%s?\n", Pregunta);
	      printf ("Para obtener: %s\n", Nuevo);
	      printf ("como respuesta: Si o No:\n");
	      Resp1 = Respuesta ();	/* Lee la respuesta adecuada a la pregunta leida */

	      /* Muestra al jugador los datos leidos para que verifique si son correctos */
	      printf ("Veamos si lo he entendido bien:\n");
	      printf ("A la pregunta: %s?\n", Pregunta);
	      if (Resp1)
		{
		  printf ("Si se responde SI se trata de un %s\n", Nuevo);
		  printf ("y si se responde NO podria ser un %s\n", P->Texto);
		}
	      else
		{
		  printf ("Si se responde SI se trata de un %s\n", P->Texto);
		  printf ("y si se responde NO podria ser un %s\n", Nuevo);
		}
	      printf ("Es correcto?");
	      Resp2 = Respuesta ();	/* Si Resp2==TRUE, los datos son correctos */
	    }
	  while (!Resp2);	/* Repite el proceso hasta que el jugador de el visto bueno */

	  /* Añadir el nodo nuevo */
	  Q = malloc (sizeof (struct ArbolAdivinador));	/* Creamos un nodo nuevo */
	  strcpy (Q->Texto, P->Texto);	/* Copiamos el Animal nuevo al nuevo Nodo */
	  Q->Si = NULL;		/* Como es un nodo hoja, Q->Si */
	  Q->No = NULL;		/* y  Q->No seran NULL */
	  if (Resp1)
	    P->No = Q;		/* Caso a) Rama de P->No es el animal 1 */
	  else
	    P->Si = Q;		/* Caso b) Rama de P->Si es el animal 1 */
	  Q = malloc (sizeof (struct ArbolAdivinador));	/* Creamos un nuevo nodo */
	  strcpy (Q->Texto, Nuevo);	/* para el nuevo animal */
	  Q->Si = NULL;		/* que también es un nodo hoja */
	  Q->No = NULL;
	  if (Resp1)
	    P->Si = Q;		/* Caso a) Rama de P->Si es el animal nuevo */
	  else
	    P->No = Q;		/* Caso b) Rama de P->No es el animal nuevo */
	  strcpy (P->Texto, Pregunta);	/* El nodo Original es ahora la pregunta */
	}
      /* Pregunta al jugador si quiere seguir jugando */
      printf
	("¿Deseas terminar el juego? (Si/No) \nSi respondes que 'Si' saldras del programa \ny guardaras los nuevos animales propuestos (si los hubo). \nSi tu respuesta es 'No', regresaras al comienzo del juego.\n");
      Salir = Respuesta ();
    }
  while (!Salir);		/* Permanece jugando mientras se responda que si */

  /* Ultimos pasos */
  Guardar (Raiz);		/* Guarda el arrbol en disco */
  /* VerArbol (Raiz);		/* Despliega el arbol */
  Borrar (Raiz);		/* Borra memoria dinamica */
  return 0;
}
