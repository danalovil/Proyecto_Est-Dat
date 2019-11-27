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
		Nuevo[strlen (Nuevo) - 1] = 0;
	      printf ("Dame una pregunta que sirva para distinguir un/a\n");
	      printf ("%s\nde un/a\n%s\n", P->Texto, Nuevo);
	      printf ("a la que se pueda contestar si o no:\n");
	      fgets (Pregunta, 80, stdin);	/* Lee la pregunta para distinguir el nuevo animal */
	      while (Pregunta[strlen (Pregunta) - 1] < ' ')
		Pregunta[strlen (Pregunta) - 1] = 0;	
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
