#include "backsubst.h"
#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		res;
	Matrix	*A;
	Matrix	*b;
	Matrix	*x;

	if (argc != 3)
		return (fprintf(stderr, "Zła liczba argumentów\n"), -3);
	A = readFromFile(argv[1]);
	b = readFromFile(argv[2]);
	if (A == NULL)
		return (-1);
	if (b == NULL)
		return (-2);
	printf("Macierz A:\n");
	printToScreen(A);
	printf("Macierz b:\n");
	printToScreen(b);
	res = eliminate(A, b);
	printf("Macierz A po eliminacji:\n");
	printToScreen(A);
	printf("Macierz b po eliminacji:\n");
	printToScreen(b);
	x = createMatrix(b->r, 1);
	if (x != NULL)
	{
		res = backsubst(x, A, b);
		if (res == 1)
			printf("Błąd, dzielenie przez 0\n");
		else if (res == 2)
			printf("Błąd, złe rozmiary macierzy\n");
		printf("Macierz A po podstawieniu wstecznym:\n");
		printToScreen(A);
		printf("Macierz b po podstawieniu wstecznym:\n");
		printToScreen(b);
		printf("Wynik (Macierz x):\n");
		printToScreen(x);
		freeMatrix(x);
	}
	else
		fprintf(stderr, "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	freeMatrix(A);
	freeMatrix(b);
	return (0);
}
