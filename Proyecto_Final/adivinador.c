#include"adivinador.h"
int Respuesta (void)
{
	char Respuesta[10];
	fgets (Respuesta, 9, stdin);
	return Respuesta[0] == 'S' || Respuesta[0] == 's';
}

void Borrar (struct ArbolAdivinador *A)
{
	if (A->Si)
	Borrar (A->Si);
	if (A->No)
	Borrar (A->No);
	free (A);
}

struct ArbolAdivinador *
Cargar (void)  { FILE * fe;
  struct ArbolAdivinador *A;
   fe = fopen ("backup.pan", "r");
  if (fe)
    
    {
      A = LeeArbol (fe);
      fclose (fe);
    }
  
  else
    
    {
      A = malloc (sizeof (struct ArbolAdivinador));
      strcpy (A->Texto, "Aguila");
      A->Si = NULL;
      A->No = NULL;
    } return (A);
}

  struct ArbolAdivinador *
LeeArbol (FILE * fe)  { char Linea[80];
  struct ArbolAdivinador *A;
  fgets (Linea, 80, fe);
  while (Linea[strlen (Linea) - 1] < ' ')
    Linea[strlen (Linea) - 1] = 0;
   A = malloc (sizeof (struct ArbolAdivinador));
  strcpy (A->Texto, &Linea[1]);
   if (Linea[0] == 'P')
    
    {
      A->Si = LeeArbol (fe);
      A->No = LeeArbol (fe);
    }
  
  else
    
    {
      A->Si = NULL;
      A->No = NULL;
    }
   return (A);
}
