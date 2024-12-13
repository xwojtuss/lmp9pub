#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    double f=0;
	for(int i=0;i<mat->c-1;i++){
		for(int j=i+1;j<mat->c;j++){
			f=mat->data[j][i]/mat->data[i][i];
			printf("%f\n",f);
			for(int k=i;k<mat->r;k++){
				mat->data[j][k]=mat->data[j][k]-(mat->data[i][k]*f);
			}
			b->data[j][0]=b->data[j][0]-(b->data[i][0]*f);

		}
	}

		return 0;
}

