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

