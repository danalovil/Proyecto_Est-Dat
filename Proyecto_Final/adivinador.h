#ifndef __ADIVINADOR__
#define __ADIVINADOR__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ArbolAdivinador
{
  char Texto[80];
  struct ArbolAdivinador *Si, *No;
};
int Respuesta (void);
void Borrar (struct ArbolAdivinador *);
struct ArbolAdivinador *Cargar (void);

struct ArbolAdivinador *LeeArbol (FILE * );
void Guardar (struct ArbolAdivinador *);
void EscribeArbol (FILE * , struct ArbolAdivinador *);
void VerArbol (struct ArbolAdivinador *);
#endif
