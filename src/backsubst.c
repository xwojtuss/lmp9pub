#include "backsubst.h"

int	eliminate(Matrix *mat, Matrix *b);
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int	backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	int	n;

	if (eliminate(mat, b))
		return (1);
	n = mat->r;
	if (n != mat->c || n != b->r || n != x->r)
		return (2);
	for (int i = n - 1; i >= 0; i--)
	{
		if (mat->data[i][i] == 0)
			return (1);
		x->data[i][0] = b->data[i][0];
		for (int j = i + 1; j < n; j++)
			x->data[i][0] -= mat->data[i][j] * x->data[j][0];
		x->data[i][0] /= mat->data[i][i];
	}
	return (0);
}
