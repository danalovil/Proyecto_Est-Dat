#include"adivinador.h"
int
Respuesta (void)
{
  char Respuesta[10];
  fgets (Respuesta, 9, stdin);
  return Respuesta[0] == 'S' || Respuesta[0] == 's';
}

void
Borrar (struct ArbolAdivinador *A)
{
  if (A->Si)
    Borrar (A->Si);
  if (A->No)
    Borrar (A->No);
  free (A);
}

struct ArbolAdivinador *
Cargar (void)
{
  FILE *fe;
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
LeeArbol (FILE * fe)
{
  char Linea[80];
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

void
Guardar (struct ArbolAdivinador *A)
{
  FILE *fs;
  fs = fopen ("backup.pan", "w");
  EscribeArbol (fs, A);
  fclose (fs);
} void

EscribeArbol (FILE * fs, struct ArbolAdivinador *A)
{
  if (A->Si)
    {
      fprintf (fs, "P%s\n", A->Texto);
      EscribeArbol (fs, A->Si);
      EscribeArbol (fs, A->No);
    }

  else
    fprintf (fs, "R%s\n", A->Texto);
}

void
VerArbol (struct ArbolAdivinador *A)
{
  int n, i;
  for (i = 0; i < n; i++)
    putchar (' ');
  n += 3;
  printf (">%s\n", A->Texto);
  if (A->Si)
    {
      printf ("S ");
      VerArbol (A->Si);
    }
  if (A->No)
    {
      printf ("N ");
      VerArbol (A->No);
    }
  n -= 3;
}
