#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "helper.h"

#define EPSILON 0.000001

int backwardSubstitution(double **m, int n, double x[])
{
	int i,j;
	int type = 0;
	double sum;
	for(i=n-1; i>=0; i--){
		sum = 0;
		for(j=i+1;j<n;j++){
			sum += m[i][j]*x[j];
		}
		if(fabs(m[i][i]) < EPSILON){
			if(fabs(m[i][n]-sum) < EPSILON){
				x[i] = 0;
				type = 0;
			}else{
				return 2;
			}
		}else{
			x[i] = (m[i][j]-sum)/m[i][i];
		}
	}
	return type;
}

void gaussianJordanElimination(double **m, int n)
{
	int i, j, k;
	for(i=0;i<n;i++){
		if(m[i][i] == 0){
			j=i+1;
			while(j<n && m[i][j]==0)
				j++;
			if(j<n){
				double aux;
				for(k=0;k<n;k++){
					aux = m[k][i];
					m[k][i] = m[k][j];
					m[k][j] = aux;
				}
			}else{
				for(k=0;k<n;k++)
					m[k][i]=0;
			}
		}
		if(m[i][i]!=0){
			for(j=0;j<n;j++){
				if(j!=i){
					double mult = -m[j][i]/m[i][i];
					m[j][i] = 0;
					for(k=i+1;k<=n;k++){
						m[j][k] += mult*m[i][k];
					}
				}
			}
		}
	}
}

int main(void)
{
	int n;
	double **m,*x;

	printf("Quantidade de variaveis: ");
	scanf("%d", &n);

	m = allocateMatrix(n, n+1);
	x = malloc(sizeof(double) * n);
	if(m==NULL || x==NULL){
		printf("Deu pau!\nFalta de Memoria\n");
		return 1;
	}

	readMatrix(m,n,n+1);
	printMatrix(m,n,n+1);

	gaussianJordanElimination(m,n);
	printf("\nMatriz diagonalizada\n");
	printMatrix(m,n,n+1);

	int type = backwardSubstitution(m,n,x);
	if(type==2){
		printf("\nSL IMCOMPATIVEL\n");
	}else{
		printf("\nSL %sDETERMINADO\n", type==1 ? "IN":"");
		for(int i=0;i<n;i++){
			printf("x[%d]=%10.3lf\n", i+1, x[i]);
		}
	}

	return 0;
}
