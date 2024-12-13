#include "gauss.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    double f=0;
	int max=0;
	double temp;
	for(int i=0;i<mat->c-1;i++){
		max=i;
		for(int j=i+1;j<mat->c;j++){
			if(mat->data[i][i]<0){
				if(mat->data[j][i]<0){
					if(-(mat->data[j][i])>-(mat->data[i][i])){
						max=j;
					}
				}else{
					if((mat->data[j][i])>-(mat->data[i][i])){
						max=j;
					}
				}
			}else{
				if(mat->data[j][i]<0){
					if(-(mat->data[j][i])>(mat->data[i][i])){
						max=j;
					}
				}else{
					if((mat->data[j][i])>(mat->data[i][i])){
						max=j;
					}
				}
			}
		}
		if(max!=i){
			for(int j=i;j<mat->r;j++){
				temp=mat->data[max][j];
				mat->data[max][j]=mat->data[i][j];
				mat->data[i][j]=temp;
			}
			b->data[max][0]=temp;
			b->data[max][0]=b->data[i][0];
			b->data[i][0]=temp;
		}
		for(int j=i+1;j<mat->c;j++){

			f=mat->data[j][i]/mat->data[i][i];
			for(int k=i;k<mat->r;k++){
				mat->data[j][k]=mat->data[j][k]-(mat->data[i][k]*f);
			}
			b->data[j][0]=b->data[j][0]-(b->data[i][0]*f);

		}
	}

		return 0;
}

