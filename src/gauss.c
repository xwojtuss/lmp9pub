#include "gauss.h"
#include <stdio.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int	eliminate(Matrix *mat, Matrix *b)
{
	double	f;
	int		maxRow;
	double	temp;

	f = 0;
	for (int i = 0; i < mat->c - 1; i++)
	{
		maxRow = i;
		for (int j = i + 1; j < mat->r; j++)
			if (fabs(mat->data[j][i]) > fabs(mat->data[maxRow][i]))
				maxRow = j;
		if (maxRow != i)
		{
			for (int k = 0; k < mat->c; k++)
			{
				temp = mat->data[i][k];
				mat->data[i][k] = mat->data[maxRow][k];
				mat->data[maxRow][k] = temp;
			}
			temp = b->data[i][0];
			b->data[i][0] = b->data[maxRow][0];
			b->data[maxRow][0] = temp;
		}
		for (int j = i + 1; j < mat->r; j++)
		{
			if (mat->data[i][i] == 0)
				return (1);
			f = mat->data[j][i] / mat->data[i][i];
			for (int k = i; k < mat->c; k++)
				mat->data[j][k] -= mat->data[i][k] * f;
			b->data[j][0] -= b->data[i][0] * f;
		}
	}
	return (0);
}
